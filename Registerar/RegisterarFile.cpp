//This program developed for Dilla university new campus Registrar Office

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<process.h>

struct student{
		char name[15],fname[15],gname[15];//   all these are the data
		char depp[30],sex,ch,ID[10];       // members of student class
		int age,DD,MM,YY,EHEECE;         //
		float p_result,GPA;                     //
		int band,choice1,choice2,choice3;  //
		int choice4,choice5,choice6,choice7;//
					 }
			 stud[300];
		int fn=0;

void Record();
void Show();
void display();
void Search();//to search a specific student data
void programmers();


		 void display()
		{gotoxy(24,24);
		cout<<"Registration Successfull!\n\n"
			  <<"Starting today you are Dilla University";}



void Record()///this function accepts student data
{
  clrscr();
  int m,h=0,k,u;
  char op;
  fstream d;

cout<<"\nHow many students do you want to register?  ";
cin>>m;
d.open("c:\Nofiles.txt",ios::in|ios::out);//to count the no of files written
u=m;
while(!d.eof())
d>>h;
k=u+h;
d.close();
d.open("c:\Nofiles.txt",ios::out|ios::trunc); //to write the no of files counted
d<<k;
d.close();

ofstream file;
  file.open("c:\student.txt",ios::out|ios::app);
  cout<<"\nyou are registering "<<m<<"student data"<<endl<<endl;
	for(int j=0;j<m;j++)
  {
	cout<<"1.New student data\n\n";
	cout<<"2.Existing student data\n\n";
	cout<<"select your choice\n\n";
	op=getch();
	if(op=='1')
	 {


				  cout<<"\n\nEnter First name of student "<<j+1<<endl;
				  cin>>stud[j].name;
				  file<<stud[j].name<<" ";
				  cout<<"\n\nEnter Father name ";
				  cin>>stud[j].fname;
				  file<<stud[j].fname<<" ";
				  cout<<"\n\nEnter Grandfather name ";
				  cin>>stud[j].gname;
				  file<<stud[j].gname<<endl;
				  cout<<"\n\nEnter sex  M or F ";
				  cin>>stud[j].sex;
				  file<<stud[j].sex<<endl;
				  do
				  {
				  cout<<"\n\nEnter Date of Birth in ETH calender the form DD/MM/YY ";
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
				  while(stud[j].DD>31||stud[j].DD<1||stud[j].ch!='/'||stud[j].MM>13||stud[j].MM<1||stud[j].YY>1983);
				  cout<<"\n\nEnter the Age ";
					 cin>>stud[j].age;
				  file<<stud[j].age<<endl;

				  cout<<"\n\nEnter EHEECE exam result ";
				  cin>>stud[j].EHEECE;
				  file<<stud[j].EHEECE<<endl;
				  cout<<"\n\nEnter Preparatory Transcript Average ";
				  cin>>stud[j].p_result;
				  file<<stud[j].p_result<<endl;
				  cout<<"\n\nEnter the ID number ";
				  cin>>stud[j].ID;
				  file<<stud[j].ID<<endl;
				  stud[j].GPA=0.00;
				  file<<stud[j].GPA<<'\n';

				cout<<"\n\nSelect your band:"
				 <<"\n\n\t\t1.Computitional Science"
				 <<"\n\n\t\t2.Engineering and Technology";
				  cin>>stud[j].band;
				  if(stud[j].band==1)
					{cout<<"\n\nSelect What you want to study in order, Example 4 6 2 3 1 5 7"
				  <<"\n\n\t\t1.Amharic"
				  <<"\n\n\t\t2.Biology"
				  <<"\n\n\t\t3.Mathmatics"
				  <<"\n\n\t\t4.Phisics"
				  <<"\n\n\t\t5.Chemistry"
				  <<"\n\n\t\t6.English"
				  <<"\n\n\t\t7.Phisical Education\n\n:";
					 cin>>stud[j].choice1>>stud[j].choice2>>stud[j].choice3
				 >>stud[j].choice4>>stud[j].choice5>>stud[j].choice6
				 >>stud[j].choice7;
			  //		 delay(800);
					clrscr();
					gotoxy(24,24);
					cout<<"Processing please wait.....";
			//		delay(2000);
					clrscr();
					display();
				if(stud[j].EHEECE + stud[j].p_result > 300)
					{ if(stud[j].choice1==1)
				{strcpy(stud[j].depp,"Amharic");
				 cout<<" Amharic department student";

				 file<<stud[j].depp<<endl;

				 }
				else if(stud[j].choice1==2)
				{strcpy(stud[j].depp,"Biology");
				 cout<<" Biology department student";
				file<<stud[j].depp<<endl;
				 }
				else if(stud[j].choice1==3)
				{strcpy(stud[j].depp,"Mathmatics");
				cout<<" Mathmatics department student";
				file<<stud[j].depp<<endl;

				 }
				else if(stud[j].choice1==4)
				{strcpy(stud[j].depp,"Physics");
				 cout<<" Physics department student";
				 file<<stud[j].depp<<endl;

				 }
				else if(stud[j].choice1==5)
				{strcpy(stud[j].depp,"Chemistry");
				 cout<<" Chemistry department student";
				 file<<stud[j].depp<<endl;

				 }
				else if(stud[j].choice1==6)
				{strcpy(stud[j].depp,"English");
				cout<<" English department student";
				 file<<stud[j].depp<<endl;
					 }
				else
				{strcpy(stud[j].depp,"Physical Education");
				 cout<<" Phisical Education department student";
				 file<<stud[j].depp<<endl;
					 }}
					else
					{
					if(stud[j].choice2==1)
				{strcpy(stud[j].depp,"Amharic");
				cout<<" Amharic department student";
				file<<stud[j].depp<<endl;
					 }
				else if(stud[j].choice2==2)
				{strcpy(stud[j].depp,"Biology");
				 cout<<" Biology department student";
				 file<<stud[j].depp<<endl;
					 }
				else if(stud[j].choice2==3)
				{strcpy(stud[j].depp,"Mathmatics");
				 cout<<" Mathatics department student";
				 file<<stud[j].depp<<endl;
					 }
				else if(stud[j].choice2==4)
				{strcpy(stud[j].depp,"Phtsics");
				 cout<<" Physics department student";
				 file<<stud[j].depp<<endl;
								 }
				else if(stud[j].choice2==5)
				{strcpy(stud[j].depp,"Chemistry");
				 cout<<" Chemistry department student";
				 file<<stud[j].depp<<endl;
								 }
				else if(stud[j].choice2==6)
				{strcpy(stud[j].depp,"English");
				 cout<<" English department student";
				 file<<stud[j].depp<<endl;
								 }
				else
				{strcpy(stud[j].depp,"Physical Education");
				 cout<<" Physical Education department student";
				 file<<stud[j].depp<<endl;
						 }
					}  //second if statment
				}///first if statment

					 else
				{
		 //		delay(800);
					clrscr();
					gotoxy(24,24);
					cout<<"Processing please wait.....";
			  //		delay(2000);
					clrscr();
					display();
				strcpy(stud[j].depp,"ComputerScience");
					 file<<stud[j].depp<<endl;
					 cout<<" Computer Science department student";
				}
				 getch();

				  cout<<endl;
					clrscr();
					gotoxy(20,20);
					cout<<"Registration successful! "<<"you registered "<<k<<"student data\n";
					 }
					else
					{cout<<"\n\nEnter First name of student "<<j+1<<endl;
				  cin>>stud[j].name;
				  file<<stud[j].name<<" ";
				  cout<<"\n\nEnter Father name ";
				  cin>>stud[j].fname;
				  file<<stud[j].fname<<" ";
				  cout<<"\n\nEnter Grandfather name ";
				  cin>>stud[j].gname;
				  file<<stud[j].gname<<endl;
				  cout<<"\n\nEnter sex  M or F ";
				  cin>>stud[j].sex;
				  file<<stud[j].sex<<endl;
				  do
				  {
				  cout<<"\n\nEnter Date of Birth in ETH calender the form DD/MM/YY ";
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
				  while(stud[j].DD>31||stud[j].DD<1||stud[j].ch!='/'||stud[j].MM>13||stud[j].MM<1||stud[j].YY>1983);
				  cout<<"\n\nEnter the Age ";
					 cin>>stud[j].age;
				  file<<stud[j].age<<endl;

				  cout<<"\n\nEnter EHEECE exam result ";
				  cin>>stud[j].EHEECE;
				  file<<stud[j].EHEECE<<endl;
				  cout<<"\n\nEnter Preparatory Transcript Average ";
				  cin>>stud[j].p_result;
				  file<<stud[j].p_result<<endl;
				  cout<<"\n\nEnter the ID number ";
				  cin>>stud[j].ID;
				  file<<stud[j].ID<<endl;
				  cout<<"Enter GPA "<<endl;
				  cin>>stud[j].GPA;
				  file<<stud[j].GPA<<endl;
				  file<<"ComputerScience";
				  clrscr();
					gotoxy(20,20);
					cout<<"Registration successful! "<<"Total records= "<<k;

				  }  }
					 file.close();
					 }


void Show() // to read data from file and display
{
	 int f=0;
	ifstream o;
o.open("c:\student.txt",ios::in|ios::end|ios::beg);
while(!o.eof())
{
o>>stud[f].name;
cout<<"\nFull name: "<<stud[f].name<<" ";
o>>stud[f].fname;
cout<<stud[f].fname<<" ";
o>>stud[f].gname;
cout<<stud[f].gname<<endl;
o>>stud[f].sex;
cout<<"\nSex: "<<stud[f].sex<<endl;
o>>stud[f].DD;
cout<<"\nBirth date: "<<stud[f].DD;
o>>stud[f].ch;
cout<<stud[f].ch;
o>>stud[f].MM;
cout<<stud[f].MM;
o>>stud[f].ch;
cout<<stud[f].ch;
o>>stud[f].YY;
cout<<stud[f].YY<<endl;
o>>stud[f].age;
cout<<"\nAge: "<<stud[f].age<<endl;
o>>stud[f].EHEECE;
cout<<"\Enterance: "<<stud[f].EHEECE<<endl;
o>>stud[f].p_result;
cout<<"\nPreparatory result: "<<stud[f].p_result<<endl;
o>>stud[f].ID;
cout<<"\nID: "<<stud[f].ID<<endl;
o>>stud[f].GPA;
cout<<"\nGPA: "<<stud[f].GPA<<'\n';
o>>stud[f].depp;
cout<<"\nDept: "<<stud[f].depp<<endl;
f++;
getch();
}

o.close();
}



void Search() //to search a specific student data
{
int c=0,p,h=0,f;
char k[8],v;
fstream d;
d.open("c:\Nofiles.txt",ios::in|ios::out);
while(!d.eof())
d>>h;
p=h;
d.close();
ifstream off;
do{
clrscr();
gotoxy(20,20);
cout<<"\n\nId of a student you want to search: ";
cin>>k;
off.open("c:\student.txt",ios::in);
for(f=0;f<p;f++)
{
off>>stud[f].name;
off>>stud[f].fname;
off>>stud[f].gname;
off>>stud[f].sex;
off>>stud[f].DD;
off>>stud[f].ch;
off>>stud[f].MM;
off>>stud[f].ch;
off>>stud[f].YY;
off>>stud[f].age;
off>>stud[f].EHEECE;
off>>stud[f].p_result;
off>>stud[f].ID;
if(strcmp(k,stud[f].ID)==0)
{
clrscr();
cout<<"\nFull name: "<<stud[f].name<<" ";
cout<<stud[f].fname<<" ";
cout<<stud[f].gname<<"\n";
cout<<"sex: "<<stud[f].sex<<endl;
cout<<"\nBirth date: "<<stud[f].DD;
cout<<stud[f].ch;
cout<<stud[f].MM;
cout<<stud[f].ch;
cout<<stud[f].YY<<'\n';
cout<<"Age: "<<stud[f].age<<endl;
cout<<"Entrance result: "<<stud[f].EHEECE<<endl;
cout<<"Preparatory result: "<<stud[f].p_result<<endl;
cout<<"ID: "<<stud[f].ID<<endl;
off>>stud[f].GPA;
cout<<"GPA: "<<stud[f].GPA<<endl;
off>>stud[f].depp;
cout<<"Department: "<<stud[f].depp<<endl;
c=1;
}
off>>stud[f].GPA;
off>>stud[f].depp;
}
char g;
if(c==0)
{
cout<<"The id doesn't exist would you like to try again?\n";
cin>>v;
}
}while(v=='y'||v=='Y');
}


void programmers()
{

clrscr();
cout<<"Programmers:\n\n";
cout<<"1.TIJANY MOHAMMED         RCS-146/11"<<endl;
cout<<"2.HABTAMU ALEMAYEHU       RCS-053/11"<<endl;
cout<<"3.ADANE  ALARO            RCS-004/11"<<endl;
cout<<"4.DANIEL TOLERA           RCS-028/11"<<endl;
cout<<"5.ALEFE  WASIHUN          RCS-009/11"<<endl;
cout<<"6.BEREKET YOHANNES        RCS-021/11"<<endl;
}


void main()
{
clrscr();
student Order;

	char ch;
	char option;
	gotoxy(18,20);
	cout<<"\n            Welcome to Dilla University Registrar Office ";
	gotoxy(22,25);
	cout<<"    Press any button to continue...";
	getch();
do{
	clrscr();
	gotoxy(24,20);
	cout<<"What do you like to do?\n\n ";
	gotoxy(20,22);
	cout<<"1.Insert new student information:\n\n";
	gotoxy(20,24);
	cout<<"2.show all student information: \n\n";
	gotoxy(20,26);
	cout<<"3.search a specifioc student information:\n\n";
	gotoxy(20,28);
	cout<<"4.exit:\n\n";
	gotoxy(20,30);
	cout<<"5.Programmers:\n\n";
	gotoxy(20,32);
	cout<<" select a number of your choice:  ";
	option=getch();
	switch(option)
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
	exit(1);
	break;
	case '5':
	clrscr();
	programmers();
	break;
	default:
	clrscr();
	gotoxy(15,40);
	cout<<"\nIncorrect choice!\n\n";
	}
	cout<<"\n      Do you want to go to the main menu?Y/N";
	ch=getch();
	}while(ch=='y'||ch=='Y');
getch();
}