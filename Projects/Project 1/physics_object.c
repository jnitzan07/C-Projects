#include "physics_object.h"

#include <tgmath.h>

#include "renderer.h"

PhysicsObject* create_object(void* graphics_object, int type, bool is_collidable, bool is_movable, double x, double y, double vx, double vy, double ax, double ay) {
    PhysicsObject *object = malloc(sizeof(PhysicsObject));
    object -> is_collidable = is_collidable;
    object -> is_movable = is_movable;

    object -> x = x;
    object -> y = y;
    object -> vx = vx;
    object -> vy = vy;
    object -> ax = ax;
    object -> ay = ay;

    object -> type = type;
    object -> graphics_object = graphics_object;

    return (object);
}

void update_object_graphics(PhysicsObject *object) {
    switch (object -> type) {
        case RECT:
            ((Rect*) object -> graphics_object) -> x = (int) object -> x;
            ((Rect*) object -> graphics_object) -> y = (int) object -> y;
            break;
        case CIRCLE:
            ((Circle*) object -> graphics_object) -> cx = (int) object -> x;
            ((Circle*) object -> graphics_object) -> cy = (int) object -> y;
            break;
        case IMAGE:
            ((struct RenderedImage*) object -> graphics_object) -> x = (int) object -> x;
            ((struct RenderedImage*) object -> graphics_object) -> y = (int) object -> y;
            break;
    }
}

void update_object(PhysicsObject *object, double delta_time) {
    object -> x += object -> vx;
    object -> y += object -> vy;

    double ax = object -> ax;
    double ay = object -> ay;

    object -> vx += delta_time * ax;
    object -> vy += delta_time * ay;
}

bool check_collision_rects(PhysicsObject obj1, PhysicsObject obj2) {
    if (obj1.type != RECT || obj2.type != RECT) return 0;
    Rect *g1 = obj1.graphics_object;
    Rect *g2 = obj2.graphics_object;
    return (CheckCollisionRecs((Rectangle) {g1 -> x, g1 -> y, g1 -> width, g1 -> height}, (Rectangle) {g2 -> x, g2 -> y, g2 -> width, g2 -> height}));
}

bool check_collision_rect_circle(PhysicsObject obj1, PhysicsObject obj2) {
    if (obj1.type != RECT || obj2.type != CIRCLE) return 0;
    Rect *g1 = obj1.graphics_object;
    Circle *c1 = obj2.graphics_object;
    bool collided = CheckCollisionCircleRec((Vector2) {c1 -> cx, c1 -> cy}, c1 -> radius, (Rectangle) {g1 -> x, g1 -> y, g1 -> width, g1 -> height});
    return (collided);
}

bool check_collision_rect_image(PhysicsObject obj1, PhysicsObject obj2) {
    if (obj1.type != RECT || obj2.type != IMAGE) return 0;
    return 0;
}

bool check_collision_circles(PhysicsObject obj1, PhysicsObject obj2) {
    if (obj1.type != CIRCLE || obj2.type != CIRCLE) return 0;
    Circle *c1 = obj1.graphics_object;
    Circle *c2 = obj2.graphics_object;
    return (CheckCollisionCircles((Vector2) {c1 -> cx, c1 -> cy}, c1 -> radius, (Vector2) {c2 -> cx, c2 -> cy}, c2 -> radius));
}

bool check_collision_circle_image(PhysicsObject obj1, PhysicsObject obj2) {
    if (obj1.type != CIRCLE || obj2.type != IMAGE) return 0;
    return 0;
}

bool check_collision_images(PhysicsObject obj1, PhysicsObject obj2) {
    if (obj1.type != IMAGE || obj2.type != IMAGE) return 0;
    return 0;
}

void collision_detection(PhysicsObject *object, int object_index, PhysicsObject **other_objects, int objects_length, int start_index) {
    bool collision = false;
    if (!object -> is_collidable) {return;}
    void* graphics_object = object -> graphics_object;
    for (int i = start_index - 1; i < objects_length; i++) {
            if (i != object_index && object -> is_movable && other_objects[i] -> is_collidable) {
                collision = false;
                switch (object -> type) {
                    case RECT:
                        collision = check_collision_rects(*object, *other_objects[i]);
                        if (collision) break;
                        collision = check_collision_rect_circle(*object, *other_objects[i]);
                        if (collision) break;
                        collision = check_collision_rect_image(*object, *other_objects[i]);
                        break;
                    case CIRCLE:
                        collision = check_collision_rect_circle(*other_objects[i], *object);
                        if (collision) break;
                        collision = check_collision_circles(*object, *other_objects[i]);
                        if (collision) break;
                        collision = check_collision_circle_image(*object, *other_objects[i]);
                        break;
                    case IMAGE:
                        collision = check_collision_rect_image(*other_objects[i], *object);
                        if (collision) break;
                        collision = check_collision_circle_image(*other_objects[i], *object);
                        if (collision) break;
                        collision = check_collision_images(*object, *other_objects[i]);
                        break;
                }
                if (collision) {
                    object -> x -= object -> vx;
                    object -> y -= object -> vy;

                    object -> vx *= -0.7;
                    object -> vy *= -0.7;
                }
            }
    }

}

void set_x(PhysicsObject *object, double x) {
    object -> x = x;
}

void set_y(PhysicsObject *object, double y) {
    object -> y = y;
}

void set_pos(PhysicsObject *object, double x, double y) {
    set_x(object, x);
    set_y(object, y);
}

void set_velocity_x(PhysicsObject *object, double vx) {
    object -> vx = vx;
}

void set_velocity_y(PhysicsObject *object, double vy) {
    object -> vy = vy;
}

void set_velocity(PhysicsObject *object, double vx, double vy) {
    set_velocity_x(object, vx);
    set_velocity_y(object, vy);
}

void set_acceleration_x(PhysicsObject *object, double ax) {
    object -> ax = ax;
}

void set_acceleration_y(PhysicsObject *object, double ay) {
    object -> ay = ay;
}

void set_acceleration(PhysicsObject *object, double ax, double ay) {
    set_acceleration_x(object, ax);
    set_acceleration_y(object, ay);
}

void set_rotation(PhysicsObject *object, double rot) {
    object -> rot = rot;
}