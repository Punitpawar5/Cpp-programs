//operator overloading using urany operator


#include<conio.h>
#include<iostream>
using namespace std;
class uover
{
	int x, y;
	public:
		uover(int a, int b)
		{
			x=a; y=b;
		}
		void show()
		{
			cout<<"\nValue of x = "<<x;
			cout<<"\nValue of y = "<<y;
		}
		void operator-()
		{
			x=-x;
			y=-y;
		}
};
int main()
{
	uover u(10,-20);
	u.show();
	cout<<"\n";
	-u;
	u.show();
	getch();
	return 0;
}
