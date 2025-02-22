#include<stdio.h>
#include<conio.h>
int sum(int, int);
int main()
{
	int a,b,ans;
	printf("Enter");
	scanf("%d%d",&a,&b);
	ans=sum(a,b);
	printf("\nSum of two number = ");
	return 0;
	getch();
}
int sum(int x,int y)
{
	int c;
	c=x+y;
	return c;
}
