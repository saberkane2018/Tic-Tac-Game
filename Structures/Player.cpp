#include"Player.h"

Player::Player(string n, string s, Board* b){
  name =n;
  symbol =s;
  playerBoard =b;
}


char Player::GetSymbol(){
  return symbol[0];
}

string Player::GetName(){
  return name;
}

bool Player::Play(){
  char choice;
  cout << "\n " << name << " might choose a number : ";
  cin >> choice;

  bool changePlayer = playerBoard->SetValue(choice, GetSymbol());
  return changePlayer;
}

bool Player::Win(){
  bool HorizontalResult;
  bool VerticalResult;
  bool DiagResult = true;
  bool AntiDiagResult = true;
  int H =0;
  int V =0;
  // This serves for horizontal and vertical checking
  for (int i = 0; i < 3; i++) {
    HorizontalResult = true;
    VerticalResult = true;
    for (int j = H; j < H + 3; j++){
      HorizontalResult &= ((*playerBoard).GetBoard()[j].GetValue()== GetSymbol() &&(*playerBoard).GetBoard()[j].GetChange()== true );
    }
    for (int j = V; j < V + 7; j= j+3){
      VerticalResult &= ((*playerBoard).GetBoard()[j].GetValue()== GetSymbol() &&(*playerBoard).GetBoard()[j].GetChange()== true );
    }

    H += 3;
    V += 1;
    if(HorizontalResult || VerticalResult)
      return true;
  }
  // this serves for diagonal and antidiagonal checking
  DiagResult = true;
  AntiDiagResult = true;
  for (int j = 0; j < 9; j = j+4){
    DiagResult &= ((*playerBoard).GetBoard()[j].GetValue()== GetSymbol() &&(*playerBoard).GetBoard()[j].GetChange()== true );
  }
  for (int j = 2; j < 7; j= j+2){
    AntiDiagResult &= ((*playerBoard).GetBoard()[j].GetValue()== GetSymbol() &&(*playerBoard).GetBoard()[j].GetChange()== true );
  }

  if(DiagResult || AntiDiagResult)
    return true;


  return false;


}
