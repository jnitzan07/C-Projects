#include <raylib.h>

#ifndef EE200_RENDERER_H
#define EE200_RENDERER_H

struct ObjectList {
    struct Rect* rects;
    struct Circle* circles;
    struct LoadedImage* images;
    struct Texture* textures;

    int rect_count;
    int circle_count;
    int image_count;
};

struct LoadedImage {
    Image image;
    Color tint;
    int x, y;
    int width, height;
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

void render();
void add_rect(int x, int y, int width, int height, Color color);
void add_circle(int cx, int cy, double radius, Color color);
void add_image(Image image, int x, int y, double scale, Color tint);
void init_objects();


#endif //EE200_RENDERER_H
