#include <iostream>
#include <Windows.h>
#include "./headers/helpers.h"
#include "./headers/nave.h"
#include "./headers/asteroid.h"
using namespace std;

int main (void){
  hideCursor();
  bool game_over = false;
  int x = 10, y = 10, heart = 3, lives = 3;

  // draw the frame
  frameScreen();

  // init nave
  NAVE nave(x, y, heart, lives);
  nave.draw();
  nave.hearts();

  // init asteroid
  ASTEROID asteroid(rand() % 71 + 4, 4);


  // main loop
  while (!game_over){

    // move ateroid
    asteroid.move();

    // move nave
    nave.move();
    nave.exploite();

    // Reduce the continuous loop
    Sleep(30);
  }

  return 0;
}