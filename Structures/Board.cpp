#include"Board.h"

Board::Board(){
  string symbol1, symbol2;
  string name1, name2;

  cout<< "what is the name of the first player : ";
  cin>>name1;

  cout<< "\nwhat is the symbol of the first player : ";
  cin>> symbol1;

  cout<< "\nwhat is the name of the second player : ";
  cin>>name2;

  cout<< "\nwhat is the symbol of the second player : ";
  cin>>symbol2;

  Player player1(name1, symbol1, this);
  Player player2(name2, symbol2, this);


  players.push_back(player1);
  players.push_back(player2);

  for (int i = 1; i < 10; i++) {
    char c = '0' + i;
    GameBoard.push_back(Cell(c,false));
  }
}

vector<Cell> Board::GetBoard(){
  return GameBoard;
}

void Board::Draw(){
  int k = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = k; j < k + 3; j++) {
      cout << " " << GameBoard[j].GetValue() << " |" ;
    }
    cout <<endl;
    k += 3;
  }

}

bool Board::EndGame(){
  for (int i = 0; i < 9; i++) {
    if(GameBoard[i].GetChange() == false){
      return true;
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

bool Board::SetValue(char initvalue, char value){
  bool valueSet = false;
  for (int i = 0; i < 9; i++) {
    if(GameBoard[i].GetValue() == initvalue && GameBoard[i].GetChange() == false){
        GameBoard[i].SetValue(value);
        GameBoard[i].SetChange(true);
        valueSet = true;
    }
  }
  return valueSet;

}

Player Board::GetPlayer(int p){
  if(p==1)
    return players[0];
  else
    return  players[1];
}
