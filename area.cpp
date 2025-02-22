#include<iostream>
#include<conio.h>
using namespace std;
class findarea
{
	public:
		void area(float r)
		{
			cout<<"\nArea of circle= "<<3.14*r*r;
		}
		void area(int l,  int b)
		{
			cout<<"\nArea of rectangle= "<<l*b;
		}
		void area(float b, float h)
		{
			cout<<"\nArea of triangle= "<<0.5*b*h;
		}
};
int main()
{
	findarea f;
	f.area(6.5);
	f.area(9,8);
	f.area((float)3.5,(float)4.5);
	getch();
	return 0;
}
