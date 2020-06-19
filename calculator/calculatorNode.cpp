#include "calculatorNode.h"

CalculatorNode::CalculatorNode(){}

//Bind all your methods used in this class
void CalculatorNode::_bind_methods(){
  ClassDB::bind_method(D_METHOD("add", "a", "b"), &CalculatorNode::add);
  ClassDB::bind_method(D_METHOD("sub", "a", "b"), &CalculatorNode::sub);
  ClassDB::bind_method(D_METHOD("mul", "a", "b"), &CalculatorNode::mul);
  ClassDB::bind_method(D_METHOD("div", "a", "b"), &CalculatorNode::div);
}


//Custom Functions
int CalculatorNode::add(int a, int b) {
  return a+b;
}

int CalculatorNode::sub(int a, int b) {
  return a-b;
}

int CalculatorNode::mul(int a, int b) {
  return a*b;
}

int CalculatorNode::div(int a, int b) {
  return a/b;
}

