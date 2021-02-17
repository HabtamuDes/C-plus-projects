   #include<iostream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>

			   struct hotel
			   {
			   char name_item[24];
			   char name_type[24];
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			   
			   char ch;
			   int date;
			
			  int code_item;
			int cost;
			   hotel*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       hotel*strat_ptr=NULL;
	       hotel*temp=new hotel;
			void add_item();
		
			void delet_at_end();
			int search();
			void display();
			
////////////////////////////////////////////////////////////////////////
	 void add_item() // record existing supermarket information;
	   {

	   hotel date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				hotel *temp2;
				hotel *temp=new hotel;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
 cout<<"\n\n\t type of item ";
      cin>>temp->name_type;
     
      cout<<"\n\n\tname of item ";
      cin>>temp->name_item;
      cout<<"\n\n\t type of item ";
      cin>>temp->name_type;
     
   cout<<"\n\n\tcode number of item";
      cin>>temp->code_item;
 cout<<"\n\n\tcost of item n";
      cin>>temp->cost;



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

	
  
void delet_at_end()
{   hotel*current,*temp;
     current=strat_ptr;
     temp=current;

cout<<"\n\n\n\tEnd position";

	hotel date;
			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;

//cout<<"\n\n\tcurrent date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;;
    if(strat_ptr==NULL)
  cout<<"\n\n\n\t list is empty !!!\n";
 else
 {
   while(current->nxt!=NULL)
   {  temp=current;
      current=current->nxt;
     }

      
      temp->nxt=NULL;
      cout<<"\n\n\titem is expired!";
      delete current;
      }

}//end of else
//end of function

int search()
{

hotel *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the code to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->code_item)
   {
cout<<"\n\n\titem ";
cout<<"Name:"<<temp->name_item<<"\n\n";
cout<<"type name:"<<temp->name_type<<"\n\n";
;
cout<<"item code:"<<temp->code_item<<"\n\n";
cout<<"cost:"<<temp->cost<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:item not found!!!";

return temp->code_item;
//clrscr();
 }
//else

//cout<<"not found\n";
//}
//temp=temp->nxt;



void developer()
{
cout<<"\n\n###################################";
cout<<"\n\n##      GROUP MEMBERS            ##";
cout<<"\n\n##1.muhammed hussien             ##";
cout<<"\n\n##2.selamawit teka               ##";
cout<<"\n\n##3.selamawit tesfaye            ##";
cout<<"\n\n##4.tigist girma                 ##";
cout<<"\n\n###################################";

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
cout<<"\n\n\titem ";
cout<<"Name:"<<temp->name_item<<"\n\n";
cout<<"type name:"<<temp->name_type<<"\n\n";

cout<<"item code:"<<temp->code_item<<"\n\n";
cout<<"cost:"<<temp->cost<<"\n\n";

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

cout<<"WELCOME TO hotel managment  SYSTEM \n\n\n";

//delay(500);
cout<<"\n\n\t################################################";
cout<<"\n\n\t#                 MENU                         #";
cout<<"\n\n\t################################################";
cout<<"\n\n\t#  1.Add item                                   #";
cout<<"\n\n\t#  2.Display information                        #";
cout<<"\n\n\t#  3.Search item inf                            #";
cout<<"\n\n\t#   p.programmer                                 #";
cout<<"\n\n\t#  8.Exit                                       #";
cout<<"\n\n\t################################################";
cout<<"\n\n\t#  Select your choise                          #";
cout<<"\n\n\t################################################";
gotoxy(32,30);
cin>>x;
switch(x)
{
case '1':
gotoxy(12,12);//    position cursor text window.
add_item();
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
{
 goto c;//transfer ~dulla^@204~
}
} 