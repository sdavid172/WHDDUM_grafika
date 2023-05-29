#ifndef VERDA_H
#define VERDA_H
#include "model.h"
#include "texture.h"
#include "utils.h"
#include "camera.h"
#include <stdbool.h>

typedef struct Verda
{
    GLuint texture_verda;
    Model model;
    vec3 pos;
    vec3 speed;
    vec3 rot;
    float angle;
    float rot_speed;

} Verda;

void init_verda(Verda* verda);
void verda_kezdo(Verda* verda);


void set_verda_roty(Verda* verda, double rot);

void set_verda_rotx(Verda* verda, double rot);

void set_verda_rotz(Verda* verda, double rot);

void set_verda_angle(Verda* verda, double angle);

void set_verda_speedy(Verda* verda, double speed);


void set_verda_speedx(Verda* verda, double speed);


void set_verda_speedz(Verda* verda, double speed);



void move_verda(Verda* verda, double time);

#endif /*VERDA_H*/
