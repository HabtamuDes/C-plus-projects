       #include<iostream.h>
       #include<conio.h>
       #include<process.h>

			   struct car
			   {
			   char name_car[24];
			   char name_type[24];
			   int code_car;
			   int speed;
			   int dist;
			   car*nxt;
			   };

       /*/*//*/*//////////////////////*/*/*/*///////
	       car*strat_ptr=NULL;
	       car*temp=new car;
			void add_car();
			void add_car_at_end();
			void add_car_at_middle(int m);
			void add_car_at_front();
			void delet_after_front();
			void search();
			void display();
		 ////////////////////////
	 void add_car() // record existing car information;
	   {

				car *temp2;
				car *temp=new car;
				clrscr();
      cout<<"\t PLEASE ENTER THE CAR INFORMATION\n";
      cout<<" NAME OF THE CAR:-   ";
      cin>>temp->name_car;
      cout<<" CAR TYPE :-";
      cin>>temp->name_type;
      cout<<" PLATE NUMBER OF CAR :-";
      cin>>temp->code_car;
cout<<" ENTRE SPEED OF CAR IN KM PER HOUR  :- ";
      cin>>temp->speed;
cout<<" ENTER THE DISTANCE THAT THE CAR WILL TRAVELL:-  ";
      cin>>temp->dist;
      temp->nxt=NULL;
			  if(strat_ptr==NULL)
			  {
			   strat_ptr=temp;
			    temp->nxt=strat_ptr;
			      }

		       else
		       temp2=strat_ptr;
		      while(temp2->nxt!=NULL)   {
		 temp2=temp2->nxt;               }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
		   }



  void add_car_at_end()
	  {
	     clrscr();
	      car *temp,*temp2;
	       temp=new car;
	 cout<<"\t YOU ARE ENTERING INFO AT THE END\n";
	 cout<<"\t PLEASE ENTER THE CAR INFORMATION\n";
      cout<<" NAME OF THE CAR:-   ";
      cin>>temp->name_car;
      cout<<" CAR TYPE :-";
      cin>>temp->name_type;
      cout<<" PLATE NUMBER OF CAR :-";
      cin>>temp->code_car;
cout<<" ENTRE SPEED OF CAR IN KM PER HOUR  :- ";
      cin>>temp->speed;
cout<<" ENTER THE DISTANCE THAT THE CAR WILL TRAVELL:-  ";
      cin>>temp->dist;

			temp->nxt=NULL;
		       temp2=strat_ptr;
		      while(temp2->nxt!=NULL)
		    {
		 temp2=temp2->nxt;
		  }
	      temp2->nxt=temp;
	    temp->nxt=NULL;
		   }

void add_car_at_middle(int m)
{
car *temp,*temp2;
temp=new car;
      cout<<"\t PLEASE ENTER THE CAR INFORMATION\n";
      cout<<" NAME OF THE CAR:-   ";
      cin>>temp->name_car;
      cout<<" CAR TYPE :-";
      cin>>temp->name_type;
      cout<<" PLATE NUMBER OF CAR :-";
      cin>>temp->code_car;
cout<<" ENTRE SPEED OF CAR IN KM PER HOUR  :- ";
      cin>>temp->speed;
cout<<" ENTER THE DISTANCE THAT THE CAR WILL TRAVELL:-  ";
      cin>>temp->dist;

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

void add_car_at_front()
{
car *temp,*temp2;
temp=new car;
temp2=strat_ptr;

      cout<<" PLEASE ENTER THE CAR INFORMATION\n";
      cout<<"NAME OF THE CAR :-  ";
      cin>>temp->name_car;
      cout<<"CAR TYPE :- ";
      cin>>temp->name_type;

      cout<<" PLATE NUMBER OF CAR :-";
      cin>>temp->code_car;
cout<<" ENTRE SPEED OF CAR IN KM PER HOUR :-";
      cin>>temp->speed;
cout<<" ENTER THE DISTANCE THAT THE CAR WILL TRAVELL :-";
      cin>>temp->dist;

 if(strat_ptr!=NULL)
 {
strat_ptr=temp;

temp->nxt=temp2;
  strat_ptr=temp;
     }
      }
  void delet_after_front()
  {
     car*temp1,*temp2;
temp2=strat_ptr;


  temp1=temp2;
temp2=temp2->nxt;


temp1->nxt=temp2->nxt;
 cout<<"\tCAR REMOVED!\n";
delete temp2;
       }
void search()
{

car *temp;
temp=strat_ptr;
 int found=0;
float code;
cout<<"ENTER THE PLATE NUMBER TO SEARCH\n";
cin>>code;

 while(temp!=NULL)
{
  if(code==temp->code_car)
   {
cout<<"CAR NAME:"<<temp->name_car<<"\n";
cout<<"CAR TYPE:"<<temp->name_type<<"\n";
cout<<"PLATE NUMBER:-  "<<temp->code_car<<"\n";
cout<<"CAR SPEED:"<<temp->speed<<"\n";
cout<<"CAR DISTANCE:"<<temp->dist<<"\n";
   found++;
   }
temp=temp->nxt;
  }
 if(found==0)
 cout<<"\nERROR:CAR CAN'T FOUND!!!";
 }
void developer()
{
cout<<"------------TRANSPORTATION SYSTEM OF DU--------------\n";
cout<< " GROUP MEMBERS    \t\t\t ID NUMBER     \n";
cout<<"\n1.TEWODROS SHAMBEL\t\t\t   RCS 142/11";
cout<<"\n2.TEWODROS AFEWORK\t\t\t   RCS 141/11";
cout<<"\n3.NESTANET NEWAY  \t\t\t   RCS 114/11";
cout<<"\n4.TADESSE MENGISTE\t\t\t   RCS 137/11";
cout<<"\n5.TEMESGEN BELELA \t\t\t   RCS 139/11";
cout<<"\n6.EYERUSALEM ABATE\t\t\t   RCS 164/11";
}

  void display()
{
temp=strat_ptr;

do
{
if(temp==NULL)
{
cout<<"\n\n\tEND OF LIST\n\n";

}
else
{
cout<<"\n\n\tcar ";
cout<<"NAME:"<<temp->name_car<<"\n";
cout<<"CAR TYPE:"<<temp->name_type<<"\n";
cout<<"CAR PLATE NUMBER:"<<temp->code_car<<"\n";
cout<<"CAR IN KM PER HOUR:"<<temp->speed<<"\n";
cout<<"CAR DISTANCE WILL TRAVELL:"<<temp->dist<<"\n";
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

c:
  clrscr();
cout<<"WELCOME TO CAR TRANSPORTATION SYSTEM \n";
cout<<"\n------------MENU----------------";
cout<<"\n  1.ADD CAR INFORMATION ";
cout<<"\n  2.ADD CAR AT END ";
cout<<"\n  3.ADD CAR AT MIDDLE ";
cout<<"\n  4.ADD CAR AT FORNT";
cout<<"\n  5.DISPLAY CAR INFORMATION ";
cout<<"\n  6.SEARCH CAR INFORMATION";
cout<<"\n  7.TO DELET AFTER FRONT";
cout<<"\n  8.Exit";
cout<<"\n  9.TO KNOW THE PROGRAMMERS";
cout<<"\n  SELECT YOUR CHOISE   ";
cin>>x;
switch(x)
{
case '1':
add_car();
cout<<"\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
if(ans=='y')
 goto c;//transfer controll goto key word.
else if(ans=='n')
   exit(0);
break;

case '2':
clrscr();
add_car_at_end();
cout<<"\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
 if(ans=='y'&& ans=='Y')
 goto c;
 else if(ans=='n'&& ans=='N')
exit(7);
break;
case '3':
clrscr();
cout<<"\tENTER THE POSITION";
cin>>n;

add_car_at_middle(n);

cout<<"\n\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
 if(ans=='y'&& ans=='Y')
 goto c;
 else if(ans=='n'&& ans=='N')
exit(7);
break;
case '4':
clrscr();
add_car_at_front();
cout<<"\n\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
 if(ans=='y'&& ans=='Y')
 goto c;
 else if(ans=='n'&& ans=='N')
 exit(7);
break;
  case '5':
//clrscr();
display();
cout<<"\n\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
clrscr();
 if(ans=='y'&& ans=='Y')
 goto c;
 else if(ans=='n'&& ans=='N')
exit(7);
break;
case '6':
clrscr();
search();
cout<<"\n\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
 if(ans=='y'&& ans=='Y')
 goto c;
 else if(ans=='n'&& ans=='N')
exit(8);
break;
case '7':
clrscr();
delet_after_front();
 break;
case '8':
clrscr();
exit(7);
break;
case '9':
clrscr();
developer();
cout<<"\n\tDO YOU  WANT TO GOTO MENU?(y/n)"<<endl;
cin>>ans;
 if(ans=='y'&& ans=='Y')
 goto c;
 else if(ans=='n'&& ans=='N')
exit(8);
break;
default:
clrscr();
cout<<"\n\n\tError choise! ";
}
getch();
clrscr();
cout<<"\n\n\tDo you want to continue? (y/n) ";
cin>>ans;
if(ans=='y'&& ans=='Y');
goto c;//transfer control.
}

