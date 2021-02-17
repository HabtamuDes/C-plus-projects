			// This Program Developed
			// For Dilla University
			//	New Campus Registrar Office

#include<iostream.h>  // To Input Output Statment
#include<conio.h>     // To Clear Screen
#include<fstream.h>   // To Ifstream Ofstream Fstream Statment
#include<string.h>    // To Strcpy Or String Copy
#include<dos.h>       //
#include<ctype.h>     //
#include<process.h>   //
struct student{
	char name[20],father_name[20],grand_father_name[20]; //    All This
	char department[30],sex,ch,ID[15];                   //   Are The Data
	int age,DD,MM,YY,EHEECE;                             //  Member Of Student
	float prep_result,GPA;                               // Information And Class
	int band,choice1,choice2,choice3,choice4,choice5;    //
	}stud[300];
	int fn=0;
void Record();      // To Accepts Student Data
void Show();        // To Read Data From File And Display Data
void display();     //
void Search();      // To Search Specific Student Data
void programmers(); // To Display List Of Programmers


	void display()
	{
	gotoxy(24,24);
	cout<<"\n\t\t+---------------------------------------+\n";
	cout<<"\t\t|     Registration Successfull!!        |\n";
	cout<<"\t\t+---------------------------------------+\n\n";}


void Record() // This Function Is To Accepts Student Data
{
clrscr();
int m,h=0,k,u;
char op;
fstream d;
cout<<"\n\t\t+------------------------------------------+\n";
cout<<"\t\t|How Many Students Do You Want To Register?|\n";
cout<<"\t\t+------------------------------------------+\n";
cout<<"\t\t--> ";
cin>>m;
d.open("h:\Nofiles.txt",ios::in|ios::out); // To Count Number Of Written Files
u=m;
while(!d.eof())
d>>h;
k=u+h;
d.close();
d.open("h:\Nofiles.txt",ios::out|ios::trunc); // To Write Counted File
d<<k;
d.close();
ofstream file;
file.open("h:\Student.txt",ios::out|ios::app);
cout<<"\n\t\tNow You Are Registering "<<m<<" Student Data"<<endl<<endl;
for(int j=0;j<m;j++)
{
cout<<"1.By New Student Data Form\n\n";
cout<<"2.By Existing Student Data Form\n\n";
cout<<"Select Your Choice -->";
op=getch();
if(op=='1')
	{
	cout<<"\n\nEnter First Name Of Student -> "<<j+1<<endl;
	cin>>stud[j].name;
	file<<stud[j].name<<" ";
	cout<<"\n\nEnter Father Name -> ";
	cin>>stud[j].father_name;
	file<<stud[j].father_name<<" ";
	cout<<"\n\nEnter Grand Father Name -> ";
	cin>>stud[j].grand_father_name;
	file<<stud[j].grand_father_name<<endl;
	cout<<"\n\nEnter Sex  M Or F -> ";
	cin>>stud[j].sex;
	file<<stud[j].sex<<endl;
	do
	{
	cout<<"\n\nEnter Birth Date In Ethiopian Calender Write This form DD/MM/YY -> ";
	cin>>stud[j].DD;
	file<<stud[j].DD;
	cin>>stud[j].ch;
	file<<stud[j].ch;
	cin>>stud[j].MM;
	file<<stud[j].MM;
	cin>>stud[j].ch;
	file<<stud[j].ch;
	cin>>stud[j].YY;
	file<<stud[j].YY<<endl;
	}
	while(stud[j].DD>31||stud[j].DD<1||stud[j].ch!='/'||stud[j].MM>13||stud[j].MM<1||stud[j].YY>1985);
	cout<<"\n\nEnter The Age -> ";
	cin>>stud[j].age;
	file<<stud[j].age<<endl;
	cout<<"\n\nEnter Enterance Exam Rresult -> ";
	cin>>stud[j].EHEECE;
	file<<stud[j].EHEECE<<endl;
	cout<<"\n\nEnter Preparatory Transcript Average -> ";
	cin>>stud[j].prep_result;
	file<<stud[j].prep_result<<endl;
	cout<<"\n\nEnter ID Number -> ";
	cin>>stud[j].ID;
	file<<stud[j].ID<<endl;
	stud[j].GPA=0.00;
	file<<stud[j].GPA<<'\n';
	cout<<"\n\nSelect Your Band:"
	<<"\n\n\t\t*============================*"
	<<"\n\n\t\t|1.Comptetional Science      |"
	<<"\n\n\t\t|2.Engineering and Technology|"
	<<"\n\n\t\t*============================*"
	<<"\n\n\t\t  -->";
	cin>>stud[j].band;
	if(stud[j].band==1)
	{
	cout<<"\n\nSelect What You Want To Study In Order: Example [2 5 4 1 3 ]"
	<<"\n\n\t\t+---------------+"
	<<"\n\n\t\t| 1.English     |"
	<<"\n\n\t\t| 2.Biology     |"
	<<"\n\n\t\t| 3.Physics     |"
	<<"\n\n\t\t| 4.Chemistry   |"
	<<"\n\n\t\t| 5.Mathematics |"
	<<"\n\n\t\t|_______________|\n\n";
	cin>>stud[j].choice1>>stud[j].choice2>>stud[j].choice3
	>>stud[j].choice4>>stud[j].choice5;
	clrscr();
	gotoxy(24,24);
	cout<<"\n\n\t\t     #==================#";
	cout<<"\n\n\t\t     # Please Wait..... #";
	cout<<"\n\n\t\t     #==================#";
	clrscr();
display();
if(stud[j].EHEECE + stud[j].prep_result > 300)
{
if(stud[j].choice1==1)
{
strcpy(stud[j].department,"English");
cout<<"\n\n\t|`````````````````````````````````````|";
cout<<"\n\n\t| You Are English Department Student! |";
cout<<"\n\n\t```````````````````````````````````````";
file<<stud[j].department<<endl;
}
else if(stud[j].choice1==2)
{
strcpy(stud[j].department,"Biology");
cout<<"\n\n\t|`````````````````````````````````````|";
cout<<"\n\n\t| You Are Biology Department Student! |";
cout<<"\n\n\t```````````````````````````````````````";
file<<stud[j].department<<endl;
}
else if(stud[j].choice1==3)
{
strcpy(stud[j].department,"Physics");
cout<<"\n\n\t|`````````````````````````````````````|";
cout<<"\n\n\t| You Are Physics Department Student! |";
cout<<"\n\n\t```````````````````````````````````````";
file<<stud[j].department<<endl;
}
else if(stud[j].choice1==4)
{
strcpy(stud[j].department,"Chemistry");
cout<<"\n\n\t|```````````````````````````````````````|";
cout<<"\n\n\t| You Are Chemistry Department Student! |";
cout<<"\n\n\t`````````````````````````````````````````";
file<<stud[j].department<<endl;
}
else
{
strcpy(stud[j].department,"Mathematics");
cout<<"\n\n\t|`````````````````````````````````````````|";
cout<<"\n\n\t| You Are Mathematics Department Student! |";
cout<<"\n\n\t```````````````````````````````````````````";
file<<stud[j].department<<endl;
}
}
else
{
if(stud[j].choice2==1)
{
strcpy(stud[j].department,"English");
cout<<"\n\n\t|`````````````````````````````````````|";
cout<<"\n\n\t| You Are English Department Student! |";
cout<<"\n\n\t```````````````````````````````````````";
file<<stud[j].department<<endl;
}
else if(stud[j].choice2==2)
{
strcpy(stud[j].department,"Biology");
cout<<"\n\n\t|`````````````````````````````````````|";
cout<<"\n\n\t| You Are Biology Department Student! |";
cout<<"\n\n\t```````````````````````````````````````";
file<<stud[j].department<<endl;
}
else if(stud[j].choice2==3)
{
strcpy(stud[j].department,"Phtsics");
cout<<"\n\n\t|`````````````````````````````````````|";
cout<<"\n\n\t| You Are Physics Department Student! |";
cout<<"\n\n\t```````````````````````````````````````";
file<<stud[j].department<<endl;
}
else if(stud[j].choice2==4)
{
strcpy(stud[j].department,"Chemistry");
cout<<"\n\n\t|```````````````````````````````````````|";
cout<<"\n\n\t| You Are Chemistry Department Student! |";
cout<<"\n\n\t`````````````````````````````````````````";
file<<stud[j].department<<endl;
}
else
{
strcpy(stud[j].department,"Mathematics");
cout<<"\n\n\t|`````````````````````````````````````````|";
cout<<"\n\n\t| You Are Mathematics Department Student! |";
cout<<"\n\n\t```````````````````````````````````````````";
file<<stud[j].department<<endl;
} //
} // To Second If Statment
} // To First If Statment
else
{
clrscr();
gotoxy(24,24);
cout<<"\n\n\t\t     #==================#";
cout<<"\n\n\t\t     # Please Wait..... #";
cout<<"\n\n\t\t     #==================#";
clrscr();
display();
strcpy(stud[j].department,"ComputerScience");
file<<stud[j].department<<endl;
cout<<"\n\n\t|``````````````````````````````````````````````|";
cout<<"\n\n\t| You Are Computer Science Department Student! |";
cout<<"\n\n\t````````````````````````````````````````````````";
}
getch();
cout<<endl;
clrscr();
gotoxy(20,20);
cout<<"\n\t\t+---------------------------+";
cout<<"\n\t\t| Registration Successful!! |";
cout<<"\n\t\t|Registered "<<k<<" Student Data! |";
cout<<"\n\t\t+---------------------------|\n";
}
else
{
cout<<"\n\nEnter First Name Of Student -> "<<j+1<<endl;
cin>>stud[j].name;
file<<stud[j].name<<" ";
cout<<"\n\nEnter Father Name -> ";
cin>>stud[j].father_name;
file<<stud[j].father_name<<" ";
cout<<"\n\nEnter Grand Father Name -> ";
cin>>stud[j].grand_father_name;
file<<stud[j].grand_father_name<<endl;
cout<<"\n\nEnter Sex  M Or F -> ";
cin>>stud[j].sex;
file<<stud[j].sex<<endl;
do
{
cout<<"\n\nEnter Birth Date In Ethiopian Calender Write This form DD/MM/YY -> ";
cin>>stud[j].DD;
file<<stud[j].DD;
cin>>stud[j].ch;
file<<stud[j].ch;
cin>>stud[j].MM;
file<<stud[j].MM;
cin>>stud[j].ch;
file<<stud[j].ch;
cin>>stud[j].YY;
file<<stud[j].YY<<endl;
}
while(stud[j].DD>31||stud[j].DD<1||stud[j].ch!='/'||stud[j].MM>13||stud[j].MM<1||stud[j].YY>1985);
cout<<"\n\nEnter The Age -> ";
cin>>stud[j].age;
file<<stud[j].age<<endl;
cout<<"\n\nEnter Enterance Exam Result -> ";
cin>>stud[j].EHEECE;
file<<stud[j].EHEECE<<endl;
cout<<"\n\nEnter Preparatory Transcript Average -> ";
cin>>stud[j].prep_result;
file<<stud[j].prep_result<<endl;
cout<<"\n\nEnter ID Number -> ";
cin>>stud[j].ID;
file<<stud[j].ID<<endl;
cout<<"Enter GPA -> "<<endl;
cin>>stud[j].GPA;
file<<stud[j].GPA<<endl;
file<<"ComputerScience";
clrscr();
gotoxy(20,20);
cout<<"\n\t\t+---------------------------+";
cout<<"\n\t\t| Registration Successful!! |";
cout<<"\n\t\t|     Total Records->   "<<k<<"   |";
cout<<"\n\t\t+---------------------------+";
}
}
file.close();
}


	void Show() // To Read Data From File And Display Data
	{
	int f=0;
	ifstream s;
	s.open("h:\Student.txt",ios::in|ios::end|ios::beg);
	while(!s.eof())
	{
	s>>stud[f].name;
	cout<<"\nFull Name: "<<stud[f].name<<" ";
	s>>stud[f].father_name;
	cout<<stud[f].father_name<<" ";
	s>>stud[f].grand_father_name;
	cout<<stud[f].grand_father_name<<endl;
	s>>stud[f].sex;
	cout<<"\nSex: "<<stud[f].sex<<endl;
	s>>stud[f].DD;
	cout<<"\nBirth Date: "<<stud[f].DD;
	s>>stud[f].ch;
	cout<<stud[f].ch;
	s>>stud[f].MM;
	cout<<stud[f].MM;
	s>>stud[f].ch;
	cout<<stud[f].ch;
	s>>stud[f].YY;
	cout<<stud[f].YY<<endl;
	s>>stud[f].age;
	cout<<"\nAge: "<<stud[f].age<<endl;
	s>>stud[f].EHEECE;
	cout<<"\Enterance Result: "<<stud[f].EHEECE<<endl;
	s>>stud[f].prep_result;
	cout<<"\nPreparatory Result: "<<stud[f].prep_result<<endl;
	s>>stud[f].ID;
	cout<<"\nID: "<<stud[f].ID<<endl;
	s>>stud[f].GPA;
	cout<<"\nGPA: "<<stud[f].GPA<<'\n';
	s>>stud[f].department;
	cout<<"\nDepartment: "<<stud[f].department<<endl;
	f++;
	getch();
	}
	s.close();
	}


void Search() // To Search Specific Student Data
{
int j=0,l,a=0,f;
char k[15],m;
fstream x;
x.open("h:\Nofiles.txt",ios::in|ios::out);
while(!x.eof())
x>>a;
l=a;
x.close();
ifstream off;
do
{
clrscr();
gotoxy(20,20);
cout<<"\n\nPlease Insert Student ID You Want To Search --> ";
cin>>k;
off.open("h:\Student.txt",ios::in);
for(f=0;f<l;f++)
{
off>>stud[f].name;
off>>stud[f].father_name;
off>>stud[f].grand_father_name;
off>>stud[f].sex;
off>>stud[f].DD;
off>>stud[f].ch;
off>>stud[f].MM;
off>>stud[f].ch;
off>>stud[f].YY;
off>>stud[f].age;
off>>stud[f].EHEECE;
off>>stud[f].prep_result;
off>>stud[f].ID;
if(strcmp(k,stud[f].ID)==0)
{
clrscr();
cout<<"\nFull Name: "<<stud[f].name<<" ";
cout<<stud[f].father_name<<" ";
cout<<stud[f].grand_father_name<<"\n";
cout<<"sex: "<<stud[f].sex<<endl;
cout<<"\nBirth Date: "<<stud[f].DD;
cout<<stud[f].ch;
cout<<stud[f].MM;
cout<<stud[f].ch;
cout<<stud[f].YY<<'\n';
cout<<"Age: "<<stud[f].age<<endl;
cout<<"Entrance Result: "<<stud[f].EHEECE<<endl;
cout<<"Preparatory Result: "<<stud[f].prep_result<<endl;
cout<<"ID: "<<stud[f].ID<<endl;
off>>stud[f].GPA;
cout<<"GPA: "<<stud[f].GPA<<endl;
off>>stud[f].department;
cout<<"Department: "<<stud[f].department<<endl;
j=1;
}
off>>stud[f].GPA;
off>>stud[f].department;
}
char g;
if(j==0)
{
cout<<"\n\t\t#===================================================#";
cout<<"\n\t\t# Sorry! This ID Is Do Not Exist! Please Try Again? #";
cout<<"\n\t\t#===================================================#";
cout<<"\n\t\t-->";
cin>>m;
}
}
while(m=='r'||m=='R');
}


	void programmers()
	{
	clrscr();
	cout<<"\t\t+-----------------------------------+\n";
	cout<<"\t\t|            Programmers            |\n";
	cout<<"\t\t|-----------------------------------|\n";
	cout<<"\t\t|No.|  Name            |  ID No.    |\n";
	cout<<"\t\t|-----------------------------------|\n";
	cout<<"\t\t|1. | YMRAHA AYALEW    | RCS-126/12 |\n";
	cout<<"\t\t|2. | SAMRAWIT TADELE  | RCS-/12    |\n";
	cout<<"\t\t|3. | MEKI LEGESO      | RCS-/12    |\n";
	cout<<"\t\t|4. | ABEBE            | RCS-/12    |\n";
	cout<<"\t\t|5. | SUALIH           | RCS-/12    |\n";
	cout<<"\t\t|6. | YETMWORK         | RCS-/12    |\n";
	cout<<"\t\t+-----------------------------------+\n";
	}


void main()
{
clrscr();
student Order;
char i;
char choic;
gotoxy(18,20);
cout<<"\n            |==============================================|\n";
cout<<"            | Welcome To Dilla University Registrar Office |\n";
cout<<"            |==============================================|";
gotoxy(22,25);
cout<<" Press Any Button To Continue -->";
getch();
do
{
clrscr();
gotoxy(24,20);
cout<<"What Do You Like To Do?\n";
cout<<"                                [MENU]\n";
gotoxy(20,22);
cout<<"->1.Insert New Student Information\n";
gotoxy(20,24);
cout<<"->2.Show All Student Information\n";
gotoxy(20,26);
cout<<"->3.Search Single Student Information";
gotoxy(20,28);
cout<<"->4.Show All Programmer";
gotoxy(20,30);
cout<<"->5.Exit\n";
gotoxy(20,32);
cout<<"\nPlease Choose From MENU List-->";
choic=getch();
switch(choic)
{
case '1':
clrscr();
gotoxy(20,20);
Record();
break;
case '2':
clrscr();
gotoxy(20,20);
Show();
break;
case '3':
clrscr();
gotoxy(20,20);
Search();
break;
case '4':
clrscr();
programmers();
break;
case '5':
clrscr();
exit(1);
break;
default:
clrscr();
gotoxy(15,40);
cout<<"\n\t\t#==========================#";
cout<<"\n\t\t# Sorry! Incorrect Choice! #";
cout<<"\n\t\t#==========================#";
}
cout<<"\n\t\t ______________________________________________";
cout<<"\n\t\t| Do You Want Go To Main MENU? Please Click R: |";
cout<<"\n\t\t|______________________________________________|";
i=getch();
}
while(i=='r'||i=='R');
getch();
}