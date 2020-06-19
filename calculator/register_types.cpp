#include "register_types.h"
#include "core/class_db.h"
#include "calculatorRef.h"
#include "calculatorNode.h"

void register_calculator_types(){
	ClassDB::register_class<CalculatorNode>();
	ClassDB::register_class<CalculatorRef>();
}

void unregister_calculator_types() {
}
