//operator overloading using binary operator



#include<iostream>
#include<conio.h>
using namespace std;
class bover
{
	int x, y;
	public:
		bover(int a, int b)
		{
			x=a; y=b;
		}
		void show()
		{
			cout<<"\nValue of x = "<<x;
			cout<<"\nValue of y = "<<y;
		}
		bover()
		{
			x=0; y=0;
		}
		bover operator+(bover m)
		{
			bover ans;
			ans.x = x+ m.x;
			ans.y = y+ m.y;
			return ans;
		}
};
int main()
{
	bover b1(10,20);
	b1.show();
	cout<<"\n";
	bover b2(4,6);
	b2.show();
	bover b3;
	b3 = b1 + b2;
	cout<<"\nObject after addition";
	b3.show();
	getch();
	return 0;
}
