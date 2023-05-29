#include "kocsi.h"

void init_kocsi(Kocsi *kocsi)
{
    load_model(&(kocsi->model), "modelek/kocsik.obj");
    kocsi->texture_kocsi = load_texture("textures/untitled/car.png");

    


    kocsi->pos.x = -1.0; 
    kocsi->pos.y = 2.5;
    kocsi->pos.z = 0.07;

    kocsi->speed.x = 0.0;
    kocsi->speed.y = 0.0;
    kocsi->speed.z = 0.0;

    kocsi->rot.x = 0.0;
    kocsi->rot.y = 0.0;
    kocsi->rot.z = 1.0;
    kocsi->angle = 270.0;
    kocsi->rot_speed = 0.0;


}

void kocsi_kezdo(Kocsi *kocsi)
{
    kocsi->pos.x = -1.0; 
    kocsi->pos.y = 2.5;
    kocsi->pos.z = 0.07;

    kocsi->speed.x = 0.0;
    kocsi->speed.y = 0.0;
    kocsi->speed.z = 0.0;

    kocsi->rot.x = 0.0;
    kocsi->rot.y = 0.0;
    kocsi->rot.z = 1.0;
    kocsi->angle = 270.0;
    kocsi->rot_speed = 0.0;
}



void set_kocsi_roty (Kocsi *kocsi, double rot)
{
kocsi->rot.y = rot;
}

void set_kocsi_rotx (Kocsi *kocsi, double rot)
{
kocsi->rot.x = rot;
}
void set_kocsi_rotz (Kocsi *kocsi, double rot)
{
kocsi->rot.z = rot;
}

void set_kocsi_angle (Kocsi *kocsi, double angle)
{
kocsi->angle = angle;
}


void set_kocsi_speedy(Kocsi *kocsi, double speed)
{
    kocsi->speed.y = -speed;
}

void set_kocsi_speedx(Kocsi *kocsi, double speed)
{
    kocsi->speed.x = speed;
}

void set_kocsi_speedz(Kocsi *kocsi, double speed)
{
    kocsi->speed.z = speed;
}

void move_kocsi(Kocsi *kocsi, double time)
{
    kocsi->pos.x += kocsi->speed.x * time;
    kocsi->pos.y += kocsi->speed.y * time;
    kocsi->pos.z += kocsi->speed.z * time;

}
