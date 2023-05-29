#ifndef CAR_H
#define CAR_H
#include "model.h"
#include "texture.h"
#include "utils.h"
#include "camera.h"
#include <stdbool.h>

typedef struct Car
{
    GLuint texture_id;
    Model model;
    vec3 pos;
    vec3 speed;
    vec3 rot;
    float angle;
    float rot_speed;

} Car;

void init_car(Car* car);
void car_kezdo(Car* car);


void set_car_roty(Car* car, double rot);

void set_car_rotx(Car* car, double rot);

void set_car_rotz(Car* car, double rot);

void set_car_angle(Car* car, double angle);

void set_car_speedy(Car* car, double speed);


void set_car_speedx(Car* car, double speed);


void set_car_speedz(Car* car, double speed);



void move_car(Car* car, double time);

#endif /*CAR_H*/
