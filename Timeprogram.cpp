#include<iostream>
#include<conio.h>
using namespace std;
class Time
{
	int hr, min, sec;
	public:
		
		Time()
		{
			hr=0;
			min=0;
			sec=0;
		}
		Time(int x, int y, int z)
		{
			hr=x;
			min=y;
			sec=z;
		}
		void showTime()
		{
			cout<<"\nTime= "<<hr<<" hours and ";
			cout<<min<<" minutes and ";
			cout<<sec<<" seconds";
		}
		friend Time operator+(Time x, Time y);
};
Time operator+(Time x, Time y)
{
	Time ans;
	ans.hr=x.hr+y.hr;
	ans.min=x.min+y.min;
	ans.sec=x.sec+y.sec;
	if(ans.sec>=60)
	{
		ans.min++;
		ans.sec=ans.sec-60;
	}
	if(ans.min>=60)
	{
		ans.hr++;
		ans.min=ans.min-60;
	}
	return ans;
};
int main()
{
	Time t1(3,40,59);
	t1.showTime();
	Time t2(6,42,39);
	t2.showTime();
	Time t3;
	t3=t1+t2;
	cout<<"\n\nFinal time after addition\n";
	t3.showTime();
	getch();
	return 0;
}
