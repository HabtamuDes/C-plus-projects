   #include<iostream.h>
  #include<fstream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>

			   struct bank
			   {
			   char name_bank[24];
			   char name_accounter[24];
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			
			
			   int account_num;
                           int deposit;
			   bank*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       bank*strat_ptr=NULL;
	       bank*temp=new bank;
			void account_create();
			void withdrawl();
	
			int search();
			void display();

		
////////////////////////////////////////////////////////////////////////
	 void account_create() // record existing bank information;
	   {
ofstream file;
  file.open("D:\info.txt",ios::out|ios::app|ios::trunc);

	    bank date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				bank *temp2;
				bank *temp=new bank;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\tname of bank ";
      cin>>temp->name_bank;
 file<<temp->name_bank<<" ";
      cout<<"\n\n\t name of accounter ";
      cin>>temp->name_accounter;
 file<<temp->name_accounter<<" ";
      cout<<"\n\n\t enter account number";
      cin>>temp->account_num;
 file<<temp->account_num<<" ";
 cout<<"\n\n\t enter deposit money";
      cin>>temp->deposit;
 file<<temp->deposit<<" ";
	      if(temp->deposit<50)
		{
		   cout<<"\n\n\tincorrect input!";
		   delete temp;
		   }
		   

		      else
			 {
		


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

	 }


  

  void withdrawl()
  {

bank *temp;
temp=strat_ptr;
 int found=0;
float co;
cout<<"\nEnter the account number  to withdwawl\n";
cin>>co;

 while(temp!=NULL)
{
  if(co==temp->account_num)
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

bank *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the account number  search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->account_num)
   {
cout<<"\n\n\tbank information ";
cout<<"Name:"<<temp->name_bank<<"\n\n";
cout<<"accounter name:"<<temp->name_accounter<<"\n\n";
cout<<"account number:"<<temp->account_num<<"\n\n";
cout<<"number of money:"<<temp->deposit<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:information  not found!!!";

return temp->account_num;
//clrscr();
 }
//else

//cout<<"not found\n";
//}
//temp=temp->nxt;






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

cout<<"\n\n\tbank information ";
cout<<"Name:"<<temp->name_bank<<"\n\n";
cout<<"accounter name:"<<temp->name_accounter<<"\n\n";
cout<<"account number:"<<temp->account_num<<"\n\n";
cout<<"number of money:"<<temp->deposit<<"\n\n";
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

cout<<"WELCOME TO bank  SYSTEM \n\n\n";

delay(1000);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@                 MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  1.create account                             @";
cout<<"\n\n\t@  2.withdrwal                                  @";
cout<<"\n\n\t@  3.Display information                        @";
cout<<"\n\n\t@  4.Search bank inf                            @";
cout<<"\n\n\t@   p.programmer                                 @";
cout<<"\n\n\t@  8.Exit                                       @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  Select your choise                          @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
gotoxy(32,30);
cin>>x;
switch(x)
{
case '1':
gotoxy(12,12);//    position cursor text window.
account_create();
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
withdrawl();
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
