#include "app.h"

#include <SDL2/SDL_image.h>

void init_app(App* app, int width, int height)
{
    int error_code;
    int inited_loaders;

    app->is_running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    app->window = SDL_CreateWindow(
        "Cube!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL);
    if (app->window == NULL) {
        printf("[ERROR] Unable to create the application window!\n");
        return;
    }

    inited_loaders = IMG_Init(IMG_INIT_PNG);
    if (inited_loaders == 0) {
        printf("[ERROR] IMG initialization error: %s\n", IMG_GetError());
        return;
    }

    app->gl_context = SDL_GL_CreateContext(app->window);
    if (app->gl_context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    init_opengl();
    reshape(width, height);

    init_camera(&(app->camera));
    init_scene(&(app->scene));

    app->is_running = true;
    app->ok = false;
 
   
}




void init_opengl()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.1, 0.1, 0.1, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
        -.08, .08,
        -.06, .06,
        .1, 200
    );
}

void handle_app_events(App* app)
{
    SDL_Event event;
    static bool is_mouse_down = false;
    static int mouse_x = 0;
    static int mouse_y = 0;
    int x;
    int y;

    


    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                app->is_running = false;
                break;
            case SDL_SCANCODE_W:
                
                set_camera_speed(&(app->camera), 1);
                




                break;
            case SDL_SCANCODE_S:
              
                set_camera_speed(&(app->camera), -1);
               
                break;
                case SDL_SCANCODE_KP_PLUS:
                if(app->scene.lighting_level <= 1)
                {
                app->scene.lighting_level += 0.2f;
                }
                set_lighting(app->scene.lighting_level);
                break;
            case SDL_SCANCODE_KP_MINUS:
                if(app->scene.lighting_level >= -0.2f)
                {
                app->scene.lighting_level -= 0.2f;
                }
                set_lighting(app->scene.lighting_level);
                break;
            case SDL_SCANCODE_P:
             if(app->ok == false)
             {
             set_car_speedx(&(app->scene.car), 1);
	     set_kocsi_speedx(&(app->scene.kocsi), 1);
  	     set_verda_speedx(&(app->scene.verda), 1);
             app->ok = true;
             }
             break;
            case SDL_SCANCODE_A:
                set_camera_side_speed(&(app->camera), 1);
                break;
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), -1);
                break;
             case SDL_SCANCODE_F1:
               
                if (app->scene.helptext)
                {
                    app->scene.helptext = false;
                  
                }
                else
                {
                    app->scene.helptext = true;
                }
             
                break;
             case SDL_SCANCODE_B:
                app->ok = false;
                car_kezdo(&(app->scene.car));
 		kocsi_kezdo(&(app->scene.kocsi));
                verda_kezdo(&(app->scene.verda));
                
	        break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_W:
     
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), 0);
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), 0);
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            is_mouse_down = true;
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            if (is_mouse_down) {
                rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
            }
            mouse_x = x;
            mouse_y = y;
            break;
        case SDL_MOUSEBUTTONUP:
            is_mouse_down = false;
            break;
        case SDL_QUIT:
            app->is_running = false;
            break;
        default:
            break;
        }
    }
}

void update_app(App* app)
{
    double current_time;
    double elapsed_time;
    

    current_time = (double)SDL_GetTicks() / 1000;
    elapsed_time = current_time - app->uptime;
    app->uptime = current_time;
    update_scene(&(app->scene),elapsed_time);
    update_camera(&(app->camera), elapsed_time);
   
 
     
   
    
   

   
 
    if(app->scene.car.pos.x >= 2.88 && app->scene.car.pos.y >= 1.8) 
    {

    
        if (app->scene.car.angle <= 180)
        {

        set_car_speedx(&(app->scene.car), 0);
        set_car_speedy(&(app->scene.car), 1);



        app->scene.car.rot_speed = 200.0;
        app->scene.car.angle -= app->scene.car.rot_speed * elapsed_time;
        set_car_rotz(&(app->scene.car),1.0);
        set_car_angle(&(app->scene.car),app->scene.car.angle);

        }
          app->scene.car.rot_speed = 0.0;



    }

    if(app->scene.car.pos.x >= 1.88 && app->scene.car.pos.y < -2.82)
    {


        if (app->scene.car.angle <= 90)
        {

        set_car_speedx(&(app->scene.car), -1);
        set_car_speedy(&(app->scene.car), 0);



        app->scene.car.rot_speed = 100.0;
        app->scene.car.angle -= app->scene.car.rot_speed * elapsed_time;
        set_car_rotz(&(app->scene.car),1.0);
        set_car_angle(&(app->scene.car),app->scene.car.angle);

        }
          app->scene.car.rot_speed = 0.0;


    }

    if(app->scene.car.pos.x < -2.89 && app->scene.car.pos.y < -1.9)
    {




        if (app->scene.car.angle <= 210)
        {

        set_car_speedx(&(app->scene.car), 0);
        set_car_speedy(&(app->scene.car), -1);

        app->scene.car.rot_speed = 100.0;
        app->scene.car.angle -= app->scene.car.rot_speed * elapsed_time;
        set_car_rotz(&(app->scene.car),1.0);
        set_car_angle(&(app->scene.car),app->scene.car.angle);

        }
          app->scene.car.rot_speed = 0.0;


    }

    if(app->scene.car.pos.y > 2.5 && app->scene.car.pos.x < -2.8)
    {
        if (app->scene.car.angle <= 45)
        {




        set_car_speedx(&(app->scene.car), 1);
        set_car_speedy(&(app->scene.car), 0);

         app->scene.car.rot_speed = 200.0;
         app->scene.car.angle -= app->scene.car.rot_speed * elapsed_time;
         set_car_rotz(&(app->scene.car),1.0);
         set_car_angle(&(app->scene.car),app->scene.car.angle);

        }
          app->scene.car.rot_speed = 0.0;
          set_car_angle(&(app->scene.car),0);
          





    }


     if(app->scene.kocsi.pos.x >= 2.88 && app->scene.kocsi.pos.y >= 1.8) 
    {

    
        if (app->scene.kocsi.angle <= 450) 
        {

        set_kocsi_speedx(&(app->scene.kocsi), 0);
        set_kocsi_speedy(&(app->scene.kocsi), 1);



        app->scene.kocsi.rot_speed = 200.0;
        app->scene.kocsi.angle -= app->scene.kocsi.rot_speed * elapsed_time;
        set_kocsi_rotz(&(app->scene.kocsi),1.0);
        set_kocsi_angle(&(app->scene.kocsi),app->scene.kocsi.angle);

        }
          app->scene.kocsi.rot_speed = 0.0;



    }

    if(app->scene.kocsi.pos.x >= 1.88 && app->scene.kocsi.pos.y < -2.82)
    {


        if (app->scene.kocsi.angle <= 360)
        {

        set_kocsi_speedx(&(app->scene.kocsi), -1);
        set_kocsi_speedy(&(app->scene.kocsi), 0);



        app->scene.kocsi.rot_speed = 100.0;
        app->scene.kocsi.angle -= app->scene.kocsi.rot_speed * elapsed_time;
        set_kocsi_rotz(&(app->scene.kocsi),1.0);
        set_kocsi_angle(&(app->scene.kocsi),app->scene.kocsi.angle);

        }
          app->scene.kocsi.rot_speed = 0.0;


    }

    if(app->scene.kocsi.pos.x < -2.89 && app->scene.kocsi.pos.y < -1.9)
    {




        if (app->scene.kocsi.angle <= 480)
        {

        set_kocsi_speedx(&(app->scene.kocsi), 0);
        set_kocsi_speedy(&(app->scene.kocsi), -1);

        app->scene.kocsi.rot_speed = 100.0;
        app->scene.kocsi.angle -= app->scene.kocsi.rot_speed * elapsed_time;
        set_kocsi_rotz(&(app->scene.kocsi),1.0);
        set_kocsi_angle(&(app->scene.kocsi),app->scene.kocsi.angle);

        }
          app->scene.kocsi.rot_speed = 0.0;


    }

    if(app->scene.kocsi.pos.y > 2.5 && app->scene.kocsi.pos.x < -2.8)
    {
        if (app->scene.kocsi.angle <= 315)
        {




        set_kocsi_speedx(&(app->scene.kocsi), 1);
        set_kocsi_speedy(&(app->scene.kocsi), 0);

         app->scene.kocsi.rot_speed = 200.0;
         app->scene.kocsi.angle -= app->scene.kocsi.rot_speed * elapsed_time;
         set_kocsi_rotz(&(app->scene.kocsi),1.0);
         set_kocsi_angle(&(app->scene.kocsi),app->scene.kocsi.angle);

        }
          app->scene.kocsi.rot_speed = 0.0;
          set_kocsi_angle(&(app->scene.kocsi),270);
          





    }


     if(app->scene.verda.pos.x >= 2.88 && app->scene.verda.pos.y >= 1.8) 
    {

    
        if (app->scene.verda.angle <= 450) 
        {

        set_verda_speedx(&(app->scene.verda), 0);
        set_verda_speedy(&(app->scene.verda), 1);



        app->scene.verda.rot_speed = 200.0;
        app->scene.verda.angle -= app->scene.verda.rot_speed * elapsed_time;
        set_verda_rotz(&(app->scene.verda),1.0);
        set_verda_angle(&(app->scene.verda),app->scene.verda.angle);

        }
          app->scene.verda.rot_speed = 0.0;



    }

    if(app->scene.verda.pos.x >= 1.88 && app->scene.verda.pos.y < -2.82)
    {


        if (app->scene.verda.angle <= 360)
        {

        set_verda_speedx(&(app->scene.verda), -1);
        set_verda_speedy(&(app->scene.verda), 0);



        app->scene.verda.rot_speed = 100.0;
        app->scene.verda.angle -= app->scene.verda.rot_speed * elapsed_time;
        set_verda_rotz(&(app->scene.verda),1.0);
        set_verda_angle(&(app->scene.verda),app->scene.verda.angle);

        }
          app->scene.verda.rot_speed = 0.0;


    }

    if(app->scene.verda.pos.x < -2.89 && app->scene.verda.pos.y < -1.9)
    {




        if (app->scene.verda.angle <= 480)
        {

        set_verda_speedx(&(app->scene.verda), 0);
        set_verda_speedy(&(app->scene.verda), -1);

        app->scene.verda.rot_speed = 100.0;
        app->scene.verda.angle -= app->scene.verda.rot_speed * elapsed_time;
        set_verda_rotz(&(app->scene.verda),1.0);
        set_verda_angle(&(app->scene.verda),app->scene.verda.angle);

        }
          app->scene.verda.rot_speed = 0.0;


    }

    if(app->scene.verda.pos.y > 2.5 && app->scene.verda.pos.x < -2.8)
    {
        if (app->scene.verda.angle <= 315)
        {




        set_verda_speedx(&(app->scene.verda), 1);
        set_verda_speedy(&(app->scene.verda), 0);

         app->scene.verda.rot_speed = 200.0;
         app->scene.verda.angle -= app->scene.verda.rot_speed * elapsed_time;
         set_verda_rotz(&(app->scene.verda),1.0);
         set_verda_angle(&(app->scene.verda),app->scene.verda.angle);

        }
          app->scene.verda.rot_speed = 0.0;
          set_verda_angle(&(app->scene.verda),270);
          





    }



     move_car(&(app->scene.car), elapsed_time);
     move_kocsi(&(app->scene.kocsi), elapsed_time);
     move_verda(&(app->scene.verda), elapsed_time);
     rotating(&(app->scene.forgo), elapsed_time);


    
     


}

void render_app(App* app)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&(app->camera));
    render_scene(&(app->scene));
    glPopMatrix();

    if (app->camera.is_preview_visible) {
        show_texture_preview();
    }

    SDL_GL_SwapWindow(app->window);
}

void destroy_app(App* app)
{
    if (app->gl_context != NULL) {
        SDL_GL_DeleteContext(app->gl_context);
    }

    if (app->window != NULL) {
        SDL_DestroyWindow(app->window);
    }

    SDL_Quit();
}
