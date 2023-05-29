#include "forgo.h"

void init_forgo(Forgo *forgo)
{
    load_model(&(forgo->fej), "modelek/head.obj");
    forgo->texture_idfej = load_texture("textures/untitled/textt.png");
   

    load_model(&(forgo->lab), "modelek/lab.obj");
    

    forgo->angle = 0.0;


    forgo->pos.x = -2.4; 
    forgo->pos.y = 4.0;
    forgo->pos.z = 0.26;

    forgo->rotseb.x = 0.0;
    forgo->rotseb.y = 0.0;
    forgo->rotseb.z = 1800.0;

    forgo->rot.x = 0.0;
    forgo->rot.y = 0.0;
    forgo->rot.z = 1.0;
   
    



}


void rotating(Forgo *forgo, double time)
{
if(forgo->angle <= 360.0)
   {
   forgo->angle += forgo->rotseb.z * time;
   } 
   else
   {
   forgo->angle -= 360.0;
   
   }    



}

