#include "scene.h"

#include "model.h"
#include <draw.h>


void init_scene(Scene* scene)
{
    load_model(&(scene->ut), "modelek/untitled.obj");
    scene->texture_id1 = load_texture("textures/untitled/sf_road5.png");

    load_model(&(scene->epulet), "modelek/epulet.obj");
    scene->texture_id3 = load_texture("textures/untitled/dirt.png");

    load_model(&(scene->talaj), "modelek/talaj.obj");
    scene->texture_id4 = load_texture("textures/untitled/fu.png");

    load_model(&(scene->lampa), "modelek/lampa.obj");

    load_model(&(scene->cube), "modelek/cube.obj");
    scene->texture_id5 = load_texture("textures/untitled/cubetext.jpg");
    
    load_model(&(scene->torony), "modelek/torony.obj");
    scene->texture_id7 = load_texture("textures/untitled/background.png");


    load_model(&(scene->piramis), "modelek/piramis.obj");
    scene->texture_id6 = load_texture("textures/untitled/uveg.png");



   scene->segitsegt = load_texture("textures/untitled/help.png");
    
  

   init_verda(&(scene->verda));
   init_car(&(scene->car));
   init_kocsi(&(scene->kocsi));
   init_forgo(&(scene->forgo));

  

  
   

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.0;
    scene->lighting_level = 0.0;

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    set_lighting(scene->lighting_level);
    scene->helptext = false;

    scene->fogColor[0] = 0.5f;
    scene->fogColor[1] = 0.5f;
    scene->fogColor[2] = 0.5f;
    scene->fogColor[3] = 1.0f;
    glEnable(GL_FOG);
    glFogf(GL_FOG_DENSITY, 0.15f);
    glFogfv(GL_FOG_COLOR, scene->fogColor);
   

  

}

void set_lighting(float lighting_level)
{
    float ambient_light[] = {lighting_level, lighting_level, lighting_level, 1.0f};
    float diffuse_light[] = {lighting_level, lighting_level, lighting_level, 1.0f};
    float specular_light[] = {lighting_level, lighting_level, lighting_level, 1.0f};
    float position[] = {1.5f, -2.400296f, 3.0f, 0.2f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void segitseg(GLuint tid)
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, tid);
    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-2.0, 2.0, -3);
    glTexCoord2f(1, 0);
    glVertex3f(2.0, 2.0, -3);
    glTexCoord2f(1, 1);
    glVertex3f(2.0, -2.0, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-2.0, -2.0, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}


void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double time)
{



}

void render_scene(const Scene* scene)
{
    GLfloat light_position[] = { -2.0,2.29,0.5, 2.0f };
    GLfloat light_direction[] = { 0.0f, 0.0f, -1.0f };
    GLfloat light_color[] = { 1.0f, 1.0f, 1.0f, 2.0f };
    GLfloat spot_cutoff = 45.0f;
    GLfloat spot_exponent = 2.0f;

    

    set_material(&(scene->material));


    glPushMatrix();

    glTranslatef(scene->verda.pos.x, scene->verda.pos.y, scene->verda.pos.z);
    glScalef(0.02,0.02,0.02);
    glRotatef(scene->verda.angle,scene->verda.rot.x,scene->verda.rot.y,scene->verda.rot.z);
    glBindTexture(GL_TEXTURE_2D, scene->verda.texture_verda);
    draw_model(&(scene->verda.model));

     glPopMatrix();
   


    glPushMatrix();

    glTranslatef(0.0,0.0,0.0);
    glScalef(0.07,0.07,0.07);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id1);
    draw_model(&(scene->ut));

     glPopMatrix();

    glPushMatrix();

    glTranslatef(scene->kocsi.pos.x, scene->kocsi.pos.y, scene->kocsi.pos.z);
    glScalef(0.15,0.15,0.15);
    glRotatef(scene->kocsi.angle,scene->kocsi.rot.x,scene->kocsi.rot.y,scene->kocsi.rot.z);
    glBindTexture(GL_TEXTURE_2D, scene->kocsi.texture_kocsi);
    draw_model(&(scene->kocsi.model));

     glPopMatrix();

   

    glPushMatrix();

    glTranslatef(-2.06,1.61,0.0);
    glScalef(0.07,0.07,0.07);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id3);
    draw_model(&(scene->epulet));

     glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0,0.0,-0.03);
    glScalef(0.07,0.07,0.07);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id4);
    draw_model(&(scene->talaj));
    

     glPopMatrix();



    


    glPushMatrix();

    glTranslatef(-2.0,2.2,0.24);
    glScalef(0.07,0.07,0.07);
    draw_model(&(scene->lampa));

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-2.0,2.29,0.5);
    glScalef(0.02,0.02,0.02);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id5);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
    draw_model(&(scene->cube));

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    glScalef(0.02,0.02,0.02);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id6);
    draw_model(&(scene->piramis));

    glPopMatrix();


	
    glPushMatrix();

    glTranslatef(0,0,0.7);
    glScalef(0.02,0.02,0.02);
    glRotatef(45.0 ,0,0,1);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id7);
    draw_model(&(scene->torony));

    glPopMatrix();


  

   glPushMatrix();
    
    glTranslatef(scene->forgo.pos.x,scene->forgo.pos.y,scene->forgo.pos.z);
    glScalef(0.1,0.1,0.1);
    glRotatef(-90, 1, 0, 0);
    glRotatef(scene->forgo.angle ,scene->forgo.rot.x,scene->forgo.rot.y,scene->forgo.rot.z);
    glBindTexture(GL_TEXTURE_2D, scene->forgo.texture_idfej);
    draw_model(&(scene->forgo.fej));

    glPopMatrix();

    


    glPushMatrix();

    glTranslatef(-2.4,4,0);
    glScalef(0.02,0.02,0.02);
    glRotatef(90, 0, 0, 1);
    draw_model(&(scene->forgo.lab));

    glPopMatrix();

    
    glPushMatrix();

    glTranslatef(scene->car.pos.x, scene->car.pos.y, scene->car.pos.z);
    glScalef(0.07,0.07,0.07);
    glRotatef(scene->car.angle,scene->car.rot.x,scene->car.rot.y,scene->car.rot.z);
    glBindTexture(GL_TEXTURE_2D, scene->car.texture_id);
    draw_model(&(scene->car.model));

    glPopMatrix();
    


    if(scene->helptext == true)
    {
    segitseg(scene->segitsegt);
    }    

    draw_origin();





}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
