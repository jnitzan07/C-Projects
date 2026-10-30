#include "physics_object.h"
#include "renderer.h"

PhysicsObject* create_object(void* graphics_object, int type, bool is_collidable, double x, double y, double vx, double vy, double ax, double ay) {
    PhysicsObject *object = malloc(sizeof(PhysicsObject));
    object -> is_collidable = is_collidable;

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

    object -> vx += ax;
    object -> vy += ay;
}

void collision_detection(PhysicsObject *object, PhysicsObject **other_objects) {
    //if collidable
        //for object in objects
            //switch type
                //case rect
                    //check the type of object
                //case circle
                    //check the type of object
                //case image
                    //use masks
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