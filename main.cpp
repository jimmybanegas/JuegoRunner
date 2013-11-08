#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <iostream>
#include "Personaje.h"
#include <vector>
#include "Enemigo.h"
#include "Fantasmita.h"
#include "Bomba.h"
#include "Llamas.h"
#include "Cocodrilo.h"

//Screen attributes
const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *meta = NULL;
Mix_Music *music = NULL;
Mix_Chunk *high = NULL;
Mix_Music *winner = NULL;

SDL_Surface *screen = NULL;
//The event structure
SDL_Event event;
//The font
TTF_Font *font = NULL;
//The color of the font
SDL_Color textColor = { 0, 0, 0 };

SDL_Surface *gameover=IMG_Load("personajes/gameover.png"); //
SDL_Surface *win=IMG_Load("personajes/win.png"); //

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "RUNNER", NULL );

    //If everything initialized fine
    return true;
}


bool load_files()
{
    //Load the background image
    background = IMG_Load( "background.png" );

    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 72 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    music = Mix_LoadMUS( "beat.wav" );
    winner =Mix_LoadMUS( "winner.wav" );
    high = Mix_LoadWAV( "high.wav" );

    if(  high == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}


void clean_up()
{
        //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( meta );
    Mix_FreeMusic( music );
    Mix_FreeChunk( high );
    //Close the font
    TTF_CloseFont( font );
    //Quit SDL_ttf
    TTF_Quit();
    Mix_CloseAudio();
    //Quit SDL
    SDL_Quit();
}


int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    Personaje *personaje=new Personaje(0,0);

    std::vector<Enemigo*> enemigos;

    enemigos.push_back(new Fantasmita(personaje));
    enemigos.push_back(new Bomba(personaje));
    enemigos.push_back(new Llamas(personaje));
    enemigos.push_back(new Cocodrilo(personaje));

    //Render the text
     meta = TTF_RenderText_Solid( font, "META", textColor );

    int duracion_animacion=10;
    int cuadro_actual=0;
    int iteracion=0;

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Apply the background
        apply_surface( 0, 0, background, screen );
        apply_surface( 930 , 510 , meta, screen );

        if(personaje->moviendose)
            apply_surface( personaje->personaje_x, personaje->personaje_y, personaje->personajes[cuadro_actual], screen );
        else
            apply_surface( personaje->personaje_x, personaje->personaje_y, personaje->personajes[0], screen );

        for(int i=0; i<4; i++)
        {
            if(enemigos[i]->checkCollision())
            {
                enemigos.clear();
                Mix_PlayMusic( music, -1 );
                apply_surface( 400 , 0 , gameover , screen );
                //apply_surface( 0 , 0 , background , screen );
                //Mix_PlayMusic( music, -1 );
               // personaje=NULL;
               // SDL_Delay(2500);

            }

            if(personaje->getX()>=850 && personaje->getY()>=400)
            {
               Mix_PlayMusic( winner, -1 );
               apply_surface( 400 , 200 , win , screen );


            }

            enemigos[i]->logica(screen);
            enemigos[i]->dibujar(screen);

        }


        //Get the keystates
        Uint8 *keystates = SDL_GetKeyState( NULL );

        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {

               personaje->personaje_y-=10;
               personaje->moviendose=true;
        }

        //If down is pressed
        if( keystates[ SDLK_DOWN ] )
        {
            //     apply_surface( ( SCREEN_WIDTH - down->w ) / 2, ( SCREEN_HEIGHT / 2 - down->h ) / 2 + ( SCREEN_HEIGHT / 2 ), down, screen );
               personaje->personaje_y+=10;
               personaje->moviendose=true;
        }


        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
//            apply_surface( ( SCREEN_WIDTH / 2 - left->w ) / 2, ( SCREEN_HEIGHT - left->h ) / 2, left, screen );
               personaje->personaje_x-=10;
               personaje->moviendose=true;
        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
//            apply_surface( ( SCREEN_WIDTH / 2 - right->w ) / 2 + ( SCREEN_WIDTH / 2 ), ( SCREEN_HEIGHT - right->h ) / 2, right, screen );
             personaje->personaje_x+=10;
             personaje->moviendose=true;
        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        iteracion++;
        if(iteracion==duracion_animacion)
        {
            cuadro_actual++;
            if(cuadro_actual>=4)
            {
                cuadro_actual=0;

            }

            iteracion=0;
            personaje->moviendose=false;
        }


     if(personaje->getY()>400)
       personaje->personaje_y=400;

     if(personaje->getY()<-70)
        personaje->personaje_y=-70;

     if(personaje->getX()>900)
      personaje->personaje_x=900;

     if(personaje->getX()<-70)
        personaje->personaje_x=-70;

    }



    //Clean up
    clean_up();

    return 0;
}
