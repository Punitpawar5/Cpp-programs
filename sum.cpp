#include<iostream>
#include<conio.h>
 using namespace std;
class sum
{
	private:
		int a,b,c;
	public:
		void input()
		{
			cout<<"enter any two number = ";
			cin>>a>>b;
		}
		void add()
		{
			c=a+b;
		}
		void output()
		{
			cout<<"\nSum of 2 no = "<<c;
		}
};
int main()
{
	sum s;
	s.input();
	s.add();
	s.output();
	getch();
	return 0;
}
