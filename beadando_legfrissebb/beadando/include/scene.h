#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "car.h"
#include "kocsi.h"
#include "forgo.h"
#include "verda.h"
#include "model.h"




typedef struct Scene
{
    Model ut;
    Car car;
    Kocsi kocsi;
    Verda verda;
    Forgo forgo;
    Model cube;
    Model epulet;
    Model torony;
    Model talaj;
    Model lampa;
    Model piramis;
    Material material;
    GLuint texture_id1;
    GLuint texture_id2;
    GLuint texture_id3;
    GLuint texture_id4;
    GLuint texture_id5;
    GLuint texture_id6;
    GLuint texture_id7;
    GLuint texture_idlab;
    float lighting_level;
    GLfloat fogColor[4];
    bool helptext;
    GLuint segitsegt;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(float lighting_level);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
