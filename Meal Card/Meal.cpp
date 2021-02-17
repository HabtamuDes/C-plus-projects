//This program developed for Dilla university semera campus meal card system

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
struct student
{
		char name[15],fname[15],sex[5];                            //   all these are the data
		char ID[10],department[30];                                  // members of student class
		int classyear,accadamicyear;
				 }meal[300];

void Record();
void Show();
void tick();
//void delete();
void programmers();

				void Record()                      ///this function accepts student data
		  {
  clrscr();
  int m,h=0,k,u;
  char op;
  fstream ml;
cout<<"\nHow many students do you want to register?  ";
cin>>m;
ml.open("Numberoffiles.txt",ios::in|ios::out);//to count the no of files written
u=m;
while(!ml.eof())
ml>>h;
k=u+h;
ml.close();
ml.open("Numberoffiles.txt",ios::out|ios::trunc); //to write the no of files counted // trunc-> If the file already existed it is erased
ml<<k;
ml.close();
ofstream file;
  file.open("mealcardsystem.txt",ios::out|ios::app);   // app->Every output is appended at the end of file
  cout<<"\n\t\t\tWELCOME TO MELE CARD REGSTERATION FORM\nknow you can enter  "<<m<<" student data"<<endl<<endl;
	for(int j=0;j<m;j++)
  {
  cout<<"select your choice\n\n";
	cout<<"1.register New student data\n\n";
	cout<<"2.Existing student data\n\n";
  op=getch();
	if(op=='1')
	{
	 cout<<"\nEnter First name of student "<<endl;
				  cin>>meal[j].name;
				  file<<meal[j].name<<" ";
				  cout<<"\nEnter Father name ";
				  cin>>meal[j].fname;
				  file<<meal[j].fname<<" "<<endl;
				  cout<<"Enter sex  M or F ";
				  cin>>meal[j].sex;
				  file<<meal[j].sex<<endl;
				  cout<<"Enter ID number ";
				  cin>>meal[j].ID;
				  file<<meal[j].ID<<endl;
				  cout<<"Enter Department ";
				  cin>>meal[j].department;
				  file<<meal[j].department<<endl;
				  cout<<"Enter class year ";
				  cin>>meal[j].classyear;
				  file<<meal[j].classyear<<endl;
				  cout<<"Enter accadamicyear ";
				  cin>>meal[j].accadamicyear;
				  file<<meal[j].accadamicyear<<endl;
					clrscr();
					gotoxy (1,1);
		cout<<"Meal card Registration Successfull!\n\n"
			  <<"Starting today you can get caffe service\n\n";
					 }
					 }
					 file.close();
					 }

				 void Show() // to read data from file and display
		  {
	 ifstream off;
	 int f,h,s=0,k,y=0;
	 fstream ml;
	 ml.open("Numberoffiles.txt",ios::in|ios::out);
while(!ml.eof())
ml>>h;
k=h;
ml.close();

		ifstream o,of;
		 of.open("mealcardsystem.txt",ios::in|ios::end|ios::beg);
		 while(!of.eof())
		 {
of>>meal[s].name;
of>>meal[s].fname;
of>>meal[s].sex;
of>>meal[s].ID;
of>>meal[s].department;
of>>meal[s].classyear;
of>>meal[s].accadamicyear;
s++;
y++;
}
of.close();
if(y<=1)
{
clrscr();
gotoxy(20,20);
cout<<"THEIR IS NO REGISTERD STUDENT IN THE MEAL CARD SYSTEM \n\n";
}
else
{
o.open("mealcardsystem.txt",ios::in|ios::end|ios::beg);
for(f=0;f<k;f++)
{
cout<<"***********************************"<<endl;
o>>meal[f].name;
cout<<"\nFull name: "<<meal[f].name<<" ";
o>>meal[f].fname;
cout<<meal[f].fname<<endl;
cout<<"                                    |";
o>>meal[f].sex;
cout<<"\nSex: "<<meal[f].sex<<endl;
cout<<"                                    |";
o>>meal[f].ID;
cout<<"\nID number: "<<meal[f].ID<<endl;
cout<<"                                    |";
o>>meal[f].department;
cout<<"\nDepartment: "<<meal[f].department<<endl;
cout<<"                                    |";
o>>meal[f].classyear;
cout<<"\nclass year: "<<meal[f].classyear<<endl;
cout<<"                                    |";
o>>meal[f].accadamicyear;
cout<<"\naccadamicyear: "<<meal[f].accadamicyear<<endl;
cout<<"*************************************"<<endl;
getch();
}
o.close();
}
}

void tick()                //to tick the meal card
{
int c=0,p,h=0,f;
char k[8],v;
fstream ml;
ml.open("Numberoffiles.txt",ios::in|ios::out);
while(!ml.eof())
ml>>h;
p=h;
ml.close();
ifstream src;
do{
clrscr();
gotoxy(20,20);
cout<<"\n ENTER MEAL CARD NUMBER OF THE STUDENT YOU WANT TO TICK: ";
cin>>k;
src.open("mealcardsystem.txt",ios::in);
for(f=0;f<p;f++)
{
src>>meal[f].name;
src>>meal[f].fname;
src>>meal[f].sex;
src>>meal[f].ID;
src>>meal[f].department;
src>>meal[f].classyear;
src>>meal[f].accadamicyear;
if(strcmp(k,meal[f].ID)==0)
{
clrscr();
cout<<"*******************************"<<endl;
cout<<"\nFull name: "<<meal[f].name<<" ";
cout<<meal[f].fname<<endl;
cout<<"*******************************"<<endl;
cout<<"                                    |";
cout<<"Sex: "<<meal[f].sex<<endl;
cout<<"                                    |";
cout<<"ID number: "<<meal[f].ID<<endl;
cout<<"                                    |";
cout<<"Department: "<<meal[f].department<<endl;
cout<<"                                    |";
cout<<"class year: "<<meal[f].classyear<<endl;
cout<<"                                    |";
cout<<"accadamicyear: "<<meal[f].accadamicyear<<endl;
cout<<"*************************************"<<endl;
cout<<'\n';
cout<<"VALID MEAL CARD NUMBER PERMISABLE TO USE CAFFE\n HAVE A NICE FOOD!!! "<<endl;

c=1;
}
}
if (c==0)
{
clrscr();
cout<<"The MEAL card number doesn exist \n\t\n\tIT IS INVALID!!!!\n\n you have no permission to use caffe \n\nwould you like to try again?\n";
cin>>v;
}
}while(v=='y'||v=='Y');
}

/*void delete()                //to delete a specific student data
{
int c=0,t,h=0,f;
char choos;
fstream ml;
ml.open("Nofiles.txt",ios::in|ios::out);
while(!ml.eof())
ml>>h;
t=h;
ml.close();
ifstream off;
do
{
clrscr();
gotoxy(20,20);
cout<<"\n Enter millID number that you want to delete : ";
cin>>k;
off.open("meal.txt",ios::in);
for(f=0;f<t;f++)
{
off>>meal[f].name;
off>>meal[f].fname;
off>>meal[f].sex;
off>>meal[f].ID;
off>>meal[f].department;
off>>meal[f].classyear;
off>>meal[f].accadamicyear;
off>>meal[f].mealcardno;
{
delete (meal[f].name);
delete (meal[f].fname);
delete (meal[f].sex);
delete (meal[f].ID);
delete (meal[f].department);
delete (meal[f].classyear);
delete (meal[f].accadamicyear);
delete (meal[f].mealcardno);
c=1;
}
}
if (c==0)
{
cout<<"NO ONE IS REGISTERD IN THIS ID NUMBER\n\twould you like to try again?\n";
cin>>choos;
}
}while(v=='y'||v=='Y');
}   */

  void programmers()
{
clrscr();
cout<<"\n\n\n\t\t\tMEAL CARD SYSTEM";
cout<<"\n\n\n\n";
cout<<"\n\t\t\t###################################";
cout<<"\n\t\t\t#                                 #";
cout<<"\n\t\t\t#          Group Member           #";
cout<<"\n\t\t\t#      Name              Id no    #";
cout<<"\n\t\t\t# 5.HAIDER  KEDIR       RCS055/11 #";
cout<<"\n\t\t\t# 1.ADEM    BERHANE     RCS005/11 #";
cout<<"\n\t\t\t# 2.AIESHA  ALI         RCS007/11 #";
cout<<"\n\t\t\t# 3.BEREKET HABTAMU     RCS020/11 #";
cout<<"\n\t\t\t# 4.ELHAM   NURDEN      RCS034/11 #";
cout<<"\n\t\t\t# 6.HIKMA   KEDIR       RCS063/11 #";
cout<<"\n\t\t\t# 7.ZEYNEBA ABEBE       RCS161/11 #";
cout<<"\n\t\t\t#                                 #";
cout<<"\n\t\t\t#      DILLA UNIVERSITY           #";
cout<<"\n\t\t\t#   COMPUTER SCIENCE DEPARTMENT   #";
cout<<"\n\t\t\t#                        2005 E.C #";
cout<<"\n\t\t\t###################################";
}
void main()
{
clrscr();
student Order;

	char ch;
	char option;
	gotoxy(18,2);
	cout<<"\n            WELCOM TO DILLA UNIVERSITY SEMERA CAMPUS MEAL CARD SYSTEM ";
	gotoxy(22,4);
	cout<<"    To continue Press your best key...";
	getch();
do{
	clrscr();
	gotoxy(10,2);
	cout<<"What do you Want to perform?\n\n ";
	gotoxy(10,4);
	cout<<"1.Insert new student information in to meal card system:\n\n";
	gotoxy(10,6);
	cout<<"2.show all student information: \n\n";
	gotoxy(10,8);
	cout<<"3.ticking the meal card :\n\n";
	gotoxy(10,10);
	cout<<"4.exit:\n\n";
	gotoxy(10,12);
  //	void delete();
	cout<<"5.Delete student from meal card system:\n\n";
	gotoxy(10,14);
	cout<<"6.Programmers:\n\n";
	gotoxy(10,16);
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
	tick();
	break;
	case '4':
	clrscr();
	exit(1);
	break;
	case '5':
	clrscr();
	//gotoxy(20,20);
  //	void delete();
	break;
	case '6':
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
