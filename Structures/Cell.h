/* this class serves to create a tic tac toe cells*/
#pragma once
#include<iostream>
using namespace std;



class Cell{

  private:

    char value;
    bool changed;


  public:

    Cell(char v, bool c);
    char GetValue();
    bool GetChange();
    void SetValue(char v);
    void SetChange(bool c);


};
