//pointer in inheritance

#include<iostream>
#include<conio.h>
using namespace std;
class base
{
	public:
		int b;
		void show()
		{
			cout<<"\nValue of base = "<<b;
		}
};
class derived: public base
{
	public:
		int d;
		void show()
		{
			cout<<"\nValue of derived = "<<d;
		}
};
int main()
{
	//base class value
	base ob;
	base *bptr;
	bptr= &ob;
	bptr->b=100;
	bptr->show(); //base class
	
	//derived class value
	derived od;
	derived *dptr;
	dptr = &od;
	dptr->b=200;
	dptr->d=400;
	dptr->show();  //derived class
	
	//base class pointer has derived class address
	
	bptr= &od;
	bptr ->b=300;	//bptr->d=600;  nhi chlega as d is not defined in base class
	
	bptr -> show();  //base class
	((derived *)bptr)->show();  //base class ke pointer ko derived class ke pointer mein typecast kra h.. that is bptr into dptr
	
	// ((derived *)bptr)->d=900; error nhi h pr work bhi nhi kr rha
	getch();
	return 0;
}
