       #include <iostream.h>
       #include <conio.h>
       #include <string.h>
       #include <process.h>
       #include <dos.h>
       #include <time.h>

			   struct bstore
			   {
			   
			   unsigned int curr_d; //current date
			   unsigned int curr_m;
			   unsigned int curr_y;
			   char ch;
			   int date;
			   int b_isbn;
			   /////////////////////////////
			   //char b_isbn[25];
			   char title[25];
			   char author[25];
			   char pub_org[25];
			   char edition[25];
			   int no_of_copy;
			   int d_i;  // date in when the book is registered
			   int m_i;  // month in
			   int y_i;  // year in
			   int pub_d;//published date
			   int pub_m;//published month
			   int pub_y;//published year
			    int d_i_b; //date of book issued
			    int m_i_b; //month of issue book
			    int y_i_b; //year of issue book
			   int d_r_b;//date of return book
			   int m_r_b;//month of return book
			   int y_r_b;//year of return book
			    //customer
			   char u_id[25];
			   char u_name[25];
			   char gender[5];
			   char school[25];
			   char dept[25];
			   char address[25];
			   /////////////////////////////
			   bstore*nxt;

			   };
/////////////////////////////////////////////////////////////////////////





	       bstore*strat_ptr=NULL;
	       bstore*temp=new bstore;
			void add_book();
			void add_book_at_end();
			void add_book_at_middle(int m);
			void add_book_at_front();
			void delet_at_start();
			void delet_at_middle();
			void delet_at_end();
			  int searchb();// searching for borrowed book
			  int searchr();// return
			  int searchbd();// book detail
			void displayb(); //display borrowed
			void displayr();//
			void displaybd();//
			void issue_date();
			void return_date();
			void groupmember();
		       //	void chek_fine();
////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
   void issue_date()
    {
     bstore date;//
     struct dosdate_t d;//stracture current date of the system.
    _dos_getdate(&d);/* _dos_getdate fills in the dosdate_t structure
		      /*datep with the system's current date*/

    date.d_i_b=d.day; ///i indicate for issue /borrow
    date.m_i_b=d.month;
    date.y_i_b=d.year;


    bstore *temp2;
    bstore *temp=new bstore;//int vv;
   clrscr();

    gotoxy(12,12);//shows the position of the cursor.
    cout<<"\n\t**********************************\n";
    cout<<"\n\t**** BOOK ISSUE FORM *************\n";
    cout<<"\n\t**********************************\n";
    cout<<"\n\tEnter User name: ";
    cin>>temp->u_name;

    cout<<"\n\tEnter  User ID ";
    cin>>temp->u_id;
    cout<<"\n\tEnter gender: ";
    cin>>temp->gender;
    cout<<"\n\tEnter school name: ";
    cin>>temp->school;
    cout<<"\n\tEnter Department name: ";
    cin>>temp->dept;
    cout<<"\n\tEnter Address: ";
    cin>>temp->address;
    cout<<"\n\tEnter Isbn:- ";
    cin>>temp->b_isbn;

    cout<<"\n\tEnter title :- ";
    cin>>temp->title;
    cout<<"\n\tBook author name";
    cin>>temp->author;
    cout<<"\n\tDate of Borrow ";
    cout<<date.d_i_b<<"/"<<date.m_i_b<<"/"<<date.y_i_b<<endl;
    cout<<"\n\tCorret input";
    cout<<"\n\tSuccessfully registered\n";
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

///////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////
      void return_date()
      {
      //
      bstore date;//
     struct dosdate_t d;//stracture current date of the system.
     _dos_getdate(&d);/* _dos_getdate fills in the dosdate_t structure
		      /*datep with the system's current date*/

	    date.d_r_b=d.day;
	    date.m_r_b=d.month;
	    date.y_r_b=d.year;


				bstore *temp2;
				bstore *temp=new bstore;//int vv;
				clrscr();
				gotoxy(12,12);//shows the position of
					       //the cursor.
    cout<<"\n\t------------------\n";
    cout<<"\n\t--BOOK ISSUE------\n";
    cout<<"\n\t------------------\n";
    cout<<"\n\tEnter User name: ";
    cin>>temp->u_name;
    cout<<"\n\tEnter User ID: ";
    cin>>temp->u_id;
    cout<<"\n\tEnter gender: ";
    cin>>temp->gender;
    cout<<"\n\tEnter school name: ";
    cin>>temp->school;
    cout<<"\n\tEnter Department name: ";
    cin>>temp->dept;
    cout<<"\n\tEnter Address: ";
    cin>>temp->address;
    cout<<"\n\tEnter Book Isbn: ";
    cin>>temp->b_isbn;
    cout<<"\n\tEnter Author Book: ";
    cin>>temp->author;
    cout<<"\n\tEnter title :- ";
    cin>>temp->title;
    cout<<"\n\tBook issue Date: ";
    cin>>temp->d_i_b;
    cin>>temp->ch;
    cin>>temp->m_i_b;
    cin>>temp->ch;
    cin>>temp->y_i_b;

    cout<<"\n\tEnter Date of Return: ";
    cout<<date.d_r_b<<"/"<<date.m_r_b<<"/"<<date.y_r_b;

    float y,z;
    z=date.d_r_b - temp->d_i_b;
     a:
    if(z<=15)
    {
    char s;
    cout<<"\n\tNo fine\n";
    delay(5000);
    cout<<"\n\t Does He return(y/n)?\n";
    cin>>s;
    if(s=='n'||s=='N')
    {
    cout<<"\n\t The book is not returned ";
    goto a;
     }
    else
    cout<<"\n\tSucessfull return";
    cout<<"\n\tCorret Input";
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

    else
    {
    float y;
    y=(z-15)*0.25;
    cout<<"\n You have fine you have to pay:-"<<y<<" ";
    if(y<0.99)
    {
    cout<<"cent\n";
    }
    else
    cout<<" birr\n";

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
	//


 /////////////////////////
 ///////////////////////
 ///////ADD BOOK///////
 /////////////////////
 ////////////////////

 void add_book() // record existing book information;
	   {

bstore date;//
struct dosdate_t d;//stracture current date of the system.
_dos_getdate(&d);/* _dos_getdate fills in the dosdate_t structure *datep with the system's
current date*/


date.d_i=d.day;
date.m_i=d.month;
date.y_i=d.year;

      bstore *temp2;
      bstore *temp=new bstore;//int vv;
      clrscr();
      gotoxy(12,12);//shows the position of the cursor.

    cout<<"\n\tEnter Book Isbn: ";
    cin>>temp->b_isbn;
    cout<<"\n\tEnter Title :- ";
    cin>>temp->title;
    cout<<"\n\tEnter Author Book: ";
    cin>>temp->author;
    cout<<"\n\tEnter Name Of Publisher Organization: ";
    cin>>temp->pub_org;
    cout<<"\n\tEnter Book Edition : ";
    cin>>temp->edition;
    cout<<"\n\tEnter Number of copy : ";
    cin>>temp->no_of_copy;
    cout<<"\n\tBook Date of registered in to stack : ";
    cout<<date.d_i<<"/"<<date.m_i<<"/"<<date.y_i<<endl;
	cout<<"\n\tEnter date of Book Published : ";
	cin>>temp->pub_d;
	cin>>temp->ch;
	cin>>temp->pub_m;
	cin>>temp->ch;
	cin>>temp->pub_y;

	if(date.y_i<temp->pub_y)
	{
	cout<<"\n incorrect input date";
	delete temp;
	}
	else
	{   cout<<"\n\tCorrecte in put\n:";
	    cout<<"\n\tSuccessfuly registered :";
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

///////////////////////////
//////////////////////////
////////ADD BOOK AT END//
////////////////////////
///////////////////////

void add_book_at_end()
{
	clrscr();
	bstore *temp,*temp2;
	temp=new bstore;
    bstore date;
    struct dosdate_t d;
	_dos_getdate(&d);
	date.d_i=d.day;
	date.m_i=d.month;
	date.y_i=d.year;

    cout<<"\n\tEnter Book Isbn: ";
    cin>>temp->b_isbn;
    cout<<"\n\tEnter title :- ";
    cin>>temp->title;
    cout<<"\n\tEnter Author Book: ";
    cin>>temp->author;
    cout<<"\n\tEnter Name of publisher organization: ";
    cin>>temp->pub_org;
    cout<<"\n\tEnter Book Edition : ";
    cin>>temp->edition;
    cout<<"\n\tEnter Number of copy : ";
    cin>>temp->no_of_copy;
    cout<<"\n\tBook Date of registered in to stack : ";
    cout<<date.d_i<<"/"<<date.m_i<<"/"<<date.y_i<<endl;
	cout<<"\n\tEnter date of Book Published : ";
	cin>>temp->pub_d;
	cin>>temp->ch;
	cin>>temp->pub_m;
	cin>>temp->ch;
	cin>>temp->pub_y;
	//cin>>temp->ch;
    cout<<"\n\tThe Inputs are Correct!\n";
    cout<<"\n\tSo the datas' are\n";
    cout<<"\n\tAlready Successful registered\n";
	temp->nxt=NULL;
    temp2=strat_ptr;
	while(temp2->nxt!=NULL)
	{
     temp2=temp2->nxt;
	}
	 temp2->nxt=temp;
	 temp->nxt=NULL;
	 

 }


/////////////////////////////////////
////////////////////////////////////
////////////ADD BOOK AT MIDDLE/////
//////////////////////////////////
/////////////////////////////////


void add_book_at_middle(int m)
{
bstore *temp,*temp2;
temp=new bstore;
bstore date;
struct dosdate_t d;
_dos_getdate(&d);

date.d_i=d.day;
date.m_i=d.month;
date.y_i=d.year;

    cout<<"\n\tEnter Book Isbn: ";
    cin>>temp->b_isbn;
    cout<<"\n\tEnter title :- ";
    cin>>temp->title;
    cout<<"\n\tEnter Author Book: ";
    cin>>temp->author;
    cout<<"\n\tEnter Name of publisher organization: ";
    cin>>temp->pub_org;
    cout<<"\n\tEnter Book Edition : ";
    cin>>temp->edition;
    cout<<"\n\tEnter Number of copy : ";
    cin>>temp->no_of_copy;
    cout<<"\n\tBook Date of registered in to stack : ";
    cout<<date.d_i<<"/"<<date.m_i<<"/"<<date.y_i<<endl;
	cout<<"\n\tEnter date of Book Published : ";
	cin>>temp->pub_d;
	cin>>temp->ch;
	cin>>temp->pub_m;
	cin>>temp->ch;
	cin>>temp->pub_y;
	//cin>>temp->ch;
    cout<<"\n\tThe Inputs are Correct!\n";
    cout<<"\n\tSo the datas' are\n";
    cout<<"\n\tAlready Successful registered\n";
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

 ///////////////////////////////////
 //////////////////////////////////
 /////////ADD BOOK AT FRONT///////
 ////////////////////////////////
 ///////////////////////////////
void add_book_at_front()
{
bstore *temp,*temp2;
temp=new bstore;
temp2=strat_ptr;

			    bstore date;

			      struct dosdate_t d;
			      _dos_getdate(&d);
			      date.d_i=d.day;
			      date.m_i=d.month;
			      date.y_i=d.year;

    cout<<"\n\tEnter Book Isbn: ";
    cin>>temp->b_isbn;
    cout<<"\n\tEnter title :- ";
    cin>>temp->title;
    cout<<"\n\tEnter Author Book: ";
    cin>>temp->author;
    cout<<"\n\tEnter Name of publisher organization: ";
    cin>>temp->pub_org;
    cout<<"\n\tEnter Book Edition : ";
    cin>>temp->edition;
    cout<<"\n\tEnter Number of copy : ";
    cin>>temp->no_of_copy;
    cout<<"\n\tBook Date of registered in to stack : ";
    cout<<date.d_i<<"/"<<date.m_i<<"/"<<date.y_i<<endl;
	cout<<"\n\tEnter date of Book Published : ";
	cin>>temp->pub_d;
	cin>>temp->ch;
	cin>>temp->pub_m;
	cin>>temp->ch;
	cin>>temp->pub_y;
	//cin>>temp->ch;
    cout<<"The Inputs are Correct!\n";
    cout<<"So the datas' are\n";
    cout<<"Already Successful registered\n";
    if(strat_ptr!=NULL)
       {
        strat_ptr=temp;
        temp->nxt=temp2;
        strat_ptr=temp;
       }
   
  }




  // to check
  //////////////////////////
  /////////////////////////
  /////////CHECK fine//////
  ///////////////////////
  //////////////////////
 /*void chek_fine()
 {



 bstore date;
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

       }*/
////////////////////////////////
///////////////////////////////
////////DELETE AT START///////
/////////////////////////////
////////////////////////////

void delet_at_start()
{

    cout<<"\n\n\n\tstart position\n";

    bstore date;
    struct dosdate_t d;
   _dos_getdate(&d);
    date.curr_d=d.day;
    date.curr_m=d.month;
	date.curr_y=d.year;
	int k;
	cout<<"\n\n\t How Old are the books u want to delete ? :";
	cin>>k;
	//cout<<"\n\n\tcurrent date:"<<date.curr_d<<date.curr_m<<date.curr_y<<endl;
   if(temp->nxt!=NULL)
   {
	 //if(date.curr_y>temp->exp_y)
	 if((date.curr_y-temp->pub_y)>=k)
	    {
	 temp=strat_ptr;
	 strat_ptr=strat_ptr->nxt;
	 cout<<"\n\n\tbook is deleted!";
	     delete temp;
	    }//end of if
    else
 cout<<"\n\n\tbook is not deleted!";
}
}


//////////////////////////////////
/////////////////////////////////
///////DELETE AT MIDDLE/////////
///////////////////////////////
  void delet_at_middle()
  {
     bstore*temp,*temp1,*temp2;

     cout<<"\n\n\n\tMiddle position";
	bstore date;
		struct dosdate_t d;
		_dos_getdate(&d);
		date.curr_d=d.day;
		date.curr_m=d.month;
		date.curr_y=d.year;
    int k;
	cout<<"\n\n\t How Old are the books u want to delete ? :";
	cin>>k;
//cout<<"\n\n\tcurrent date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;

    while(temp->nxt!=NULL)
     {
      //if(date.curr_y>temp->exp_y)
	  if((date.curr_y-temp->pub_y)>=k)
      {

       if(strat_ptr==NULL)
	  {
	     cout<<"\n\n\tNo book! ";
	   }
      else
	  {
	   temp2=strat_ptr;
	   temp1=temp2;
	   temp2=temp2->nxt;
	   temp1->nxt=temp2->nxt;
	   cout<<"\n\n\tBook is Deleted!";
	   delete temp2;
	      }
       }
   }
}

///////////////////////////////////
//////////////////////////////////
///////DELETE AT END/////////////
////////////////////////////////
///////////////////////////////
void delet_at_end()
{   bstore*current,*temp;
     current=strat_ptr;
     temp=current;

cout<<"\n\n\n\tEnd position";

	bstore date;
	struct dosdate_t d;
       _dos_getdate(&d);
	date.curr_d=d.day;
	date.curr_m=d.month;
	date.curr_y=d.year;
    int k;
	cout<<"\n\n\t How Old are the books u want to delete ? :";
	cin>>k;
//cout<<"\n\n\tcurrent date:"<<date.curr_d<<"/"<<date.curr_m<<"/"<<date.curr_y<<endl;;
    if(strat_ptr==NULL)
      cout<<"\n\n\n\t list is empty !!!\n";
	else
	 {
	  while(current->nxt!=NULL)
	  {
	       temp=current;
	   current=current->nxt;
	  }
	 //if(date.curr_y>current->exp_y)
	     if((date.curr_y-temp->pub_y)>=k)
	    {
	   temp->nxt=NULL;
	   cout<<"\n\n\tbook is Delete!";
	   delete current;
	    }
	 else
	   cout<<"\n\n\tbook is not expired!";
 }//end of else if
}//end of else
//end of function

//////////////////////////////
/////////////////////////////
////SEARCH FUNCTION/////////
///////////////////////////
//////////////////////////

int searchb()
{

bstore *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the ISBN to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->b_isbn)
   {
cout<<"\n\n\tBook Information ";
cout<<"USER NAME:"<<temp->u_name<<"\n\n";
cout<<"USER ID  :"<<temp->u_id<<"\n\n";
cout<<"GENDE   : "<<temp->gender<<"\n\n";
cout<<"SCHOOL NAME: "<<temp->school<<"\n\n";
cout<<"DEPARTMENT : "<<temp->dept<<"\n\n";
cout<<"ADRESS : "<<temp->address<<"\n\n";
cout<<"BOOK ISBN : "<<temp->b_isbn<<"\n\n";
cout<<"BOOK AUTHOR : "<<temp->author<<"\n\n";
cout<<"BOOK TITLE : "<<temp->title<<"\n\n";
cout<<"BOOK ISSUE DATE :"<<temp->d_i_b<<"/"<<temp->m_i_b<<"/"<<temp->y_i_b<<"\n\n";
//cout<<"BOOK ISSUED RETURN :"<<temp->d_r_b<<"/"<<temp->m_r_b<<"/"<<temp->y_r_b<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:Book not found!!!";

return temp->b_isbn;
//clrscr();
 }
//else

//cout<<"not found\n";
//}
//temp=temp->nxt;
   int searchr()
{

bstore *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"\nEnter the ISBN to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->b_isbn)
   {
cout<<"\n\n\tBook Information ";
cout<<"USER NAME:"<<temp->u_name<<"\n\n";
cout<<"USER ID  :"<<temp->u_id<<"\n\n";
cout<<"GENDE   : "<<temp->gender<<"\n\n";
cout<<"SCHOOL NAME: "<<temp->school<<"\n\n";
cout<<"DEPARTMENT : "<<temp->dept<<"\n\n";
cout<<"ADRESS : "<<temp->address<<"\n\n";
cout<<"BOOK ISBN : "<<temp->b_isbn<<"\n\n";
cout<<"BOOK AUTHOR : "<<temp->author<<"\n\n";
cout<<"BOOK TITLE : "<<temp->title<<"\n\n";
cout<<"BOOK ISSUE DATE :"<<temp->d_i_b<<"/"<<temp->m_i_b<<"/"<<temp->y_i_b<<"\n\n";
cout<<"BOOK ISSUED RETURN :"<<temp->d_r_b<<"/"<<temp->m_r_b<<"/"<<temp->y_r_b<<"\n\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:Book not found!!!";

return temp->b_isbn;
//clrscr();
 }

 /////////////////
 ////////////////
 //////////////////
 int searchbd()
{

bstore *temp;
temp=strat_ptr;

 bstore date;
 struct dosdate_t d;
_dos_getdate(&d);
 date.d_i=d.day;
 date.m_i=d.month;
 date.y_i=d.year;

 int found=0;
float code;
cout<<"\nEnter the ISBN to search\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->b_isbn)
   {
   cout<<"\n\n\tBook Information ";
   cout<<"BOOK ISBN"<<temp->b_isbn<<"\n\n";
   cout<<"BOOK TITLE  :"<<temp->title<<"\n\n";
   cout<<"AUTHOR OF BOOK   : "<<temp->author<<"\n\n";
   cout<<"NAME OF PUBLISHER ORGANIZATIOBN: "<<temp->pub_org<<"\n\n";
   cout<<"BOOK EDITION : "<<temp->edition<<"\n\n";
   cout<<"NUMBER OF COPIES : "<<temp->no_of_copy<<"\n\n";
   cout<<"BOOK DATE OF REGISTERD IN TOTO STACK : ";
   cout<<date.d_i<<"/"<<date.m_i<<"/"<<date.y_i<<"\n\n";
   cout<<"\n\ Date of Book Published : ";
   cout<<temp->pub_d<<"/"<<temp->pub_m<<"/"<<temp->pub_y;
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nError:Book not found!!!";

return temp->b_isbn;
//clrscr();
 }

  ///////////////////////////////////
  /////////////////////////////////
  ////////////DIPLAY//////////////
  ///////////////////////////////


  void displayb()
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
cout<<"\n\n\tBook Information ";
cout<<"USER NAME:"<<temp->u_name<<"\n\n";
cout<<"USER ID  :"<<temp->u_id<<"\n\n";
cout<<"GENDE   : "<<temp->gender<<"\n\n";
cout<<"SCHOOL NAME: "<<temp->school<<"\n\n";
cout<<"DEPARTMENT : "<<temp->dept<<"\n\n";
cout<<"ADRESS : "<<temp->address<<"\n\n";
cout<<"BOOK ISBN : "<<temp->b_isbn<<"\n\n";
cout<<"BOOK AUTHOR : "<<temp->author<<"\n\n";
cout<<"BOOK TITLE : "<<temp->title<<"\n\n";
cout<<"BOOK BORROW DATE :"<<temp->d_i_b<<"/"<<temp->m_i_b<<"/"<<temp->y_i_b<<"\n\n";
//cout<<"BOOK ISSUE RETURN :"<<temp->d_r_b<<"/"<<temp->m_r_b<<"/"<<temp->y_r_b<<"\n\n";
temp=temp->nxt;
}
}
while(temp!=NULL);

}


 //////////////////////////////////
 ///////////Return book//////////
 //////////////////////////////
void displayr()
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
cout<<"\n\n\tBook Information ";
cout<<"USER NAME:"<<temp->u_name<<"\n\n";
cout<<"USER ID  :"<<temp->u_id<<"\n\n";
cout<<"GENDE   : "<<temp->gender<<"\n\n";
cout<<"SCHOOL NAME: "<<temp->school<<"\n\n";
cout<<"DEPARTMENT : "<<temp->dept<<"\n\n";
cout<<"ADRESS : "<<temp->address<<"\n\n";
cout<<"BOOK ISBN : "<<temp->b_isbn<<"\n\n";
cout<<"BOOK AUTHOR : "<<temp->author<<"\n\n";
cout<<"BOOK TITLE : "<<temp->title<<"\n\n";
cout<<"BOOK ISSUE DATE :"<<temp->d_i_b<<"/"<<temp->m_i_b<<"/"<<temp->y_i_b<<"\n\n";
cout<<"BOOK ISSUE RETURN :"<<temp->d_r_b<<"/"<<temp->m_r_b<<"/"<<temp->y_r_b<<"\n\n";
temp=temp->nxt;
}
}
while(temp!=NULL);

}
 /////////////////////////////////
 //////////////display book information
 /////////////////////////
void displaybd()
{
bstore *temp;
temp=strat_ptr;
//temp=strat_ptr;
  bstore date;
  struct dosdate_t d;
 _dos_getdate(&d);
date.d_i=d.day;
date.m_i=d.month;
date.y_i=d.year;

do
{
if(temp==NULL)
{
cout<<"\n\n\tEnd of list\n\n";

}
else
{
cout<<"\n\n\tBook Information ";
cout<<"BOOK ISBN"<<temp->b_isbn<<"\n\n";
cout<<"BOOK TITLE  :"<<temp->title<<"\n\n";
cout<<"AUTHOR OF BOOK   : "<<temp->author<<"\n\n";
cout<<"NAME OF PUBLISHER ORGANIZATIOBN: "<<temp->pub_org<<"\n\n";
cout<<"BOOK EDITION : "<<temp->edition<<"\n\n";
cout<<"NUMBER OF COPIES : "<<temp->no_of_copy<<"\n\n";
cout<<"BOOK DATE OF REGISTERD IN TOTO STACK : ";
cout<<date.d_i<<"/"<<date.m_i<<"/"<<date.y_i<<"\n\n";
cout<<"\n\ Date of Book Published : ";
cout<<temp->pub_d<<"/"<<temp->pub_m<<"/"<<temp->pub_y;

temp=temp->nxt;
}
}
while(temp!=NULL);

}

void groupmember()
{
clrscr();
cout<<"\n\t_____________________________________________\n";
cout<<"\n\t______ DEVELOPERS OF THIS PROGRAM ___________\n";
cout<<"\n\t______ 1. ZEWD AYALEW       RCS160/11________\n";
cout<<"\n\t______ 2. ZIGJU DEMSSIE     RCS162/11________\n";
cout<<"\n\t______ 3. MEKDES BELETE     RCS165/11________\n";
cout<<"\n\t______ 4. YESHALEM ABRHA    RCS157/11________\n";
cout<<"\n\t______ 5. HABTAM MELESE     RCS051/11________\n";
cout<<"\n\t______ 6. DAMENECH DERGASO  RCS026/11________\n";
cout<<"\n\t_____________________________________________\n";
cout<<"\n\n\t press any key to continue ........\n";
getch();
}




/////////////////////////
////////////////////////
///// main function////
//////////////////////
/////////////////////
int main()
{
clrscr();
int n;
char ans,x;


c:  clrscr();
	 //gotoxy(26,28);

cout<<"WELCOME TO DU BOOk STORE MANAGEMENT SYSTEM \n\n\n";

delay(500);
cout<<"\n\t               =============";
cout<<"\n\t               =    MENU   =";
cout<<"\n\t=================================================";
cout<<"\n\t=  1.ADD BOOK                                   =";
cout<<"\n\t=  2.ADD BOOK END                               =";
cout<<"\n\t=  3.ADD BOOK AT MIDDLE                         =";
cout<<"\n\t=  4.ADD BOOK FRONT                             =";
cout<<"\n\t=  5.DISPLAY INFORMATION                        =";
cout<<"\n\t=  6.SEARCH BOOK                                =";
cout<<"\n\t=  7.DEVELOPERS OF THE PROGRAM                  =";
cout<<"\n\t=  8.EXIT                                       =";
cout<<"\n\t=  9.DELETE BOOK AT THE BEGINING                =";
cout<<"\n\t=  d.DELETE BOOK AT THE MIDDLE                  =";
cout<<"\n\t=  e.DELETE BOOK AT THE END                     =";
cout<<"\n\t=  a.BOOK ISSUE                                 =";
cout<<"\n\t=  b.BOOK RETURN                                =";
cout<<"\n\t=================================================";
cout<<"\n\t=  SELECT CHOICE HERE   =";
cout<<"\n\t=========================";
gotoxy(15,34);
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
exit(7);
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
exit(7);
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
exit(7);
break;
  case '5':
clrscr();
gotoxy(12,12);
char j;
cout<<"\n\n\t press q for display borrowed book\n";
cout<<"\n\n\t press r for display returned book\n";
cout<<"\n\n\t press s for display book information\n";
cin>>j;
if(j=='q')
{
clrscr();
displayb();
}
else if(j=='r')
{
clrscr();
displayr();
}
else if(j=='s')
{
clrscr();
displaybd();
 }
cout<<"\n\n\tdo u goto menu?(y/n)";
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
char v;
cout<<"\n\n\t press b for search borrowed book\n";
cout<<"\n\n\t press r for search returned book\n";
cout<<"\n\n\t press d for search book information\n";
cin>>v;
if(v=='b')
{
clrscr();
searchb();
}
else if(v=='r')
{
clrscr();
searchr();
}
else if(v=='d')
{
clrscr();
searchbd();
 }
cout<<"\n\n\tdo goto menu?(y/n)";
cin>>ans;

if(ans=='y')
goto c;
else if(ans=='n')
exit(8);
break;

/*case '7':
clrscr();
gotoxy(12,12);

chek_fine();
cout<<"do u want to go to menu?y/n";
cin>>ans;
if(ans=='y')
{
goto c;
}
else
exit(8);
 break;
 */
case '8':
clrscr();
exit(7);


break;

case '7':
groupmember();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
  goto c;//transfer controll goto key word.
else if(ans=='n')
   exit(0);
break;
case '9':
clrscr();
gotoxy(12,12);//    position cursor text window.
delet_at_start();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
  goto c;//transfer controll goto key word.
else if(ans=='n')
   exit(0);
break;

case 'd':
clrscr();
gotoxy(12,12);//    position cursor text window.
delet_at_middle();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
  goto c;//transfer controll goto key word.
else if(ans=='n')
   exit(0);
break;

case 'e':
clrscr();
gotoxy(12,12);//    position cursor text window.
delet_at_end();
cout<<"\n\n\tdo goto menu?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
  goto c;//transfer controll goto key word.
else if(ans=='n')
   exit(0);
break;
case 'a':
clrscr();
issue_date();
break;
case 'b':
clrscr();
return_date();
break;


default://
clrscr();
cout<<"\n\n\tError choice! ";
}
getch();
clrscr();
cout<<"\n\n\tDo you want to continue? (y/n) ";
cin>>ans;
if(ans=='y');
 goto c;//transfer control.
}
