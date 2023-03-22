#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/**
 * Siska Dávid - WHDDUM
 */




int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;



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
    "Rectangle draw by David Siska (WHDDUM) 2023.",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600,
    SDL_WINDOW_OPENGL);

     SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
SDL_Rect rectangle;

rectangle.w = 100;
rectangle.h = 50;

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






        if ( SDL_BUTTON_LEFT == event.button.button )
         {
               int x, y;
               SDL_GetMouseState( &x, &y );


                j++;

                if(j == 1)
                {

                SDL_Log("LOG: Teglalap letrehozva.");


                j = 0;


                srand(time(0));

                int r = rand() % 256;

                int g = rand() % 256;

                int b = rand() % 256;


                SDL_SetRenderDrawColor(renderer,r,g,b,SDL_ALPHA_OPAQUE);




                rectangle.x = x;
                rectangle.y = y;

                SDL_RenderFillRect(renderer,&rectangle);

                SDL_RenderDrawRect(renderer,&rectangle);









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
