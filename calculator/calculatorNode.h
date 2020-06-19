//insert the Headername here
#ifndef CALCULATORNODE_H
#define CALCULATORNODE_H

#include "scene/main/node.h"


class CalculatorNode : public Node {
	GDCLASS(CalculatorNode, Node);

protected:
  static void _bind_methods();

public:
  CalculatorNode();

  int add(int a, int b);
  int sub(int a, int b);
  int mul(int a, int b);
  int div(int a, int b);

};

#endif
