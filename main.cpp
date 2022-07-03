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
  system("cls");
  bool game_over = false;
  int x = 35, y = 30, heart = 3, lives = 3;
  int points = 0;
  // draw the frame
  frameScreen();

  // init nave
  NAVE nave(x, y, heart, lives);
  nave.draw();
  nave.hearts();

  // init asteroid
  //ASTEROID asteroid(rand() % 71 + 4, 4), asteroid2(rand() % 71 + 4, 8), asteroid3(rand() % 71 + 4, 10);

  list<ASTEROID*> asteroids;
  list<ASTEROID *>::iterator itA;
  for (int i = 0; i < 5; i++){
    asteroids.push_back(new ASTEROID(rand() % 71 + 4, rand() % 5 + 4));
  }

  // init laser
  list<LAZER *> lazer;
  list<LAZER *>::iterator it;


  // main loop
  while (!game_over){
    // points
    locate(4, 2); printf("PINTS: %d", points);

    // lazer movement
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
    for(itA = asteroids.begin(); itA != asteroids.end(); itA++){
      (*itA)->move();
      (*itA)->crash(nave);
    }

    // colision lazer and asteroid
    for(itA = asteroids.begin(); itA != asteroids.end(); itA++){
        for(it = lazer.begin(); it != lazer.end(); it++){
            if((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() + 1 == (*it)->Y())){
              locate((*it)->X(), (*it)->Y()); printf(" "); // erase the lazer
              delete (*it); // delete the iterator
              it = lazer.erase(it); // for pass the next iterator

              (*itA)->exploite();
              delete (*itA); // delete the iterator
              itA = asteroids.erase(itA); // for pass the next iterator
              asteroids.push_back(new ASTEROID(rand() % 71 + 4, rand() % 5 + 4)); // create new asteroid

              points++;
            }
        }
    }

    // move nave
    nave.move();
    nave.exploite();

    // Reduce the continuous loop
    Sleep(30);

    // check if the nave is dead
    if(nave.dead()){
      game_over = true;
    }
  }

  // game over
  system("cls");
  frameScreen();
  locate(30, 20); printf("GAME OVER");
  locate(30, 22); printf("PINTS: %d", points);

  return 0;
}