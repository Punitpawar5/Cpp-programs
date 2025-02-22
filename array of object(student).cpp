#include<iostream>
#include<conio.h>
using namespace std;
class student
{
	private:
		string name,enroll;
	public:
		void input()
		{
			cout<<"\nEnter name of student = ";
			getline(cin,name);
			cout<<"\nEnter enrollment number = ";
			getline(cin,enroll);
		}
		void output()
		{
			cout<<"\nName of student= "<<name;
			cout<<"\nEnrollment No.="<<enroll;
		}
};
int main()
{
	student s[100];
	int i,n;
	cout<<"Enter total name of student = ";
	cin>>n;
	cout<<"\nEnter information of "<<n<<"students";
		for(i=0;i<=n-1;i++)
		{
			s[i].input();
		}
	cout<<"\nInformation of "<<n<<"students";
		for(i=0;i<=n-1;i++)
		{
			s[i].output();
		}
	getch();
	return 0;
}
