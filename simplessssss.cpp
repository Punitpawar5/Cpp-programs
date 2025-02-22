#include<iostream>
#include<conio.h>
using namespace std;
class simple
{
	public:
		void interest(int p, int r, int t)
		{
			cout<<"enter principle amount= ";
			cin>>p;
			cout<<"enter rate of interest= ";
			cin>>r;
			cout<<"enter time period= ";
			cin>>t;
			cout<<"Simple interest="<<(p*r*t)/100;
		}
		void interest(float p, float r, float t)
		{
			cout<<"enter principle amount= ";
			cin>>p;
			cout<<"enter rate of interest= ";
			cin>>r;
			cout<<"enter time period= ";
			cin>>t;
			cout<<"Simple interest="<<(p*r*t)/100;
		}
};
int main()
{
	simple s;
	s.interest();
	s.interest((float));
	getch();
	return 0;
}
