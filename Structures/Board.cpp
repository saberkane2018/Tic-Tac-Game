#include"Board.h"

Board::Board(){
  char symbol1, symbol2;
  string name1, name2;

  cout<< "what is the name of the first player : ";
  cin>>name1;

  cout<< "what is the symbol of the first player : ";
  cin>>symbol1;

  cout<< "what is the name of the second player : ";
  cin>>name2;

  cout<< "what is the symbol of the second player : ";
  cin>>symbol2;

  Player player1(name1, symbol1, this);
  Player player2(name2, symbol2, this);


  players.push_back(player1);
  players.push_back(player2);
}

void Board::Draw(){

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << " " << board[i][j] << " |" ;
    }
    cout <<endl;
  }

}

bool Board::EndGame(){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if(board[i][j] != players[0].GetSymbol() && board[i][j] != players[1].GetSymbol()){
          return true;
        }
    }
  }
  cout<< "\nEnd of Game" << endl;
  return false;
}

Player Board::TogglePlayer(Player player){

    if(player.GetName() == players[0].GetName())
        return players[1];
    else
        return players[0];
}

void Board::SetValue(char initvalue, char value){

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if(board[i][j] == initvalue){
          board[i][j] = value;
        }
    }
  }

}

Player Board::GetPlayer(int p){
  if(p==1)
    return players[0];
  else
    return  players[1];
}
