#include "stack.hpp"

int main(void)
{
	StackManager sm = StackManager();
	Stack sta = sm.new_stack();

	long double a = 12.97644*23.876533+6/7.8654;
	long double b = 22/9.8643*12.9875423;
	long double c = 12/9.7655312;
	long double d = 3.875543/7.96777656545*2.975432;

	sta = sm.add(sta, a, b);
	sta = sm.add(sta, c, d);

	sm.print(sta);

	sta = sm.del(sta);

	return 0;
}
