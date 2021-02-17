   #include<iostream>
  #include<fstream>
      // #include<conio>
       #include<process>
       #include<ctype>
       #include<string>
       #include<dos>
       #include<time>

			   struct dorm
			   {
			   char name_org[24];
			   char name_stud[24];
                         char name_dept[24];
                        char name_dorm[24];


			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;


			   int year;
                           int ID;
                           int block_num;
                              int dorm_num;
			   dorm*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       dorm*strat_ptr=NULL;
	       dorm*temp=new dorm;
			void register_info();
			//void register_dorm();
	              void dorm_system();
			int search();
			void display();
void developer();

////////////////////////////////////////////////////////////////////////
	 void register_info() // record existing student and dorm information;
	   {
ofstream file;
  file.open("D:\student.txt",ios::out|ios::app|ios::trunc);

	    dorm date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				dorm *temp2;
				dorm *temp=new dorm;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\tname of organization ";
      cin>>temp->name_org;
 file<<temp->name_org<<" ";
      cout<<"\n\n\t name of student ";
      cin>>temp->name_stud;
 file<<temp->name_stud<<" ";
cout<<"\n\n\t name of department ";
      cin>>temp->name_dept;
 file<<temp->name_dept<<" ";
      cout<<"\n\n\t enter ID number";
      cin>>temp->ID;
 file<<temp->ID<<" ";
 cout<<"\n\n\t enter class year";
      cin>>temp->year;
 file<<temp->year<<" ";
file<<temp->name_org<<" ";
      cout<<"\n\n\t name of dorm ";
      cin>>temp->name_dorm;
 file<<temp->name_dorm<<" ";
cout<<"\n\n\t enter Block number ";
      cin>>temp->block_num;
 file<<temp->block_num<<" ";
      cout<<"\n\n\t dorm number";
      cin>>temp->dorm_num;
 file<<temp->dorm_num<<" ";




			temp->nxt=NULL;
			  if(strat_ptr==NULL)
			  {
			   strat_ptr=temp;
			   temp->nxt=strat_ptr;
			      }

				   else

		       temp2=strat_ptr;
		      while(temp2->nxt!=NULL)
		    {
		 temp2=temp2->nxt;
		  }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
	   }





  void dorm_system()
  {

dorm *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the ID number \n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->ID)
   {ifstream of;
       of.open("D:\DOR.txt",ios::in|ios::end|ios::beg);
cout<<"\n\n\tdorm  information ";
cout<<"Name of organization:"<<temp->name_org<<"\n\n";
cout<<"name department:"<<temp->name_dept<<"\n\n";

cout<<"dorm name:"<<temp->name_dorm<<"\n\n";

cout<<"block number:"<<temp->block_num<<"\n\n";

cout<<"dorm number:"<<temp->dorm_num<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:information  not found!!!";


//clrscr();
 }







int search()
{

dorm *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the ID number \n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->ID)
   {
cout<<"\n\n\tdorm  information ";
cout<<"Name of organization:"<<temp->name_org<<"\n\n";
cout<<"name department:"<<temp->name_dept<<"\n\n";
cout<<"dorm name:"<<temp->name_dorm<<"\n\n";
cout<<"block number:"<<temp->block_num<<"\n\n";
cout<<"dorm number:"<<temp->dorm_num<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:information  not found!!!";

return temp->ID;
//clrscr();
 }


void developer()
{
cout<<"\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n1.dddddddd                               @";
cout<<"\n\n2.dddddddd                               @";
cout<<"\n\n3.dddddddd                               @";
cout<<"\n\n4.dddddddd                               @";
cout<<"\n\n5.dddddddd                               @";
cout<<"\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
}


  void display()
{
temp=strat_ptr;

do
{
if(temp==NULL)
{
cout<<"\n\n\tEnd of list\n\n";

}
else
{

cout<<"\n\n\tdorm  information ";
cout<<"Name of organization:"<<temp->name_org<<"\n\n";
cout<<"name department:"<<temp->name_dept<<"\n\n";

cout<<"dorm name:"<<temp->name_dorm<<"\n\n";
cout<<"block number:"<<temp->block_num<<"\n\n";
cout<<"dorm number:"<<temp->dorm_num<<"\n\n";
cout<<endl;
temp=temp->nxt;
}
}
while(temp!=NULL);

}
int main()
{
clrscr();
int n;
char ans,x;

c:  clrscr();
	 //gotoxy(26,28);

cout<<"WELCOME TO DORM  SYSTEM \n\n\n";

delay(1000);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@                 MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  1.register dorm and student information      @";
cout<<"\n\n\t@  2.dorm system                                @";
cout<<"\n\n\t@  3.Display information                        @";
cout<<"\n\n\t@  4.Search student  inf                        @";
cout<<"\n\n\t@   p.programmer                                @";
cout<<"\n\n\t@  8.Exit                                       @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  Select your choice                          @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
gotoxy(32,30);
cin>>x;
switch(x)
{
case '1':
gotoxy(12,12);//    position cursor text window.
register_info();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
  goto c;//transfer controll goto key word.
else if(ans=='n')
   exit(0);
break;


case '2':
clrscr();
gotoxy(12,12);
dorm_system();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
 if(ans=='y')
 goto c;
 else if(ans=='n')
exit(7);
break;

  case '3':
clrscr();
gotoxy(12,12);
display();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

clrscr();
if(ans=='y')
goto c;
else if(ans=='n')
exit(7);
break;
case '4':
clrscr();
gotoxy(12,12);
search();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

if(ans=='y')
goto c;
else if(ans=='n')
exit(8);
break;

case 'p':
clrscr();
gotoxy(12,12);
developer();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

clrscr();
if(ans=='y')
goto c;
else if(ans=='n')
exit(7);
break;


default://
clrscr();
cout<<"\n\n\tError choise! ";
}
getch();
clrscr();
cout<<"\n\n\tDo you want to continue? (y/n) ";
cin>>ans;
if(ans=='y');
 goto c;//transfer control.
}
