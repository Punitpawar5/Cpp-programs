#include<iostream>
#include<conio.h>
using namespace std;
class employees
{
	private:
		int salary;
		string name,des;
	public:
		void input()
		{
			cout<<"\nEnter name of employee = ";
			getline(cin,name);
			cout<<"\nEnter salary of employee = ";
			cin>>(salary);
			cout<<"\nEnter designation of employee = ";
			getline(cin,des);
		}
		void output()
		{
			cout<<"\nName of employee = "<<name;
			cout<<"\nSalary of employee="<<salary;
			cout<<"\nDesignation of employee="<<des;
		}
};
int main()
{
	employees e[100];
	int i,n;
	cout<<"Enter total name of employee = ";
	cin>>n;
	cout<<"\nEnter information of "<<n<<" employee";
		for(i=0;i<n;i++)
		{
			e[i].input();
		}
	cout<<"\nInformation of "<<n<<" employees =";
		for(i=0;i<n;i++)
		{
			e[i].output();
		}
	getch();
	return 0;
}
