   #include<iostream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>

			   struct book
			   {
			   char name_book[24];
			   char name_author[24];
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			   int pub_d;
			   int pub_m;
			   int pub_y;
			   char ch;
			   int date;
			 
			   int code_book;
			   book*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       book*strat_ptr=NULL;
	       book*temp=new book;
			void add_book();
			void add_book_at_end();
			void add_book_at_middle(int m);
			void add_book_at_front();
			void remove_at_any();
			int search();
			void display();
			
////////////////////////////////////////////////////////////////////////
	 void add_book() // record existing medicine information;
	   {

	    book date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				book *temp2;
				book *temp=new book;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\ttitle of  book ";
      cin>>temp->name_book;
      cout<<"\n\n\t name of author ";
      cin>>temp->name_author;
      cout<<"\n\n\t enter published date ";
      cin>>temp->pub_d;
      cin>>temp->ch;
      cin>>temp->pub_m;
      cin>>temp->ch;
      cin>>temp->pub_y;
      
      cout<<"\n\n\tISBN number of book";
      cin>>temp->code_book;
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

  void add_book_at_end()
	  {
	     clrscr();
	      book *temp,*temp2;
	       temp=new book;
		 book date;
		    struct dosdate_t d;
			 _dos_getdate(&d);
			    date.curr_d=d.day;
			      date.curr_m=d.month;
			       date.curr_y=d.year;
cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\ttitle of  book ";
      cin>>temp->name_book;
      cout<<"\n\n\t name of author ";
      cin>>temp->name_author;
      cout<<"\n\n\t enter published date ";
      cin>>temp->pub_d;
      cin>>temp->ch;
      cin>>temp->pub_m;
      cin>>temp->ch;
      cin>>temp->pub_y;
      
      cout<<"\n\n\tISBN number of book";
      cin>>temp->code_book;


  

			temp->nxt=NULL;

		       temp2=strat_ptr;
		      while(temp2->nxt!=NULL)
		    {
		 temp2=temp2->nxt;
		  }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
	   }

	
void add_book_at_middle(int m)
{
book *temp,*temp2;
temp=new book;



   book date;
			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
                         date.curr_y=d.year;

		cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\ttitle of  book ";
      cin>>temp->name_book;
      cout<<"\n\n\t name of author ";
      cin>>temp->name_author;
      cout<<"\n\n\t enter published date ";
      cin>>temp->pub_d;
      cin>>temp->ch;
      cin>>temp->pub_m;
      cin>>temp->ch;
      cin>>temp->pub_y;
      
      cout<<"\n\n\tISBN number of book";
      cin>>temp->code_book;	       



int count=0;




temp2=strat_ptr;
while(count<m)
{
temp2=temp2->nxt;
count++;
}
temp->nxt=temp2->nxt;
temp2->nxt=temp;
}
 

 
void add_book_at_front()
{
book *temp,*temp2;
temp=new book;
temp2=strat_ptr;

			    book date;

			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;


cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\ttitle of  book ";
      cin>>temp->name_book;
      cout<<"\n\n\t name of author ";
      cin>>temp->name_author;
      cout<<"\n\n\t enter published date ";
      cin>>temp->pub_d;
      cin>>temp->ch;
      cin>>temp->pub_m;
      cin>>temp->ch;
      cin>>temp->pub_y;
      
      cout<<"\n\n\tISBN number of book";
      cin>>temp->code_book;	       



 if(strat_ptr!=NULL)
 {
strat_ptr=temp;

temp->nxt=temp2;
  strat_ptr=temp;
     }
}
      
 

  void remove_at_any()
  {
    
book *temp;
temp=strat_ptr;
 int found=0;
float co;
cout<<"\nEnter the book code to search\n";
cin>>co;

 while(temp!=NULL)
{
  if(co==temp->code_book)
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

book *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the book code to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->code_book)
   {
cout<<"\n\n\title ";
cout<<"Name:"<<temp->name_book<<"\n\n";
cout<<"author name:"<<temp->name_author<<"\n\n";
cout<<"published date:"<<temp->pub_d<<"/"<<temp->pub_m<<"/"<<temp->pub_y<<"\n\n";

cout<<"book code:"<<temp->code_book<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:book not found!!!";

return temp->code_book;

 }


void developer()
{
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"GROUP MEMBER                           ID ";
cout<<"\n\n1.FISEHA GEBREKIDAN             RCS044/11 ";
cout<<"\n\n2.DEGEN  NEBERTAY               RCS029/11 ";
cout<<"\n\n3.ASEGED WELDE                  RCS013/11 ";
cout<<"\n\n4.EFREM MEHARE                  RCS031/11 ";
cout<<"\n\n5.HAMDU AWEL                    RCS057/11 ";
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";

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
cout<<"\n\n\title ";
cout<<"Name:"<<temp->name_book<<"\n\n";
cout<<"author name:"<<temp->name_author<<"\n\n";
cout<<"published date:"<<temp->pub_d<<"/"<<temp->pub_m<<"/"<<temp->pub_y<<"\n\n";

cout<<"book code:"<<temp->code_book<<"\n\n";
}

}while(temp!=NULL);

}
int main()
{
clrscr();
int n;
char ans,x;

c:  clrscr();
	 //gotoxy(26,28);

cout<<"WELCOME TO Library  SYSTEM \n\n\n";

//delay(500);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@                 MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  1.Add book                                   @";
cout<<"\n\n\t@  2.Add book end                               @";
cout<<"\n\n\t@  3.Add book  at middle                        @";
cout<<"\n\n\t@  4.Add book front                             @";
cout<<"\n\n\t@  5.Display information                        @";
cout<<"\n\n\t@  6.Search book inf                        @";
cout<<"\n\n\t@  7.remove book                                @";
cout<<"\n\t@  p.programmer                                   @";
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
add_book();
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
add_book_at_end();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
 if(ans=='y')
 goto c;
 else if(ans=='n')
exit(8);
break;
case '3':
clrscr();
gotoxy(12,12);
cout<<"\n\n\tEnter position";
cin>>n;

add_book_at_middle(n);

cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
 if(ans=='y')
 goto c;
 else if(ans=='n')
exit(8);
break;

case '4':
clrscr();
gotoxy(12,12);
add_book_at_front();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
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
  case '5':
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
case '6':
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

case '7':
clrscr();
gotoxy(12,12);

remove_at_any();
cout<<"do goto menu?y/n";
cin>>ans;
if(ans=='y')
{
goto c;
}
else
exit(8);
 break;
case '8':
clrscr();
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
