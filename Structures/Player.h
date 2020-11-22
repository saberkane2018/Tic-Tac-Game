
/* this class serves to create players*/
#pragma once
#include<iostream>
#include<string.h>
using namespace std;

#include"Board.h"

  class Board;

  class Player{
    private:
      string name;
      char symbol;
      Board* playerBoard;

    public:

      Player(string n, char s, Board* b);
      char GetSymbol();
      string GetName();
      void Play();
      bool Win();


};
