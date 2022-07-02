#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "./headers/helpers.h"

class ASTEROID{
  int x, y;

  public:
  ASTEROID(int _x, int _y): x(_x), y(_y){};
  void draw();
  void erase();
  void move();
};

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