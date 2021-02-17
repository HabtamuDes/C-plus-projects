   #include<iostream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>

			   struct schedule
			   {
			   char name_instr[24];
			   char name_subj[24];
                          char name_dep[24];
                          char org_name[24];
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			   date time;
			   int room;
                           int section;

		 
			   char ch;
			   int date;
                          int code;

			   
			   schedule*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       schedule*strat_ptr=NULL;
	       schedule*temp=new schedule;
			void register_sch();
			
	              void delete_sch();
			int search();
			void display();
			 
////////////////////////////////////////////////////////////////////////
	 void register_sch() // record scheduling  information;
	   {

	    schedule date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				schedule *temp2;
				schedule *temp=new schedule;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
cout<<"\n\n\t name of organization ";
      cin>>temp->org_name;
cout<<"\n\n\tname of department ";
      cin>>temp->name_dep;
      cout<<"\n\n\tname of instructor ";
      cin>>temp->name_instr;

cout<<"\n\n\tname of course ";
      cin>>temp->name_subj;
cout<<"\n\n\t course code ";
      cin>>temp->code;
      
   
      cout<<"\n\n\tenter section";
      cin>>temp->section;
cout<<"\n\n\tenter class room number";
      cin>>temp->room;
cout<<"eneter time in form of dd:dfd";
cin>>temp->date;
	      
		
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

		

	   

  




void delete_sch()
{schedule *temp;
temp=strat_ptr;
 int found=0;
float co;
cout<<"\nEnter the code to search\n";
cin>>co;

 while(temp!=NULL)
{
  if(co==temp->code)
   {
 cout<<"\n\n\tdata is deleted!";
delete temp;

   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:information not found!!!";





   
     
      
      }


int search()
{

schedule *temp;
temp=strat_ptr;
 int found=0;
float co;
cout<<"\nEnter the code to search\n";
cin>>co;

 while(temp!=NULL)
{
  if(co==temp->code)
   {
cout<<"\n\n\tnameofdepartment instructor course  code sect room number time\n\n";
      cout<< "\t"<<temp->name_dep<<"\t" <<temp->name_instr<<"\t"<<  temp->name_subj<<"\t"
 <<temp->code<<"\t"<<temp->section<<"\t" <<temp->room<<"\t"<<temp->date<<"\n";


   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:information not found!!!";

return temp->code;
//clrscr();
 }
//else

//cout<<"not found\n";
//}
//temp=temp->nxt;

void developer()
{ 
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
cout<<"GROUP MEMBER                          ";
cout<<"\n\n1.ADENEW ADISSE  RCS 006/11       ";
cout<<"\n\n2 FIRAOL TESFAYE RCS 042/11       ";
cout<<"\n\n3 MEBRATU ALEMU  RCS 075/11       ";
cout<<"\n\n4 MELAKU GUCHI   RCS 078/11       ";
cout<<"\n\n5 MELESE ARAGAW  RCS 079/11       ";
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";

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
{cout<<"\n\n\tnameofdepartment instructor course  code sect room number time\n\n";
      cout<< "\t"<<temp->name_dep<<"\t\t" <<temp->name_instr<<"\t\t"<<  temp->name_subj<<"\t"
 <<temp->code<<"\t"<<temp->section<<"\t" <<temp->room<<"\t"<<temp->date<<"\n";

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

cout<<"WELCOME TO scheduling  SYSTEM \n\n\n";

//delay(500);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@                 MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  1.register schedule                          @";
cout<<"\n\n\t@  2.Display information                        @";
cout<<"\n\n\t@  3.Search  information                        @";
cout<<"\n\n\t@  4.delete  information                        @";
cout<<"\n\t@   p.programmer                                 @";
cout<<"\n\n\t@  5.Exit                                       @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  Select your choise                          @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
gotoxy(32,30);
cin>>x;
switch(x)
{
case '1':
gotoxy(12,12);//    position cursor text window.
register_sch();
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
display();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

clrscr();
if(ans=='y')
goto c;
else if(ans=='n')
exit(7);
break;
case '3':
clrscr();
gotoxy(12,12);
search();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

if(ans=='y')
goto c;
else if(ans=='n')
exit(5);
break;
case '4':
clrscr();
gotoxy(12,12);
delete_sch();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

if(ans=='y')
goto c;
else if(ans=='n')
exit(5);
break;
case 'p':
clrscr();
gotoxy(12,12);
developer();

cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

if(ans=='y')
goto c;
else if(ans=='n')
exit(5);
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
