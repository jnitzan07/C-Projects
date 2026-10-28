#include <raylib.h>
#include "hashmap.h"


#ifndef EE200_RENDERER_H
#define EE200_RENDERER_H

//keeps all objects we're rendering and the textures for images
struct ObjectList {
    struct Rect* rects;
    struct Circle* circles;
    struct RenderedImage* images;
    HashMap *textures;

    int rect_count;
    int circle_count;
    int image_count;
};

//info and texture for images we can/are rendering
struct RenderedImage {
    Texture2D *texture;
    Color tint;
    int x, y;
    double scale;
};

struct Rect {
    int x, y;
    int width, height;
    Color color;
};

struct Circle {
    int cx, cy;
    float radius;
    Color color;
};

Texture2D* add_texture(const char *path);
void add_rect(int x, int y, int width, int height, Color color);
void add_circle(int cx, int cy, double radius, Color color);

void add_image(Texture2D *texture, int x, int y, double scale, Color tint);

void init_objects();
void render();


#endif //EE200_RENDERER_H
