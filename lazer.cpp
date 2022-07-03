#include <Windows.h>
#include "./headers/helpers.h"
#include "./headers/nave.h"
#include <list>
using namespace std;


class LAZER {
  int x, y;
  public:
  LAZER(int _x, int _Y): x(_x), y(_Y){};
  int X(){ return x; };
  int Y(){ return y; };
  void move();
  void key();
  bool outOfScreen();
};

void LAZER::move(){
  locate(x, y); printf(" ");
  y--;
  locate(x, y); printf("%c", 219);
}

bool LAZER::outOfScreen(){
  if(y == 4){
    return true;
  }
  return false;
}