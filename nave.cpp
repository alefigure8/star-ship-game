#include "./headers/helpers.h"
#include <conio.h>

class NAVE {

  int x, y;
  int heart;
  int lives;

  public:
    NAVE(int _x, int _y, int _hearts, int _lives):x(_x), y(_y), heart(_hearts), lives(_lives){}
    void draw();
    void erase();
    void move();
    void hearts();
    void exploite();
};

void NAVE::hearts(){
  locate(50, 2); printf("LIVES: %d", lives);
  locate(64, 2); printf("HEALTH");
  locate(72, 2); printf("   ");
  for (int i = 0; i < heart; i++){
    locate(72 + i, 2); printf("%c", 3);
  }
}


void NAVE::draw(){
  locate(x,y);      printf("  %c", 30);
  locate(x,y + 1);  printf(" %c%c%c", 40, 207, 41);
  locate(x,y + 2);  printf("%c%c %c%c", 30, 190, 190, 30);
}

void NAVE::erase(){
  locate(x,y);      printf("      ");
  locate(x,y + 1);  printf("      ");
  locate(x,y + 2);  printf("      ");
}

void NAVE::move(){
  if(kbhit()){
    char key = getch();
    erase();
    moveCursor (key, x, y, heart);
    draw();
    hearts();
  }
}

void NAVE::exploite(){
  if(heart == 0){

    erase();
    locate(x,y);     printf("   **   ");
    locate(x,y + 1); printf("  ****  ");
    locate(x,y + 2); printf("   **   ");
    Sleep(150);

    erase();
    locate(x,y);     printf(" \\**/ " );
    locate(x,y + 1); printf(" **** ");
    locate(x,y + 2); printf("/ ** \\");
    Sleep(200);
    erase();

    lives--;
    heart = 3;
    hearts();
    draw();
  }
}