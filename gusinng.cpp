#include <iostream>
#include<cstdlib>
using namespace std;
void drill();
int count;
int num_right;
int main(int argc, char** argv)
{
	cout <<" how many practice problemes: ";
	cin>> count;
	num_right = 0;
	do{
		drill();
		count--;
		
	}
	while (count);
	cout<<"you got"<< num_right << "right.\n";
return 0;
{
	void drill()
	
}
	int count;
	int a,b;ans;
	a = rand() % 100;
	b = rand() % 100;
	for(count=0;count<3; count++){
		cout << "what is "<< a<<"+"<<b<<"?";
		cin >> ans;
		if( ans==a+b){
			cout <<"right\n";
			num_right++;
			return;
		}
	}
	cout <<"you have used up all your tries.\n";
	cout<<"the ansewr is "<<a+b<<'\n';
}