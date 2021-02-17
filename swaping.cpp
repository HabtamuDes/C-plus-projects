#include <iostream>
using namespace std;
void swap (int *x, int y*);
int main()
{
	int i, j;
	i = 10;
	j = 20;
	cout << "intial values of i and j: ";
	swap (&j, &i);
	cout << "swapped values of i and j: ";
	cout << i << j << '\n';
	return 0;
}
 void swap(int *x, int *y)
 {
 	int temp;
 	temp = *x;
 	*x = *y;
 	*y = temp;
  }