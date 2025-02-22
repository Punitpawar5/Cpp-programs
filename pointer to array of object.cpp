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
			cout<<"\nEnter name of product = ";
			cin>>name;
			cout<<"\nEnter price of product = ";
			cin>>price;
		}
		void output()
		{
			cout<<"\nName = "<<name;
			cout<<"\tPrice = "<<price;
		}
};
int main()
{
	product *ptr= new product[4];
	product *q= ptr;
	int i;
		std::cout<<"Enter values of all products\n";
		for(i=1;i<=4;i++)
		{
			ptr->input();
			ptr++;
		}
		std::cout<<"\nInfo of all products\n";
		for(i=1;i<=4;i++)
		{
			q->output();
			q++;
		}
	getch();
	return 0;
}
