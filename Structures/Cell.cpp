#include"Cell.h"

Cell::Cell(char v, bool c){
  value= v;
  changed = c;
}

char Cell::GetValue(){
  return value;
}

bool Cell::GetChange(){
  return changed;
}

void Cell::SetValue(char v){
  value =v;
}

void Cell::SetChange(bool c){
  changed =c;
}
