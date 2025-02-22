#include<iostream>
#include<conio.h>
using namespace std;
class area
{
	public:
		void circle(int r)
		{
			float a;
			a=3.14*r*r;
			cout<<"Area of circle = "<<a;
		}
		void circle(double r)
		{
			float a;
			a=3.14*r*r;
			cout<<"Area of circle = "<<a;
		}
};
int main()
{
	area ar;
	ar.circle(600);
	ar.circle(810.2);
	getch();
	return 0;
}

