#include <iostream>
#include <Windows.h>
#include <list>
#include "./headers/helpers.h"
#include "./headers/nave.h"
#include "./headers/asteroid.h"
#include "./headers/lazer.h"
using namespace std;

int main (void){
  hideCursor();
  bool game_over = false;
  int x = 30, y = 10, heart = 3, lives = 3;

  // draw the frame
  frameScreen();

  // init nave
  NAVE nave(x, y, heart, lives);
  nave.draw();
  nave.hearts();

  // init asteroid
  ASTEROID asteroid(rand() % 71 + 4, 4), asteroid2(rand() % 71 + 4, 8), asteroid3(rand() % 71 + 4, 10);

  // init laser
  list<LAZER *> lazer;
  list<LAZER *>::iterator it;


  // main loop
  while (!game_over){

    if(kbhit()){
      char key = getch();
      if(key == 'a'){
        lazer.push_back(new LAZER(nave.X() + 2, nave.Y() - 1));
      }
    }

    // move lazer
    for(it = lazer.begin(); it != lazer.end(); it++){
      (*it)->move();
      if((*it)->outOfScreen()){
        locate((*it)->X(), (*it)->Y()); printf(" ");
        delete (*it); // delete the iterator
        it = lazer.erase(it); // for pass the next iterator
      }
    }

    // move ateroid
    asteroid.move(); asteroid.crash(nave);
    asteroid2.move(); asteroid2.crash(nave);
    asteroid3.move(); asteroid3.crash(nave);

    // move nave
    nave.move();
    nave.exploite();

    // Reduce the continuous loop
    Sleep(30);
  }

  return 0;
}