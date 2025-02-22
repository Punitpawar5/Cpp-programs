#include<iostream>
#include<conio.h>
using namespace std;
class cds
{
	static int count;
	public:
		cds()
		{
			count++;
			cout<<"\nObject no"<<count<<"created";
		}
		~cds()
		{
			cout<<"\nObject no"<<count<<"destroyed";
			count--;
		}
};
int cds::count=0;
int main()
{
	cds c1,c2,c3;
	{
		cout<<"\nInside inner block-1";
		cds c4,c5;
	}
	cout<<"\nBack in main";
	{
		cout<<"\nInside inner block-2";
		cds c6,c7,c8;
	}
	getch();
	return 0;
}
