#ifndef EE200_PHYSICS_OBJECT_H
#define EE200_PHYSICS_OBJECT_H

enum GRAPHICS_TYPE {
    RECT,    //0
    CIRCLE,  //1
    IMAGE    //2
};

typedef struct PhysicsObject {
    void* graphics_object;
    int type;

    bool is_collidable;

    double x, y;
    double vx, vy;
    double ax, ay;

    double rot;
} PhysicsObject;

PhysicsObject* create_object(void* graphics_object, int type, bool is_collidable, double x, double y, double vx, double vy, double ax, double ay);

void update_object_graphics(PhysicsObject *object);
void update_object(PhysicsObject *object, double delta_time);

void set_x(PhysicsObject *object, double x);
void set_y(PhysicsObject *object, double y);
void set_pos(PhysicsObject *object, double x, double y);

void set_velocity_x(PhysicsObject *object, double vx);
void set_velocity_y(PhysicsObject *object, double vy);
void set_velocity(PhysicsObject *object, double vx, double vy);

void set_acceleration_x(PhysicsObject *object, double ax);
void set_acceleration_y(PhysicsObject *object, double ay);
void set_acceleration(PhysicsObject *object, double ax, double ay);

void set_rotation(PhysicsObject *object, double rot);

void collision_detection(PhysicsObject *object, PhysicsObject **other_objects);

#endif //EE200_PHYSICS_OBJECT_H
