#include<windows.h>
#include<stdio.h>

#include<conio.h>

#include <stdlib.h>

#include<string.h>                 

#include<ctype.h>                   

#include<dos.h>                    

#include<time.h>



#define RETURNTIME 15



char catagories[][15]={"Student","Teacher","Staffs"};

void returnfunc(void);

void mainmenu(void);

void addstaff(void);

void deletestaff(void);

void editstaff(void);

void searchstaff(void);

void viewstaff(void);

void closeapplication(void);

int  getdata();

int  checkid(int);

int t(void);



void Password();

void issuerecord();

void loaderanim();





FILE *fp,*ft,*fs;





COORD coord = {0, 0};



int s;

char findstaff;

char password[10]={"pass"};



void gotoxy (int x, int y)

{

coord.X = x; coord.Y = y; 

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



struct meroDate

{

int mm,dd,yy;

};

struct staff

{

int id;

char stname[20];

char name[20];

char Address[20];

char course[10];

int contact;

int count;

char *cat;

struct meroDate issued;

struct meroDate duedate;

};

struct staff a;

int main()

{

Password();

getch();

return 0;



}

void mainmenu()

{

system("cls");

int i;

gotoxy(20,3);

printf(" INFORMATICS COLLEGE PVT.LTD,PKR \n ");

printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");



gotoxy(20,5);

printf("<1> Fill Up Records   ");

gotoxy(20,7);

printf("<2> Remove Records");

gotoxy(20,9);

printf("<3> Search Records");

gotoxy(20,11);

printf("<4> View Record's list");

gotoxy(20,13);

printf("<5> Modify Record");

gotoxy(20,15);

printf("<6> Close Application");

gotoxy(20,22);

t();

gotoxy(20,18);

printf("Enter your choice:");



switch(getch())

{

case '1':

addstaff();

break;

case '2':

deletestaff();

break;

case '3':

searchstaff();

break;

case '4':

viewstaff();

break;

case '5':

editstaff();

break;

case '6':

{

system("cls");

gotoxy(16,3);

printf("\tCollege Management System");

gotoxy(16,4);

printf("\tProject in C");

gotoxy(16,5);

printf("\tis brought to you by");

gotoxy(16,7);

printf("\tCODE-PROJECTS");

gotoxy(16,8);



exit(0);

}

default:

{

gotoxy(10,25);

printf("\aWrong Entry!!Please re-entered correct option");

if(getch())

mainmenu();

}



}

}

void addstaff(void)    

{

system("cls");

int i;

gotoxy(20,5);

printf("SELECT CATEGORIES");

gotoxy(20,7);

printf("<1> Student");

gotoxy(20,9);

printf("<2> Teacher");

gotoxy(20,11);

printf("<3> Staff");

gotoxy(20,13);

printf("<4> Back to main menu");

gotoxy(20,21);



printf("Enter your choice:");

scanf("%d",&s);

if(s==4)



mainmenu() ;

system("cls");

fp=fopen("stf.dat","ab+");

if(getdata()==1)

{

a.cat=catagories[s-1];

fseek(fp,0,SEEK_END);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

gotoxy(21,14);

printf("The record is sucessfully saved");

gotoxy(21,15);

printf("Save any more?(Y / N):");

if(getch()=='n')

mainmenu();

else

system("cls");

addstaff();

}

}

void deletestaff()    

{

system("cls");

int d;

char another='y';

while(another=='y')  

{

system("cls");

gotoxy(10,5);

printf("Enter the ID to  remove:");

scanf("%d",&d);

fp=fopen("stf.dat","rb+");

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{



gotoxy(10,7);

printf("The record is available");

gotoxy(10,8);

printf("Name is %s",a.name);

gotoxy(10,9);

findstaff='t';

}

}

if(findstaff!='t')

{

gotoxy(10,10);

printf("No record is found modify the search");

if(getch())

mainmenu();

}

if(findstaff=='t' )

{

gotoxy(10,9);

printf("Do you want to delete it?(Y/N):");

if(getch()=='y')

{

ft=fopen("test.dat","wb+");  

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id!=d)

{

fseek(ft,0,SEEK_CUR);

fwrite(&a,sizeof(a),1,ft); 

}                              

}

fclose(ft);

fclose(fp);

remove("stf.dat");

rename("test.dat","stf.dat"); 

fp=fopen("stf.dat","rb+");    

if(findstaff=='t')

{

gotoxy(10,10);

printf("The record is sucessfully deleted");

gotoxy(10,11);

printf("\n\tDelete another record?(Y/N)");

}

}

else

mainmenu();

fflush(stdin);

another=getch();

}

}

gotoxy(10,15);

mainmenu();

}

void searchstaff()

{

system("cls");

int d;

printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbSearch Record\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");


gotoxy(20,10);

printf("1. Search By ID");

gotoxy(20,14);

printf("2. Search By Name");

gotoxy( 15,20);

printf("Enter Your Choice");

fp=fopen("stf.dat","rb+"); 

rewind(fp);   

switch(getch())

{

case '1':

{

system("cls");

gotoxy(25,4);

printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch By Id\xdb\xdb\xdb\xdb\xdb\xdb");

gotoxy(20,5);

printf("Enter the id:");

scanf("%d",&d);

gotoxy(20,7);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{

Sleep(2);

gotoxy(20,6);

printf("The Record is available\n");

gotoxy(20,8);

printf("ID:%d",a.id);

gotoxy(20,9);

printf("Category:%s",a.cat);

gotoxy(20,10);

printf("Name:%s",a.name);

gotoxy(20,11);

printf("Address:%s ",a.Address);

gotoxy(20,12);

printf("Contact:%i ",a.contact);

gotoxy(20,13);

printf("Course:%s",a.course);

findstaff='t';

}



}

if(findstaff!='t')  

{

printf("\aNo Record Found");

}

gotoxy(20,17);

printf("Try another search?(Y/N)");

if(getch()=='y')

searchstaff();

else

mainmenu();

break;

}

case '2':

{

char s[15];

system("cls");

gotoxy(25,4);

printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch Record By Name\xdb\xdb\xdb\xdb\xdb\xdb");

gotoxy(20,5);

printf("Enter the Name:");

scanf("%s",s);

int d=0;

while(fread(&a,sizeof(a),1,fp)==1)

{

if(strcmp(a.name,(s))==0) 

{

	gotoxy(20,d+7);

	//printf("The Staff is available");

	gotoxy(20,d+8);

	printf("ID:%d",a.id);

	gotoxy(20,d+10);

	printf("Name:%s",a.name);

	gotoxy(20,d+11);

	printf("Address:%s",a.Address);

	gotoxy(20,d+12);

	printf("Contact:%i",a.contact);

	gotoxy(20,d+13);
	
	printf("Course:%s",a.course);
	
	gotoxy(20,d+14);

	getch();

	d+=6;

}



}

if(d==0)



printf("\aNo Record Found");



gotoxy(20,d+11);

printf("Try another search?(Y/N)");

if(getch()=='y')

	searchstaff();

else

	mainmenu();

break;

}

default :

getch();

searchstaff();

}

fclose(fp);

}



void viewstaff(void)  

{

int i=0,j;

system("cls");

gotoxy(1,1);

printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbRecord List\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

gotoxy(2,2);

printf("\n CATEGORY === ID ==== NAME ======== ADDRESS ===== CONTACT ===== COURSE      ");


j=4;

fp=fopen("stf.dat","rb");

while(fread(&a,sizeof(a),1,fp)==1)

{

gotoxy(1,j);

printf("%s",a.cat);

gotoxy(14,j);

printf("%d",a.id);

gotoxy(22,j);

printf("%s",a.name);

gotoxy(36,j);

printf("%s",a.Address);

gotoxy(50,j);

printf("%i",a.contact);

gotoxy(65,j);

printf("%s",a.course);

gotoxy(68,j);

printf("\n\n");

j++;

}

fclose(fp);

gotoxy(35,25);

returnfunc();

}

void editstaff(void)  

{

system("cls");

int c=0;

int d,e;

gotoxy(20,4);

printf("\xdb\xdb\xdb\xdb\xdb\xdbEdit Record \xdb\xdb\xdb\xdb\xdb\xdb");

char another='y';

while(another=='y')

{

system("cls");

gotoxy(15,6);

printf("Enter Id to be edited:");

scanf("%d",&d);

fp=fopen("stf.dat","rb+");

while(fread(&a,sizeof(a),1,fp)==1)

{

if(checkid(d)==0)

{

gotoxy(15,7);

printf("This Member is available");

gotoxy(15,8);

printf("The ID:%d",a.id);

gotoxy(15,9);

printf("Enter new name:");

scanf("%s",a.name);

gotoxy(15,10);

printf("Enter new Address:");

scanf("%s",a.Address);

gotoxy(15,11);

printf("Enter new Contact:");

scanf("%i",&a.contact);

gotoxy(15,12);

printf("Enter New Course Name:");

scanf("%s",&a.course);

gotoxy(15,13);

printf("The record is modified");

fseek(fp,ftell(fp)-sizeof(a),0);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

c=1;

}

if(c==0)

{

gotoxy(15,9);

printf("No record found");

}

}

gotoxy(15,16);

printf("Modify another Record?(Y/N)");

fflush(stdin);

another=getch() ;

}

returnfunc();

}

void returnfunc(void)

{

{

gotoxy(15,20);

printf("Press ENTER to return to main menu");

}

a:

if(getch()==13) 

mainmenu();

else

goto a;

}

int getdata()

{

int t;

gotoxy(20,3);

printf("Enter the Information Below");

gotoxy(20,4);

printf("Category:");

gotoxy(31,5);

printf("%s",catagories[s-1]);

gotoxy(21,6);

printf("ID:\t");

gotoxy(30,6);

scanf("%d",&t);

if(checkid(t) == 0)

{

gotoxy(21,13);

printf("\aThe id already exists\a");

getch();

mainmenu();

return 0;

}

a.id=t;

gotoxy(21,7);

printf("Name:");

gotoxy(33,7);

scanf("%s",a.name);

gotoxy(21,8);

printf("Address:");

gotoxy(30,8);

scanf("%s",a.Address);

gotoxy(21,9);

printf("Contact:");

gotoxy(31,9);

scanf("%i",&a.contact);

gotoxy(21,10);

printf("Course:");

scanf("%s",&a.course);

gotoxy(31,10);

return 1;

}

int checkid(int t)  

{

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

if(a.id==t)

return 0;  

return 1; 

}

int t(void) 

{

time_t t;

time(&t);

printf("Date and time:%s\n",ctime(&t));



return 0 ;

}



void Password(void) 

{



system("cls");

char d[25]="Password Protected";

char ch,pass[10];

int i=0,j;





	printf("\t\t\t\tWELCOME\n\t\t\t\t  To \n\t\t   \xdb\xdb\xdb\xdb\xdb\xdb College Management System \xdb\xdb\xdb\xdb\xdb\xdb\n");

	printf("\t \n\n\n Enter Password:");

	

while(ch!=13)

{

ch=getch();



if(ch!=13 && ch!=8){

putch('*');

pass[i] = ch;

i++;

}

}

pass[i] = '\0';

if(strcmp(pass,password)==0)

{

printf("\n\n\n\t\tPassword matched!!");

printf("\n\n\tPress any key to countinue.....");

getch();

mainmenu();

}

else

{

printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");

getch();

Password();

}

}





