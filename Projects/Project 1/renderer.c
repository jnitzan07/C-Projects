#include "renderer.h"
#include <raylib.h>
#include <stdlib.h>

#define MAX_OBJ_PER_TYPE 1000

struct ObjectList objects;

void init_objects() {
    objects.rect_count = 0;
    objects.circle_count = 0;
    objects.image_count = 0;

    objects.rects = malloc(sizeof(struct Rect) * MAX_OBJ_PER_TYPE);
    objects.circles = malloc(sizeof(struct Circle) * MAX_OBJ_PER_TYPE);
    objects.images = malloc(sizeof(struct RenderedImage) * MAX_OBJ_PER_TYPE);

    objects.textures = create_table();
}

Texture2D* add_texture(const char *path) {
    Texture2D *existing = get_value(objects.textures, path);
    if (existing) return existing;
    Texture2D *tex = malloc(sizeof(Texture2D));
    *tex = LoadTexture(path);
    insert(objects.textures, path, tex);
    return tex;
}

void free_textures() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = objects.textures -> buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current -> next;
            UnloadTexture(*(Texture2D*) temp -> value);
            free(temp -> value);
            free(temp -> key);
            free(temp);
        }
    }
    free(objects.textures);
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

    objects.rects[objects.rect_count] = new_rect;
    objects.rect_count++;
}

void add_circle(int cx, int cy, double radius, Color color) {
    struct Circle new_circle;
    new_circle.cx = cx;
    new_circle.cy = cy;
    new_circle.radius = radius;
    new_circle.color = color;

    objects.circles[objects.circle_count] = new_circle;
    objects.circle_count++;
}

void add_image(Texture2D *texture, int x, int y, double scale, Color tint) {
    struct RenderedImage image = {texture, tint, x, y, scale};
    objects.images[objects.image_count] = image;
    objects.image_count++;
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
    for (int i = 0; i < objects.image_count; i++) {
        struct RenderedImage *image = &objects.images[i];
        DrawTextureEx(*image -> texture, (Vector2){image -> x, image -> y}, 0.0f, image -> scale, image -> tint);
    }
}