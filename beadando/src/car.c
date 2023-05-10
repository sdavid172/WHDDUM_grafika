#include "car.h"

void init_car(Car *car)
{
    load_model(&(car->model), "pd.obj");
    car->texture_id = load_texture("textures/untitled/dirt.png");


    car->pos.x = -2.4; //-2.4
    car->pos.y = 2.5;
    car->pos.z = 0.05;

    car->speed.x = 0.0;
    car->speed.y = 0.0;
    car->speed.z = 0.0;
   
    car->rot.x = 0.0;
    car->rot.y = 0.0;
    car->rot.z = 0.0;
    car->angle = 0.0;

  
}

void car_kezdo(Car *car)
{
 car->pos.x = -2.7; 
    car->pos.y = 2.5;
    car->pos.z = 0.05;

    car->speed.x = 1.0;
    car->speed.y = 0.0;
    car->speed.z = 0.0;
   
    car->rot.x = 0.0;
    car->rot.y = 0.0;
    car->rot.z = 0.0;
    car->angle = 0.0;
}


void set_car_pos(Car *car, vec3 newPos)
{
    car->pos.x += newPos.x;
    car->pos.y += newPos.y;
    car->pos.z += newPos.z;
}

void set_car_roty (Car *car, double rot)
{
car->rot.y = rot;
}

void set_car_rotx (Car *car, double rot)
{
car->rot.x = rot;
}
void set_car_rotz (Car *car, double rot)
{
car->rot.z = rot;
}

void set_car_angle (Car *car, double angle)
{
car->angle = angle;
}


void set_car_speedy(Car *car, double speed)
{
    car->speed.y = -speed;
}

void set_car_speedx(Car *car, double speed)
{
    car->speed.x = speed;
}

void set_car_speedz(Car *car, double speed)
{
    car->speed.z = speed;
}

void move_car(Car *car, double time)
{
    car->pos.x += car->speed.x * time;
    car->pos.y += car->speed.y * time;
    car->pos.z += car->speed.z * time;

}