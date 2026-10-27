#include "renderer.h"
#include <raylib.h>
#include <stdlib.h>

#define MAX_OBJ_PER_TYPE 1000

struct ObjectList objects;

void init_objects() {
    objects.rects = malloc(sizeof(struct Rect) * MAX_OBJ_PER_TYPE);
    objects.circles = malloc(sizeof(struct Circle) * MAX_OBJ_PER_TYPE);
    objects.images = malloc(sizeof(struct LoadedImage) * MAX_OBJ_PER_TYPE);
}

void load_images() {

}

void add_rect(int x, int y, int width, int height, Color color) {
    struct Rect new_rect;
    new_rect.x = x;
    new_rect.y = y;
    new_rect.width = width;
    new_rect.height = height;
    new_rect.color = color;

    objects.rect_count++;
    objects.rects[objects.rect_count] = new_rect;
}

void add_circle(int cx, int cy, double radius, Color color) {
    struct Circle new_circle;
    new_circle.cx = cx;
    new_circle.cy = cy;
    new_circle.radius = radius;
    new_circle.color = color;

    objects.circle_count++;
    objects.circles[objects.circle_count] = new_circle;
}

void render() {
    ClearBackground(GRAY);
    //rendering all rects
    for (int i = 0; i < objects.rect_count; i++) {
        DrawRectangle(objects.rects[i].x, objects.rects[i].y, objects.rects[i].width, objects.rects[i].height, objects.rects[i].color);
    }
    //rendering all circles
    for (int i = 0; i < objects.circle_count; i++) {
        DrawCircle(objects.circles[i].cx, objects.circles[i].cy, objects.circles[i].radius, objects.circles[i].color);
    }
    //rendering all images (loaded textures to be specific)
    //todo later
}