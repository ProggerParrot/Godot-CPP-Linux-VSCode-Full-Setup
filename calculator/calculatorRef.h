//insert the Headername here
#ifndef CALCULATORREF_H
#define CALCULATORREF_H

#include "core/reference.h"

class CalculatorRef : public Reference {
  GDCLASS(CalculatorRef, Reference);

protected:
  static void _bind_methods();

public:
  CalculatorRef();

  int add(int a, int b);
  int sub(int a, int b);
  int mul(int a, int b);
  int div(int a, int b);

};

#endif
