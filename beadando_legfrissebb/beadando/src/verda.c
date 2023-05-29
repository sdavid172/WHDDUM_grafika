#include "verda.h"

void init_verda(Verda *verda)
{
    load_model(&(verda->model), "modelek/verda.obj");
    verda->texture_verda = load_texture("textures/untitled/body.png");

    


    verda->pos.x = 0.8; 
    verda->pos.y = 2.5;
    verda->pos.z = 0.02;

    verda->speed.x = 0.0;
    verda->speed.y = 0.0;
    verda->speed.z = 0.0;

    verda->rot.x = 0.0;
    verda->rot.y = 0.0;
    verda->rot.z = 1.0;
    verda->angle = 270.0;
    verda->rot_speed = 0.0;


}

void verda_kezdo(Verda *verda)
{
    verda->pos.x = 0.8; 
    verda->pos.y = 2.5;
    verda->pos.z = 0.02;

    verda->speed.x = 0.0;
    verda->speed.y = 0.0;
    verda->speed.z = 0.0;

    verda->rot.x = 0.0;
    verda->rot.y = 0.0;
    verda->rot.z = 1.0;
    verda->angle = 270.0;
    verda->rot_speed = 0.0;
}



void set_verda_roty (Verda *verda, double rot)
{
verda->rot.y = rot;
}

void set_verda_rotx (Verda *verda, double rot)
{
verda->rot.x = rot;
}
void set_verda_rotz (Verda *verda, double rot)
{
verda->rot.z = rot;
}

void set_verda_angle (Verda *verda, double angle)
{
verda->angle = angle;
}


void set_verda_speedy(Verda *verda, double speed)
{
    verda->speed.y = -speed;
}

void set_verda_speedx(Verda *verda, double speed)
{
    verda->speed.x = speed;
}

void set_verda_speedz(Verda *verda, double speed)
{
    verda->speed.z = speed;
}

void move_verda(Verda *verda, double time)
{
    verda->pos.x += verda->speed.x * time;
    verda->pos.y += verda->speed.y * time;
    verda->pos.z += verda->speed.z * time;

}
