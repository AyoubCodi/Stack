#include "stack.hpp"
#include <math.h>

// Both functions to execute
double multi(double x, double y)
{
	return x * y;
}
double divi(double x, double y)
{
	return x / y;
}

int main(void)
{
	StackManager sm = StackManager();
	Stack sta = sm.new_stack();
	
	// Function pointers and assinging them to the functions
	double (*a)(double, double);
	double (*b)(double, double);

	a = &multi;
	b = &divi;

	double x = 13/23.87766554+9.6654332-12.765;
	double y = 12/97+21.754332;
	
	// Using adapted functions of the class to execute the callstack
	sta = sm.add(sta, a);
	sta = sm.add(sta, b);

	sm.execute(sta, x, y);

	sta = sm.del(sta);
	return 0;
}
