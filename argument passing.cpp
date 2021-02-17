#include <iostream>
using namespace std;
int sqr_it(int x);
int main(int argc, char** argv)
{
	int t=10;
	cout << sqr_it(t) <<'x'<< t ;
	return 0;
	{
		int sqr_it(int x)
		{
			x = x*x;
			return x;
		}