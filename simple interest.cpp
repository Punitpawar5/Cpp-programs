#include<iostream>
#include<conio.h>
using namespace std;
class SimpleInterest
{
	public:
		void simple(int p, int r, int t)
		{
			cout<<"\nSI = "<<(p*r*t)/100;
		}
		void simple(float p, float r, float t)
		{
			cout<<"\nSI = "<<(p*r*t)/100;
		}
};
int main()
{
	SimpleInterest si;
	si.simple(500000,600,8);
	si.simple((float)5000.0,(float) 600.3, (float) 5);
	getch();
	return 0;
}
