//runtime polymorphism

#include<iostream>
#include<conio.h>
using namespace std;
class base
{
	public:
		virtual void show()
		{
			cout<<"\nShow function of base class";
		}
		void display()
		{
			cout<<"\nDisplay function of base class";
		}
};
class derived: public base
{
	public:
		void show()
		{
			cout<<"\nShow function of derived class";
		}
		void display()
		{
			cout<<"\nDisplay function of derived class";
		}
};
int main()
{
	//base class
	base ob;
	base *bptr;
	bptr =&ob;
	bptr->show();
	bptr->display();
	
	//derived class
	derived od;
	derived *dptr;
	dptr = &od;
	dptr->show();
	dptr->display();
	
	//runtime polymorphism or virtual function use
	bptr = &od;
	bptr->show(); //show function of derived class as output because of base class point points derived class object
	bptr->display();
	((derived *)bptr) -> show();
	getch();
	return 0;
}
