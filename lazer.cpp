#include <Windows.h>
#include "./headers/helpers.h"


class LAZER {
  int x, y;
  public:
  LAZER(int _x, int _Y): x(_x), y(_Y){};
  void move();
};

void LAZER::move(){
  locate(x, y); printf(" ");
  if(y > 4){
    y--;
    locate(x, y); printf("%c", 219);
  }
}