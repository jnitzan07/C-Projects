#include <raylib.h>
#include <stdio.h>

#include "renderer.h"
#include "file_manager.h"
#include "hashmap.h"

#define WINDOW_WIDTH 1240
#define WINDOW_HEIGHT 780

void init_graphics(int target_fps) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Physics");
    SetTargetFPS(target_fps);
}

void update() {

}

int main() {

    init_files();

    bool running = true;
    int target_fps = 60;
    float time;
    float delta_time = 1.0f/target_fps;

    //initializes the object arrays and the delta_time setup
    init_objects();
    init_graphics(target_fps);

    time = 0.0f;
    while (running) {
        //updates frame/time counter
        time += GetFrameTime();

        //exit condition
        if (WindowShouldClose()) {
            running = false;
            break;
        }

        //makes sure updates stick to the fps
        while (time >= delta_time) {
            time -= delta_time;
            update();
        }

        //rendering
        BeginDrawing();
        render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
