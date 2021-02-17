       #include<iostream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>



		    struct enventory
			   {
			   char g_name[20];
			   char g_type[20],quality[20];
			   int price,quantity;
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			   int reciev_d;
			   int reciev_m;
			   int reciev_y;
			   char ch;
			   char Nreciever[12],Id[12];
			   int date;
			   int return_d;
			   int return_m;
			   int return_y;
			   int good_code;
			   enventory*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       enventory*strat_ptr=NULL;
	       enventory*temp=new enventory;
			void add_good();
			void add_good_at_end();
			void ada_good_at_middle(int m);
			void add_good_at_front();
			int search();
			void display();
////////////////////////////////////////////////////////////////////////

		 void add_good()
	   {

	    enventory date;//
	   struct dosdate_t d;//stracture current date of the system.
	 _dos_getdate(&d);/* _dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				enventory *temp2;
				enventory*temp=new enventory;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enter:";
      cout<<"\n\n\t\tName of good\t\t";
      cin>>temp->g_name;
      cout<<"\n\n\t\t Good_type\t\t ";
      cin>>temp->g_type;
cout<<"\n\n\t\tQuality_of_good\t\t";
cin>>temp->quality;
cout<<"\n\n\t\tQuantity_of_good\t";
cin>>temp->quantity;
cout<<"\n\n\t\tPrice_of_good\t\t";
cin>>temp->price;
      cout<<"\n\n\t\t Recieved date\t\t";
      cin>>temp->reciev_d;
      cin>>temp->ch;
      cin>>temp->reciev_m;
      cin>>temp->ch;
      cin>>temp->reciev_y;
      cout<<"\n\n\t\tReturned date\t\t";
      cin>>temp->return_d;
      cin>>temp->ch;
      cin>>temp->return_m;
      cin>>temp->ch;
      cin>>temp->return_y;
      cout<<"\n\n\t\t\tID to search:\t";
      cin>>temp->good_code;
      cout<<"\n\n\t Name of reciever:\t\t";
      cin>>temp->Nreciever;
      cout<<"\n\n\tID of reciever:\t\t\t";
      cin>>temp->Id;
	      if(temp->return_y<date.curr_y)
		{
		   cout<<"\n\n\tincorrect input!";
		   delete temp;
		   }
		   else if(temp->return_y==date.curr_y)
			{
		   if(temp->return_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->return_m==date.curr_m)
			   {      if(temp->return_d<=date.curr_d)
				   {
			   cout<<"incorrecte in put!!";
			   delete temp;
				   }

		      else
			 {
		      cout<<"correct input";


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

		     else
	      {
	      cout<<"corret input";
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

		     else
		      {
		     cout<<"correcte in put:";

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





 void add_good_at_end()
	  {
	     clrscr();
	     enventory *temp,*temp2;
	       temp=new enventory;
		 enventory date;

		    struct dosdate_t d;
			 _dos_getdate(&d);
			    date.curr_d=d.day;
			      date.curr_m=d.month;
			       date.curr_y=d.year;

cout<<"current date:\t\t"<<date.curr_d
<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;;
cout<<"\n\n\tname of good\t\t ";
cin>>temp->g_name;
cout<<"\n\n\tType of good\t\t";
cin>>temp->g_type;
cout<<"\n\n\tQuality_of_good\t\t";
cin>>temp->quality;
cout<<"\n\n\tQuantity_of_good\t\t";
cin>>temp->quantity;
cout<<"\n\n\tPrice_of_good\t\t";
cin>>temp->price;
cout<<"\n\n\tDate of recieved ";
cin>>temp->reciev_d;
cin>>temp->ch;
cin>>temp->reciev_m;
cin>>temp->ch;
cin>>temp->reciev_y;
cout<<"\n\n\Date of returned ";

cin>>temp->return_d;
cin>>temp->ch;
cin>>temp->return_m;
cin>>temp->ch;
cin>>temp->return_y;

cout<<"\n\n\tID to search good information\t\t ";
cin>>temp->good_code;
      cout<<"\n\n\t Name of reciever\t\t:";
      cin>>temp->Nreciever;
      cout<<"\n\n\tID of reciever\t\t";
      cin>>temp->Id;

  if(temp->return_y<date.curr_y)
		{
		   cout<<"\n\n\tincorrect input!";
		   delete temp;
		   }
		   else if(temp->return_y==date.curr_y)
			{
		   if(temp->return_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->return_m==date.curr_m)
			   {
			   if(temp->return_d<=date.curr_d)
				   {
			   cout<<"incorrecte in put!!";
			   delete temp;
				   }

		      else
			 {
		      cout<<"correct input";


			temp->nxt=NULL;

		       temp2=strat_ptr;
		      while(temp2->nxt!=NULL)
		    {
		 temp2=temp2->nxt;
		  }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
	   }

	 }

		     else
	      {
	      cout<<"corret input";
		       temp->nxt=NULL;

		       temp2=strat_ptr;
		      while(temp2->nxt!=NULL)
		    {
		 temp2=temp2->nxt;
		  }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
	   }

	 }

		     else
		      {
		     cout<<"correcte in put:";

			    temp->nxt=NULL;

			    temp2=strat_ptr;
		      while(temp2->nxt!=NULL)
		    {
		 temp2=temp2->nxt;
		  }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
	   }

	   }

	       void add_good_at_middle(int m)
		  {
enventory*temp,*temp2;
temp=new enventory;



   enventory date;
			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;

			       date.curr_y=d.year;

cout<<"current date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<"/"<<endl;
cout<<"\n\n\tEnter ";
cout<<"\n\n\tg_name\t\t";
cin>>temp->g_name;
cout<<"\n\n\t good type:\t\t ";
cin>>temp->g_type;

      cout<<"\n\n\tQuality_of_good\t\t";
      cin>>temp->quality;
      cout<<"\n\n\tQuantity_of_good\t\t";
      cin>>temp->quantity;
      cout<<"\n\n\tPrice_of_good\t\t";
      cin>>temp->price;

cout<<"\n\n\t Date of recieved\t\t";

cin>>temp->reciev_d;
cin>>temp->ch;
cin>>temp->reciev_m;
cin>>temp->ch;
cin>>temp->reciev_y;
cout<<"\n\n\t Date of returned";
cin>>temp->return_d;
cin>>temp->ch;
cin>>temp->return_m;
cin>>temp->ch;
cin>>temp->return_y;

cout<<"\n\n\t ID to search\t\t";
cin>>temp->good_code;

      cout<<"\n\n\t Name of reciever\t\t:";
      cin>>temp->Nreciever;
      cout<<"\n\n\tID of reciever\t\t";
      cin>>temp->Id;

if(temp->return_y<date.curr_y)
{
 cout<<"\n\n\tincorrect input!";

    delete temp;
    }

else if(temp->return_y==date.curr_y)
			{
		   if(temp->return_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->return_m==date.curr_m)
			   {
			   if(temp->return_d<=date.curr_d)
				   {
			   cout<<"incorrecte in put!!";
			   delete temp;
				   }

		      else
			 {
		      cout<<"correct input";



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
  }

  else
  {
   cout<<"correct in put!";

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

  }

 else

 {
cout<<"correct input!";
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
}


		void add_good_at_front()
		     {
enventory*temp,*temp2;
temp=new enventory;
temp2=strat_ptr;

			    enventory date;

			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;

cout<<"current date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
cout<<"\n\n\tEnter ";
cout<<"\n\n\tname of good:\t\t";
cin>>temp->g_name;
cout<<"\n\n\ttype of good:\t\t";
cin>>temp->g_type;
cout<<"\n\n\tQuality_of_good:";
cin>>temp->quality;
cout<<"\n\n\tQuantity_of_good:";
cin>>temp->quantity;
cout<<"\n\n\tPrice_of_good:";
cin>>temp->price;
cout<<" \n\n\trecieved date :";
cin>>temp->reciev_d;
cin>>temp->ch;
cin>>temp->reciev_m;
cin>>temp->ch;
cin>>temp->reciev_y;
cout<<"\n\n\treturned date";
cin>>temp->return_d;
cin>>temp->ch;
cin>>temp->return_m;
cin>>temp->ch;
cin>>temp->return_y;

cout<<"\n\n\tcode numeber to search good:\t\t ";
cin>>temp->good_code;

      cout<<"\n\n\t Name of reciever\t\t:";
      cin>>temp->Nreciever;
      cout<<"\n\n\tID of reciever\t\t";
      cin>>temp->Id;

if(temp->return_y<date.curr_y)
{
 cout<<"\n\n\t incorrect input!";

    delete temp;
    }

else if(temp->return_y==date.curr_y)
			{
		   if(temp->return_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->return_m==date.curr_m)
			   {
			   if(temp->return_d<=date.curr_d)
				   {
			   cout<<"incorrecte in put!!";
			   delete temp;
				   }

		      else
			 {
		      cout<<"correct input";



 if(strat_ptr!=NULL)
 {
strat_ptr=temp;

temp->nxt=temp2;
  strat_ptr=temp;
     }
      }

     }
  else
  {
  cout<<"correct input!";

   if(strat_ptr!=NULL)
   {
strat_ptr=temp;

temp->nxt=temp2;
  strat_ptr=temp;
    }
     }
       }
     else
     {
     cout<<"correct input!";


      if(strat_ptr!=NULL)
      {
strat_ptr=temp;



temp->nxt=temp2;
  strat_ptr=temp;
     }
       }


  }

	       int search()
		  {

enventory *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the code to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->good_code)
   {
cout<<"\n\n\tGOOD";
cout<<"Name:\t\t"<<temp->g_name<<"\n\n";
cout<<"good_type:\t\t"<<temp->g_type<<"\n\n";
      cout<<"Quality_of_good:\t\t"<<temp->quality<<"\n\n";
      cout<<"Quantity_of_good\t\t:"<<temp->quantity<<"\n\n";
      cout<<"Price_of_good\t\t:"<<temp->price<<"\n\n";

cout<<"date recieved:\t\t"<<temp->reciev_d<<"/"<<temp->reciev_m<<"/"<<temp->reciev_y<<"\n\n";
cout<<"date returned:\t\t"<<temp->return_d<<"/"<<temp->return_m<<"/"<<temp->return_y<<"\n\n";
cout<<"good code to search:\t\t"<<temp->good_code<<"\n\n";
cout<<"Reciever name:\t\t"<<temp->Nreciever<<"\n\n";
cout<<"IDreciever:\t\t"<<temp->Id;
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:good not found!!!";

return temp->good_code;
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
cout<<"\n\n\tGOOD";
cout<<"Name:\t"<<temp->g_name<<"\n\n";
cout<<"G_type:\t"<<temp->g_type<<"\n\n";
cout<<"Quality_of_good:\t"<<temp->quality<<"\n\n";
cout<<"Quantity_of_good:\t"<<temp->quantity<<"\n\n";
cout<<"Price_of_good:\t\t"<<temp->price<<"\n\n";
cout<<"Recieved date:\t\t"<<temp->reciev_d<<"/"<<temp->reciev_m<<"/"<<temp->reciev_y<<"\n\n";
cout<<"Returned date:\t\t"<<temp->return_d<<"/"<<temp->return_m<<"/"<<temp->return_y<<"\n\n";
cout<<"Good code to search:\t"<<temp->good_code<<"\n\n";
cout<<"Reciever name:\t\t"<<temp->Nreciever<<"\n\n";
cout<<"IDreciever:\t\t"<<temp->Id;
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
cout<<" WELCOME TO ENVENTORY SYSTEM \n\n\n";
delay(600);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@            MAIN MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t                                               @";
cout<<"\n\n\t@  1.Add good                                  @";
cout<<"\n\n\t@  2.Add good at end                           @";
cout<<"\n\n\t@  3.Add good at middle                        @";
cout<<"\n\n\t@  4.Add good at front                         @";
cout<<"\n\n\t@  5.Display information                       @";
cout<<"\n\n\t@  6.Search good informn                       @";
cout<<"\n\n\t@  7.Exit                                      @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  Select your choise                          @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

gotoxy(32,30);
cin>>x;
switch(x)
{
case '1':
gotoxy(12,12);
add_good();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
  goto c;
else if(ans=='n')
   exit(0);
break;

case '2':
clrscr();
gotoxy(12,12);
add_good_at_end();
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
cout<<"\n\n\tEnter position";
cin>>n;

add_good_at_middle(n);

cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
 if(ans=='y')
 goto c;
 else if(ans=='n')
exit(7);
break;

case '4':
clrscr();
gotoxy(12,12);
add_good_at_front();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
 if(ans=='y')
 goto c;
 else if(ans=='n')
exit(7);
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
exit(7);
break;
clrscr();
cout<<"\n\n\tError choise! ";
}
getch();
clrscr();
cout<<"\n\n\tDo you want to continue? (y/n) ";
cin>>ans;
if(ans=='y');
 goto c;
}
