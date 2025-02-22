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
	product *ptr = new product;
	ptr->input();
	ptr->output();
	getch();
	return 0;
}
