   #include<iostream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>

			   struct water
			   {
			   char name_kebele[24];
			   
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			   int watersuply_d;
			   int watersuply_m;
			   int watersuply_y;
			   char ch;
			   
			   int keb_num;
			
			   water*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       water*strat_ptr=NULL;
	       water*temp=new water;
			void add_info();
		
			int search();
			void display();
			
////////////////////////////////////////////////////////////////////////
	 void add_info() // record existing supermarket information;
	   {

	    water date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				water *temp2;
				water *temp=new water;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\tname of kebele ";
      cin>>temp->name_kebele;
     
      cout<<"\n\n\t enter water supply  date of item ";
      cin>>temp->watersuply_d;
      cin>>temp->ch;
      cin>>temp->watersuply_m;
      cin>>temp->ch;
      cin>>temp->watersuply_y;
      
      cout<<"\n\n\tkebele number";
      cin>>temp->keb_num;


	      


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

	

  
int search()
{

water *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the kebele number to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->keb_num)
   {
cout<<"\n\n\twater suply information ";
cout<<"Name of kebele:"<<temp->name_kebele<<"\n\n";
cout<<"water suply date:"<<temp->watersuply_d<<"/"<<temp->watersuply_m<<"/"<<temp->watersuply_y<<"\n\n";
cout<<"kebele number:"<<temp->keb_num<<"\n\n";

   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:information  not found!!!";

return temp->keb_num;
//clrscr();
 }
//else

//cout<<"not found\n";
//}
//temp=temp->nxt;

void developer()
{
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"GROUP MEMBER                       ";
cout<<"\n\n1.likelesh kebede              ";
cout<<"\n\n2.lidiya terefe                ";
cout<<"\n\n3.mastewal deribew             ";
cou<<"\n\n4.metasebia desta               ";
cou<<"yenesew tsegaye                     ";
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

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
cout<<"\n\n\twater suply information ";
cout<<"Name of kebele:"<<temp->name_kebele<<"\n\n";
cout<<"water suply date:"<<temp->watersuply_d<<"/"<<temp->watersuply_m<<"/"<<temp->watersuply_y<<"\n\n";
cout<<"kebele number:"<<temp->keb_num<<"\n\n";

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

cout<<"WELCOME TO water supply  SYSTEM \n\n\n";

delay(500);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@                 MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  1.Add  water supply infor                    @";
cout<<"\n\n\t@  2.Display information                        @";
cout<<"\n\n\t@  3.Search item inf                            @";
cout<<"\n\n\t@  p.programmer                                 @";
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
add_info();
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
exit(8);
break;
case 'p':
clrscr();
gotoxy(12,12);
developer();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
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
