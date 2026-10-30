#include <raylib.h>
#include <stdio.h>

#include "renderer.h"
#include "file_manager.h"
#include "hashmap.h"
#include "physics_object.h"

#define WINDOW_WIDTH 1240
#define WINDOW_HEIGHT 780


//either a dict or array of objects

void init_graphics(int target_fps) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Physics");
    SetTargetFPS(target_fps);
}

void update(PhysicsObject **objects, double delta_time) {
    for (int i = 0; objects[i] != NULL; i++) {
        update_object(objects[i], delta_time);
        update_object_graphics(objects[i]);
    }
}

int main() {
    init_files();

    bool running = true;
    bool paused = false;

    int target_fps = 60;
    float time;
    float delta_time = 1.0f/target_fps;

    //initializes the object arrays and the delta_time setup
    init_objects();
    init_graphics(target_fps);




    PhysicsObject* objects[1000] = {0};



    Rect *test = add_rect(0, 0, 100, 100, GREEN);
    PhysicsObject* test_obj = create_object(test, RECT, false, 50.0, 50.0, 5, 0, -0.25, 0.0);
    objects[0] = test_obj;

    time = 0.0f;
    while (running) {

        //exit condition
        if (WindowShouldClose()) {
            running = false;
            break;
        }

        //some sort of key detection (will need to check docs for how that works)
        //p to say paused = !paused or something

        //so ideally when we add key detection later we can pause
        //though i guess in the end we may want 2 timers? One for general UI and one for the physics specifically (or a mode that changes based on the operation i suppose)
        if (!paused) {
            //updates frame/time counter
            time += GetFrameTime();

            //makes sure updates stick to the fps
            while (time >= delta_time) {
                time -= delta_time;
                update(objects, delta_time);
            }
        }

        //rendering
        BeginDrawing();
        render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
