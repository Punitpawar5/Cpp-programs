//operator overloading using binary operator



#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
	int x, y;
	public:
		complex(int a, int b)
		{
			x=a; y=b;
		}
		void show()
		{
			cout<<"\nValue of 1st real and complex number = "<<x;
			cout<<"\nValue of 2nd real and complex number = "<<y;
		}
		complex()
		{
			x=0; y=0;
		}
		complex operator+(complex m)
		{
			complex ans;
			ans.x = x+ m.x;
			ans.y = y+ m.y;
			return ans;
		}
		void print()  
        {  
            cout << x << " + " << y << "i" << "\n";  
        }
};
int main()
{
	complex b1(10,20);
	b1.show();
	cout<<"\n";
	complex b2(4,6);
	b2.show();
	complex b3;
	b3 = b1 + b2;
	cout<<"\n\ncomplex number = ";
	b3.print();
	getch();
	return 0;
}
