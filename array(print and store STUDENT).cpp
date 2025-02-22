#include<iostream>
#include<conio.h>
using namespace std;
class student
{
	private:
		string name,add,enroll;
	public:
		void input()
		{
			cout<<"\nEnter name of student = ";
			getline(cin,name);
			cout<<"\nEnter address of student = ";
			getline(cin,add);
			cout<<"\nEnter ENrollment no. = ";
			getline(cin,enroll);
		}
		void output()
		{
			cout<<"\nName of student = "<<name;
			cout<<"\nAddress of student = "<<add;
			cout<<"\nEnrollment no. = "<<enroll;
		}
};
int main()
{
	student s;
	s.input();
	s.output();
	getch();
	return 0;
}
