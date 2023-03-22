#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>


/**
 * Siska Dávid - WHDDUM
 */

struct Line
{
int x0;
int y0;
int x1;
int y1;


};

struct Color
{
    int r;
    int g;
    int b;
};

struct Line line;
struct Color szin;

int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;

 szin.r = 255;
 szin.g = 255;
 szin.b = 255;

  bool need_run;
  SDL_Event event;
  SDL_GLContext gl_context;
  int i;

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Line draw by David Siska (WHDDUM) 2023.",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600,
    SDL_WINDOW_OPENGL);

     SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);


  gl_context = SDL_GL_CreateContext(window);
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);


  int j = 0;

  int k = 0;



  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
      case SDL_QUIT:
        need_run = false;
        break;
        case SDL_MOUSEBUTTONDOWN:



        if( SDL_BUTTON_RIGHT == event.button.button)
        {
            k++;

            if(k == 1)
            {

             SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Color select", "Szin atallitva: zold", window);

             szin.r = 20;
             szin.g = 255;
             szin.b = 28;
            }

            if(k == 2)
            {
             SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Color select", "Szin atallitva: feher", window);

             szin.r = 255;
             szin.g = 255;
             szin.b = 255;
            }
            if(k == 3)
            {
             szin.r = 0;
             szin.g = 38;
             szin.b = 255;
             SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Color select", "Szin atallitva: kek", window);


            }

             if(k == 4)
            {
             szin.r = 255;
             szin.g = 255;
             szin.b = 0;
             SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Color select", "Szin atallitva: citromsarga", window);


            }

             if(k == 5)
            {
             szin.r = 217;
             szin.g = 0;
             szin.b = 255;
             SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Color select", "Szin atallitva: lila", window);


            }

            if(k == 6)
            {
             szin.r = 255;
             szin.g = 0;
             szin.b = 0;
             SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Color select", "Szin atallitva: piros", window);

             k = 0;
            }



        }

        if ( SDL_BUTTON_LEFT == event.button.button )
         {
               int x, y;
               SDL_GetMouseState( &x, &y );


                j++;

                if(j == 1)
                {

                SDL_Log("LOG: Szakasz kezdopontja mentve.");
                line.x0 = x;
                line.y0 = y;


                }

                if(j == 2)
                {
                line.x1 = x;
                line.y1 = y;
                j = 0;
                SDL_Log("LOG: Szakasz vegpontja mentve.");
                SDL_Log("LOG: Szakasz letrehozva. x0: %d y0: %d x1: %d y1: %d",line.x0,line.y0,line.x1,line.y1);



                SDL_SetRenderDrawColor(renderer,szin.r,szin.g,szin.b,SDL_ALPHA_OPAQUE);


                SDL_RenderDrawLine(renderer, line.x0, line.y0, line.x1, line.y1);




                }


         }
      }

    }


    SDL_RenderPresent(renderer);


  }

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
