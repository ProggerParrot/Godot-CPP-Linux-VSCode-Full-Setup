#include "calculatorRef.h"

CalculatorRef::CalculatorRef(){}

//Bind all your methods used in this class
void CalculatorRef::_bind_methods(){
  ClassDB::bind_method(D_METHOD("add", "a", "b"), &CalculatorRef::add);
  ClassDB::bind_method(D_METHOD("sub", "a", "b"), &CalculatorRef::sub);
  ClassDB::bind_method(D_METHOD("mul", "a", "b"), &CalculatorRef::mul);
  ClassDB::bind_method(D_METHOD("div", "a", "b"), &CalculatorRef::div);
}


//Custom Functions
int CalculatorRef::add(int a, int b) {
  return a+b;
}

int CalculatorRef::sub(int a, int b) {
  return a-b;
}

int CalculatorRef::mul(int a, int b) {
  return a*b;
}

int CalculatorRef::div(int a, int b) {
  return a/b;
}

