#include "scene.h"

#include "model.h"
#include <draw.h>


void init_scene(Scene* scene)
{
    load_model(&(scene->ut), "untitled.obj");
    scene->texture_id1 = load_texture("textures/untitled/textt.png");

    init_car(&(scene->car));
 
    load_model(&(scene->epulet), "epulet.obj");
    scene->texture_id3 = load_texture("textures/untitled/fu.png");

    load_model(&(scene->talaj), "talaj.obj");
    scene->texture_id4 = load_texture("textures/untitled/sf_road5.png");
    
    load_model(&(scene->lampa), "lampa.obj");


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
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 50.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
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

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));

    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    glScalef(0.07,0.07,0.07);
    draw_model(&(scene->ut));
     glBindTexture(GL_TEXTURE_2D, scene->texture_id1);
     glPopMatrix();

    glPushMatrix();
    glTranslatef(scene->car.pos.x, scene->car.pos.y, scene->car.pos.z);
    glScalef(0.07,0.07,0.07);
    glRotatef(scene->car.angle,scene->car.rot.x,scene->car.rot.y,scene->car.rot.z);
    draw_model(&(scene->car.model));
    glBindTexture(GL_TEXTURE_2D, scene->car.texture_id);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.06,1.61,0.0);
    glScalef(0.07,0.07,0.07);
    draw_model(&(scene->epulet));
     glBindTexture(GL_TEXTURE_2D, scene->texture_id3);
     glPopMatrix();

glPushMatrix();
    glTranslatef(0.0,0.0,-0.03);
    glScalef(0.07,0.07,0.07);
    draw_model(&(scene->talaj));
     glBindTexture(GL_TEXTURE_2D, scene->texture_id4);
     glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0,2.2,0.24);
    glScalef(0.07,0.07,0.07);
    draw_model(&(scene->lampa));
    glPopMatrix();


    set_lighting();

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
