#ifndef FORGO_H
#define FORGO_H
#include "model.h"
#include "texture.h"
#include "utils.h"
#include "camera.h"
#include <stdbool.h>

typedef struct Forgo
{
    GLuint texture_idfej;
    Model fej;
    Model lab;
    vec3 pos;
    vec3 rotseb;
    vec3 rot;
    int angle;

} Forgo;

void init_forgo(Forgo* forgo);

void rotating(Forgo* forgo, double time);

#endif /*FORGO_H*/
