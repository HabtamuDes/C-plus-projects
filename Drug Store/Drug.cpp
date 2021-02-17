   #include<iostream.h>
       #include<conio.h>
       #include<process.h>
       #include<ctype.h>
       #include<string.h>
       #include<dos.h>
       #include<time.h>

			   struct drug
			   {
			   char name_medc[24];
			   char org_medc[24];
			   unsigned int curr_d;
			   unsigned int curr_m;
			   unsigned int curr_y;
			   int manf_m;
			   int manf_y;
			   char ch;
			   int date;
			   int exp_d;
			   int exp_m;
			   int exp_y;
			   int code_medc;
			   drug*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       drug*strat_ptr=NULL;
	       drug*temp=new drug;
			void add_medc();
			void add_medc_at_end();
			void add_medc_at_middle(int m);
			void add_medc_at_front();
			void delet_at_start();
			void delet_at_middle();
			void delet_at_end();
			int search();
			void display();
			 void chek_exp();
////////////////////////////////////////////////////////////////////////
	 void add_medc() // record existing medicine information;
	   {

	    drug date;//
	   struct dosdate_t d;//structure current date of the system.
	 _dos_getdate(&d);/*dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


	 date.curr_d=d.day;
	date.curr_m=d.month;
       date.curr_y=d.year;

				drug *temp2;
				drug *temp=new drug;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\n\tcurrent date:"
    <<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
      cout<<"\n\n\tPleas enetr";
      cout<<"\n\n\tname of medicine ";
      cin>>temp->name_medc;
      cout<<"\n\n\t name of manifactered organization ";
      cin>>temp->org_medc;
      cout<<"\n\n\t enter manfacter date of medicine ";
      cin>>temp->manf_d;
      cin>>temp->ch;
      cin>>temp->manf_m;
      cin>>temp->ch;
      cin>>temp->manf_y;
      cout<<"\n\n\tenter expired date of medicine";
      cin>>temp->exp_d;
      cin>>temp->ch;
      cin>>temp->exp_m;
      cin>>temp->ch;
      cin>>temp->exp_y;
      cout<<"\n\n\tcode number of medicine";
      cin>>temp->code_medc;
	      if(temp->exp_y<date.curr_y)
		{
		   cout<<"\n\n\tincorrect input!";
		   delete temp;
		   }
		   else if(temp->exp_y==date.curr_y)
			{
		   if(temp->exp_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->exp_m==date.curr_m)
			   {      if(temp->exp_d<=date.curr_d)
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

  void add_medc_at_end()
	  {
	     clrscr();
	      drug *temp,*temp2;
	       temp=new drug;
		 drug date;
		    struct dosdate_t d;
			 _dos_getdate(&d);
			    date.curr_d=d.day;
			      date.curr_m=d.month;
			       date.curr_y=d.year;

cout<<"current date:"<<date.curr_d
<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;;
cout<<"\n\n\tname of medicine ";
cin>>temp->name_medc;
cout<<"\n\n\tname of organization";
cin>>temp->org_medc;



cout<<"\n\n\t enter manfacter date of medicine ";
cin>>temp->manf_d;
cin>>temp->ch;
cin>>temp->manf_m;
cin>>temp->ch;
cin>>temp->manf_y;
cout<<"\n\n\texpired date of medicine ";

cin>>temp->exp_d;
cin>>temp->ch;
cin>>temp->exp_m;
cin>>temp->ch;
cin>>temp->exp_y;

cout<<"\n\n\tcode number of medicine ";
cin>>temp->code_medc;

  if(temp->exp_y<date.curr_y)
		{
		   cout<<"\n\n\tincorrect input!";
		   delete temp;
		   }
		   else if(temp->exp_y==date.curr_y)
			{
		   if(temp->exp_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->exp_m==date.curr_m)
			   {
			   if(temp->exp_d<=date.curr_d)
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

void add_medc_at_middle(int m)
{
drug *temp,*temp2;
temp=new drug;



   drug date;
			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;

			       date.curr_y=d.year;

cout<<"current date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<"/"<<endl;
cout<<"\n\n\tEnter ";
cout<<"\n\n\tname of medicine";
cin>>temp->name_medc;
cout<<"\n\n\t organization name ";
cin>>temp->org_medc;
cout<<"\n\n\tmanifactered date of medicine ";

cin>>temp->manf_d;
cin>>temp->ch;
cin>>temp->manf_m;
cin>>temp->ch;
cin>>temp->manf_y;
cout<<"\n\n\t expired date of medicine ";
cin>>temp->exp_d;
cin>>temp->ch;
cin>>temp->exp_m;
cin>>temp->ch;
cin>>temp->exp_y;

cout<<"\n\n\t code number of medicine";
cin>>temp->code_medc;

if(temp->exp_y<date.curr_y)
{
 cout<<"\n\n\tincorrect input!";

    delete temp;
    }

else if(temp->exp_y==date.curr_y)
			{
		   if(temp->exp_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->exp_m==date.curr_m)
			   {
			   if(temp->exp_d<=date.curr_d)
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
void add_medc_at_front()
{
drug *temp,*temp2;
temp=new drug;
temp2=strat_ptr;

			    drug date;

			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;

cout<<"current date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;
cout<<"\n\n\tEnter ";
cout<<"\n\n\tname of medicine ";
cin>>temp->name_medc;
cout<<"\n\n\tname of orgnization ";
cin>>temp->org_medc;
cout<<" \n\n\tmanifacterd date of medicine";
cin>>temp->manf_d;
cin>>temp->ch;
cin>>temp->manf_m;
cin>>temp->ch;
cin>>temp->manf_y;
cout<<"\n\n\texpired date of medicine";
cin>>temp->exp_d;
cin>>temp->ch;
cin>>temp->exp_m;
cin>>temp->ch;
cin>>temp->exp_y;

cout<<"\n\n\tcode numeber of medicine ";
cin>>temp->code_medc;



if(temp->exp_y<date.curr_y)
{
 cout<<"\n\n\tincorrect input!";

    delete temp;
    }

else if(temp->exp_y==date.curr_y)
			{
		   if(temp->exp_m<date.curr_m)
			       {

			    cout<<"incorrecte input!!";
			    delete temp;
			    }
			   else if(temp->exp_m==date.curr_m)
			   {
			   if(temp->exp_d<=date.curr_d)
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
 void chek_exp()
 {



 drug date;
	      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;

cout<<"current date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;

    if(date.curr_d<date.curr_d+1)
    {
       delet_at_start();
	delet_at_middle();
	delet_at_end();


	}

       }
void delet_at_start()
{

 cout<<"\n\n\n\tstart posution";

   drug date;
			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;

//cout<<"\n\n\tcurrent date:"<<date.curr_d<<date.curr_m<<date.curr_y<<endl;
   if(temp->nxt!=NULL)
   {
	 if(date.curr_y>temp->exp_y)
	    {
      temp=strat_ptr;
    strat_ptr=strat_ptr->nxt;
   cout<<"\n\n\tMedicine is expired!";
	 delete temp;
	     }//end of if
     else if(date.curr_y==temp->exp_y)
	       {
		   if(date.curr_m>temp->exp_m)
			   {
			 temp=strat_ptr;
			 strat_ptr=strat_ptr->nxt;
			    cout<<"\n\n\tMedicine is expired!";
			    delete temp;
		       }//end of if
		 else if(date.curr_m==temp->exp_m)
			{
			     if(date.curr_d>=temp->exp_d)
			       {
				temp=strat_ptr;
				    strat_ptr=strat_ptr->nxt;
				      cout<<"\n\n\tMedicine is expired!";
					  delete temp;
				}//end of if
			     else

			      cout<<"\n\n\tMedicine not is expired!";
		      } //end of else if
		 else

		cout<<"\n\n\tMedicine is not expired!";

	  }  //end of else if

 else
 cout<<"\n\n\tMedicine is not expired!";
}
}

  void delet_at_middle()
  {
     drug*temp,*temp1,*temp2;

     cout<<"\n\n\n\tMiddle position";
	drug date;
			      struct dosdate_t d;
			       _dos_getdate(&d);
			      date.curr_d=d.day;
			       date.curr_m=d.month;
			       date.curr_y=d.year;

//cout<<"\n\n\tcurrent date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;

    while(temp->nxt!=NULL)
   {
      if(date.curr_y>temp->exp_y)
      {

if(strat_ptr==NULL)
{
cout<<"\n\n\tNo medicine! ";

}
else
{
temp2=strat_ptr;


  temp=temp2;
temp2=temp2->nxt;

temp1->nxt=temp2->nxt;
 cout<<"\n\n\tMedicine is expired!";
delete temp2;


	 } }
    else if(date.curr_y==temp->exp_y)
    {
       if(date.curr_m>temp->exp_m)
       {

if(strat_ptr==NULL)
{
cout<<"\n\n\tNo medicine! ";

}
else
{
temp2=strat_ptr;


  temp1=temp2;
temp2=temp2->nxt;


temp1->nxt=temp2->nxt;
 cout<<"\n\n\tMedicine is expired!";
delete temp2;
       } }
     else if(date.curr_m==temp->exp_m)
     {
	     if(date.curr_d>=temp->exp_d)
	      {


if(strat_ptr==NULL)
{
cout<<"\n\n\tNo medicine! ";

}
else
{
temp2=strat_ptr;


  temp1=temp2;
temp2=temp2->nxt;


temp1->nxt=temp2->nxt;
 cout<<"\n\n\tMedicine is expired!";
delete temp2;
	}
	    }
		    else

	 cout<<"\n\n\tMedicine is not expired!";
	 }
	  else

	 cout<<"\n\n\tMedicine is not expired!";
	 }
     else

       cout<<"\n\n\tMedicine is not expired!";

}}
void delet_at_end()
{   drug*current,*temp;
     current=strat_ptr;
     temp=current;

cout<<"\n\n\n\tEnd position";

	drug date;
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

      if(date.curr_y>current->exp_y)
      {
      temp->nxt=NULL;
      cout<<"\n\n\tMedicine is expired!";
      delete current;
      }
else if(date.curr_y==current->exp_y)
     {
	 if(date.curr_m>current->exp_m)
	   {
	    temp->nxt=NULL;
	   cout<<"\n\n\tMedicine is expired!";
	    delete current;
	   }
      else if(date.curr_m==current->exp_m)
	   {
	      if(date.curr_d>=current->exp_d)
		   {   temp->nxt=NULL;
		   cout<<"\n\n\tMedicine is expired!";
		     delete current;
		 }
	      else
	      cout<<"\n\n\tMedicine is not expired!";
	   }
     else
     cout<<"\n\n\tMedicine is not expired!";
   }
 else
cout<<"\n\n\tMedicine is not expired!";
 }//end of else if
}//end of else
//end of function

int search()
{

drug *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the code to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->code_medc)
   {
cout<<"\n\n\tMEDICINE ";
cout<<"Name:"<<temp->name_medc<<"\n\n";
cout<<"org name:"<<temp->org_medc<<"\n\n";
cout<<"menifacter date:"<<temp->manf_d<<"/"<<temp->manf_m<<"/"<<temp->manf_y<<"\n\n";
cout<<"expired date:"<<temp->exp_d<<"/"<<temp->exp_m<<"/"<<temp->exp_y<<"\n\n";
cout<<"medicine code:"<<temp->code_medc<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:Medicin not found!!!";

return temp->code_medc;
//clrscr();
 }
//else

//cout<<"not found\n";
//}
//temp=temp->nxt;

void developer()
{
cout<< " GROUP MEMBERS   \t\t\t ID NUMBER     \n";
cout<<"\n1.samuel elias  \t\t\t   RCS 127/11";
cout<<"\n2.tamiru asefa  \t\t\t   RCS 138/11";
cout<<"\n3.NESTANET lale  \t\t\t   RCS 113/11";
cout<<"\n4.nathenael nadew \t\t\t   RCS 098/11";
cout<<"\n5.kasahun galishow \t\t\t   RCS 067/11";
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
cout<<"\n\n\tMEDICINE ";
cout<<"Name:"<<temp->name_medc<<"\n\n";
cout<<"org name:"<<temp->org_medc<<"\n\n";
cout<<"menifacter date:"<<temp->manf_d<<"/"<<temp->manf_m<<"/"<<temp->manf_y<<"\n\n";
cout<<"expired date:"<<temp->exp_d<<"/"<<temp->exp_m<<"/"<<temp->exp_y<<"\n\n";

cout<<"medicine code:"<<temp->code_medc<<"\n\n";
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

cout<<"WELCOME TO PHARMACY SYSTEM \n\n\n";

delay(500);
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@                 MENU                         @";
cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
cout<<"\n\n\t@  1.Add medicine                               @";
cout<<"\n\n\t@  2.Add medicine end                           @";
cout<<"\n\n\t@  3.Add medicine at middle                     @";
cout<<"\n\n\t@  4.Add medicine front                         @";
cout<<"\n\n\t@  5.Display information                        @";
cout<<"\n\n\t@  6.Search medicine inf                        @";
cout<<"\n\n\t@  7.check expired medicine                     @";
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
add_medc();
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
add_medc_at_end();
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

add_medc_at_middle(n);

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
add_medc_at_front();
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

chek_exp();
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
