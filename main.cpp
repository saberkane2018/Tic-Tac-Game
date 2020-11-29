
#include <iostream>
using namespace std;
#include "Structures/Board.h"
#include "Structures/Player.h"


int main() {


    Board Game;
    Player player = Game.GetPlayer(1);// used for toggling between players
    bool cont = true;// the game will continue while this value is true
    bool changePlayer;


    cout<< "\nLet's start the game \nEvery player should choose a number on the given board to place his symbol \n" <<endl;
    Game.Draw();


    while(cont){

      cont = false;
      //Ask the player to play his turn
      changePlayer = player.Play();
      // Draw the board on the console
      Game.Draw();
      //check if any of the players is winning
      if (player.Win()){
        cout << player.GetName()<< " won this game\nCongratulations!!!!!!" <<endl;
        return 0;
      }
      // switch to the next player
      if(changePlayer){
        player = Game.TogglePlayer(player);
      }
      else{
        cout << "number choosen isn't available, this is a symbol, can you try again" << endl;
      }

      // check if we still have empty cells for the game
      cont = Game.EndGame();

    }





}
