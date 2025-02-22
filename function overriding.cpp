//function overriding

#include<iostream>
#include<conio.h>
using namespace std;
class parent
{
	public:void show()
	{
		cout<<"I am parent class";
	}
};
class child: public parent
{
	public:void show()
	{
		cout<<"\nI am child class";
	}
};
int main()
{
	parent p;
	child c;
	p.show();
	c.show();
	getch();
	return 0;
}
