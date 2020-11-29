
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
      string symbol;
      Board* playerBoard;

    public:

      Player(string n, string s, Board* b);
      char GetSymbol();
      string GetName();
      bool Play();
      bool Win();


};
