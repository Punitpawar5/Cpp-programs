#include<iostream>
#include<conio.h>
using namespace std;
class product
{
		string name;
		int price;
	public:
		void input()
		{
			cout<<"Enter name = ";
			getline(cin,name);
			cout<<"\nEnter price = ";
			cin>>price;
		}
		void output()
		{
			cout<<"Name = "<<name;
			cout<<"\nPrice = "<<price;
		}
};
int main()
{
	product p;
	product *ptr;
	ptr = &p;
	ptr->input();
	ptr->output();
	getch();
	return 0;
}
