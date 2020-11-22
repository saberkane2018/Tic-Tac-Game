#include"Player.h"

Player::Player(string n, char s, Board* b){
  name =n;
  symbol =s;
  playerBoard =b;
}


char Player::GetSymbol(){
  return symbol;
}

string Player::GetName(){
  return name;
}

void Player::Play(){
  char choice;
  cout << "\n " << name << " might choose a number : ";
  cin >> choice;

  playerBoard->SetValue(choice, symbol);

}

bool Player::Win(){
  bool HorizontalResult;
  bool VerticalResult;
  bool DiagResult = true;
  bool AntiDiagResult = true;

  for (int i = 0; i < 3; i++) {
    HorizontalResult = true;
    VerticalResult = true;
    for (int j = 0; j < 3; j++) {
      // this part checks of we dont have any sucess in rows and columns
      HorizontalResult &= ((*playerBoard).board[i][j]== symbol);
      VerticalResult &= ((*playerBoard).board[j][i]== symbol);

    }

    if(HorizontalResult || VerticalResult)
      return true;
    //This part checks if we dont have any sucesss for the diagonal and anti diagonal
    DiagResult &= ((*playerBoard).board[i][i]== symbol);
    AntiDiagResult &= ((*playerBoard).board[2-i][i]== symbol);
  }
  if(DiagResult || AntiDiagResult)
    return true;

  return false;

}
