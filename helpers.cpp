#include <iostream>
#include <Windows.h>

enum keyDirection {
  UP = 72,
  DOWN = 80,
  LEFT = 75,
  RIGHT = 77
};

// Hide the cursor
void locate(int x, int y){
  HANDLE hCon;
  hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;

  SetConsoleCursorPosition(hCon,dwPos);
}


// Move the cursor trough the screen
void moveCursor (char key, int &x, int &y, int &heart){

  if(key == keyDirection::UP && y > 4) y--;
  if(key == keyDirection::DOWN && y + 3 < 33) y++;
  if(key == keyDirection::LEFT  && x > 3) x--;
  if(key == keyDirection::RIGHT  && x + 6 < 77) x++;
  if(key == 'e') heart--;
};

// Hide the cursor
void hideCursor(){
  HANDLE hCon;
  hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  CONSOLE_CURSOR_INFO cci;
  cci.dwSize = 50;
  cci.bVisible = FALSE;

  SetConsoleCursorInfo(hCon, &cci);
}

// frame screen
void frameScreen(){

 //upper line and bottom line
 for (int i = 2; i < 78; i++){
  locate(i, 3); printf("%c", 205);
  locate(i, 33); printf("%c", 205);
 }

  // side lines
  for (int i = 4; i < 33; i++){
    locate(2, i); printf("%c", 186);
    locate(77, i); printf("%c", 186);
  }

  // Corner top left
  locate(2, 3); printf("%c", 201);

  // Corner top right
  locate(77, 3); printf("%c", 187);

  // Corner bottom left
  locate(2, 33); printf("%c", 200);

  // Corner bottom right
  locate(77, 33); printf("%c", 188);
}