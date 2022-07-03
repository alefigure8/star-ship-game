#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "./headers/helpers.h"
#include "./headers/nave.h"

class ASTEROID{
  int x, y;

  public:
  ASTEROID(int _x, int _y): x(_x), y(_y){};
  int X(){ return x; };
  int Y(){ return y; };
  void draw();
  void move();
  void crash(NAVE &nave);
  void exploite();

};

void ASTEROID::exploite(){
  locate(x, y); printf(" ");
  locate(x, y); printf("X");
  Sleep(200);
  locate(x, y); printf(" ");
}

void ASTEROID::draw(){
  locate(x, y); printf("%c", 184);
}

void ASTEROID::move(){
  locate(x, y); printf(" ");
  y++;
  if(y > 32){ // if asteroid is out of screen reset it to the top
    x = rand() %  71 + 4;
    y = 4;
  }
  draw();
}

void ASTEROID::crash(NAVE &nave){
  if(x >= nave.X() && x <= nave.X() + 6 && y >= nave.Y() && y <= nave.Y() + 3){
    nave.heartsDown();
    nave.crash();
    nave.hearts();
    nave.draw();
    locate(x, y); printf(" ");
    x = rand() % 71 + 4;
    y = 4;
  }
}