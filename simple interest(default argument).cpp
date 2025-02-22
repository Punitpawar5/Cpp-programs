 #include<iostream>
#include<conio.h>
using namespace std;
class SimpleInterest
{
	private:
		float s;
	public:
		void interest(int p, int t, float r=3.2)
		{
			s=(p*r*t)/100;
			cout<<"\nSI = "<<s;
		}
};
int main()
{
	int p,t,age; SimpleInterest si;
	cout<<"\nEnter principle rate and time = ";
	cin>>p>>t;
	cout<<"\nEnter your age";
	cin>>age;
	if(age>=60)
	{
		si.interest(p,t,5.6);
	}
	else
		si.interest(p,t);
		getch();
		return 0;
}
