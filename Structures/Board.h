/* this class serves to create a tic tac toe game board and defines method to play*/
#pragma once
#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
#include "Player.h"

class Player;
class Board{

  private:


    vector<Player> players;


  public:

    char board[3][3] =  {'1','2','3','4','5','6','7','8','9'};

    Board();
    void SetValue(char initvalue, char value);
    void Draw();
    Player GetPlayer(int p);
    Player TogglePlayer(Player player);
    bool EndGame();




};
