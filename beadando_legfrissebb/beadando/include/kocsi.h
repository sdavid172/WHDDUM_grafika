#ifndef KOCSI_H
#define KOCSI_H
#include "model.h"
#include "texture.h"
#include "utils.h"
#include "camera.h"
#include <stdbool.h>

typedef struct Kocsi
{
    GLuint texture_kocsi;
    Model model;
    vec3 pos;
    vec3 speed;
    vec3 rot;
    float angle;
    float rot_speed;

} Kocsi;

void init_kocsi(Kocsi* kocsi);
void kocsi_kezdo(Kocsi* kocsi);


void set_kocsi_roty(Kocsi* kocsi, double rot);

void set_kocsi_rotx(Kocsi* kocsi, double rot);

void set_kocsi_rotz(Kocsi* kocsi, double rot);

void set_kocsi_angle(Kocsi* kocsi, double angle);

void set_kocsi_speedy(Kocsi* kocsi, double speed);


void set_kocsi_speedx(Kocsi* kocsi, double speed);


void set_kocsi_speedz(Kocsi* kocsi, double speed);



void move_kocsi(Kocsi* kocsi, double time);

#endif /*KOCSI_H*/
