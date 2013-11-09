#include "Bomba.h"
#include "SDL/SDL_mixer.h"
Bomba::Bomba(Personaje *personaje)
{
    this->x=200;
    this->y=200;
  this->sprites.push_back(IMG_Load("Enemies/spike01.png"));
  this->sprites.push_back(IMG_Load("Enemies/spike02.png"));
  this->sprites.push_back(IMG_Load("Enemies/spike03.png"));
    this->personaje=personaje;
    this->moviendose=true;
    //ctor

}

Bomba::~Bomba()
{
    //dtor
}

void Bomba::logica(Personaje *personaje)
{

    if(va_para_la_derecha){
        this->y--;
    this->x++;
    }else{
        this->y++;
    this->x--;

    }
    if(x>400)
            va_para_la_derecha=false;


    if(x<150)

            va_para_la_derecha=true;


     if(personaje->personaje_x+36>this->x && personaje->personaje_x<this->x+45
            && personaje->personaje_y+40>this->y && personaje->personaje_y<this->y+38){

              Mix_Music *music ;
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
            music = Mix_LoadMUS( "beat.wav" );
            Mix_PlayMusic( music, -1 );

            this->colision=true;
            }


}
