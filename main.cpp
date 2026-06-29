#include <iostream>
#include <functional>
#include <cassert>

using namespace std;


int triple_number(int x)
{
	return x * 3;
}
int double_number(int x)
{
	return x * 2;
}
int square(int x)
{
	return x * x;
}

bool greater_than_100(int x)
{
	return (x > 100);
}
bool greater_than_1000(int x)
{
	return (x > 1000);
}


int until(int x, function<int(int)> f, function<bool(int)> g)
{
	while (!g(x))
	{
		x = f(x);
	}
	return x;
}
void tests()
{

	assert(until(1, double_number, greater_than_100) == 128);
	assert(until(10, double_number, greater_than_100) == 160);
	assert(until(100, double_number, greater_than_100) == 200);
	assert(until(101, double_number, greater_than_100) == 101);

	assert(until(1, triple_number, greater_than_100) == 243);
	assert(until(30, triple_number, greater_than_100) == 270);
	assert(until(100, triple_number, greater_than_100) == 300);
	assert(until(101, triple_number, greater_than_100) == 101);

	assert(until(2, square, greater_than_100) == 256);
	assert(until(2, square, greater_than_1000) == 65536);

	assert(until(100, double_number, greater_than_1000) == 1600);
	assert(until(100, triple_number, greater_than_1000) == 2700);


	cout << "All tests passed!" << endl;

}
int main()
{
	tests();
}