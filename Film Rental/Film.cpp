#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
const int max=80;
int y;

struct film
{
char tittle[max];
char  type[max];
char address[max];
char f_name[max];
char l_name[max];
int dd,mm,yy,qnty,y,chan,clmn,row;
film*nxt;
};

film*first=NULL;
film*first1=NULL;
film*first2=NULL;

int f_rec()
{
		cont:
		film*add=new film;
		cout<<"\n WHEN YOU ENTER A DATA INTO A FILE REPLACE SPACE WITH A DOT\n";
		cout<<"ENTER THE TITTLE OF THE FILM:\n" ;
		cin>>add->tittle;
		cout<<"ENTER THE NAME OF THE ACTER:\n";
		cout<<"FIRST NAME:\n";
		cin>>add->f_name;
		cout<<"ENTER THE LASTNAME:\n";
		cin>>add->l_name;
		cout<<"ENTER THE PLACE WHERE YOU ORDER:\n";
		cout<<"COLUMN\n";
		cin>>add->clmn;
		cout<<"ROW\n";
		cin>>add->row;
		cout<<"ENTER THE DAY OF THE FILM BOUGHT\n";
		cout<<" DAY:\n";
		cin>>add->dd;
		cout<<" MONTH:\n" ;
		cin>>add->mm;
		cout<<" YEAR:\n";
		cin>>add->yy;
		cout<<"ENTER THE TYPE OF THE FILM:\n";
		cin>>add->type; //ACTION,HORRER OR WHAT ELSE
		cout<<"ENTER THE QUANTITY OF THE FILM:\n";
		cin>>add->qnty;
		add->nxt=first;
		first=add;
		cout<<"IF YOU WENT TO SAVE PRESS(1)FOR YES OTHERWISE PRESS(0)FOR NO\n";
		cin>>y;
		if(y==1)
{
		ofstream ad("film.txt",ios::out|ios::app);
		if(ad.good())
{
		ad<<"TITTLE\n"<<add->tittle<<endl;
		ad<<"ACTOR NAME\n"<<add->f_name<<" ";
		ad<<add->l_name<<endl;
		ad<<"COLUMN\n"<<add->clmn<<",";
		ad<<"ROW"<<add->row<<endl;
		ad<<"DATE\n"<<add->dd<<"-";
		ad<<add->mm<<"-";
		ad<<add->yy<<endl;
		ad<<"FILM TYPE\n"<<add->type<<endl;
		ad<<"QUANTITY\n"<<add->qnty<<endl;
		ad<<"end\n";
		ad.close();
}
		else
		cout<<"UNABLE TO OPEN";
}
		con:
		cout<<"IF YOU WENT TO CONTINUOE PRESS(1)FOR YES OTHERWISE PRESS(0)FOR NO\n";
		cin>>y;
		clrscr();
		if(y==1)
		goto cont;
		else if(y!=0 &&y!=1)
{
		cout<<"ENTER EITHER 1 OR 0\n";
		goto con;
}
		else
		return 0;
}

int o_rec()
{
		cont:
		film*add=new film;
		cout<<"\n WHEN YOU ENTER A DATA INTO A FILE REPLACE SPACE WITH A DOT\n";
		cout<<"ENTER THE TITTLE OF THE CASSET\n" ;
		cin>>add->tittle;
		cout<<"ENTER THE TYPE OF THE CASSET\n" ;//MUSIC,DRAMA OR WHAT ELSE
		cin>>add->type;
		cout<<"ENTER THE DAY OF THE CASSET BOUGHT\n";
		cout<<"DAY:\n";
		cin>>add->dd;
		cout<<"MONTH:\n" ;
		cin>>add->mm;
		cout<<"YEAR\n";
		cin>>add->yy;
		cout<<"ENTER THE QUANTITY OF THE FILM\n";
		cin>>add->qnty;
		add->nxt=first;
		first1=add;
		cout<<"if you went to save press(1)for yes either press(0)for no";
		cin>>y;
		if(y==1)
{
		ofstream ad("film.txt",ios::out|ios::app);
		if(ad.good())
	{
		ad<<"TITTLE\n"<<add->tittle<<endl;
		ad<<"FILM TYPE\n"<<add->type<<endl;
		ad<<"DATE\n"<<add->dd<<"-";
		ad<<add->mm<<"-";
		ad<<add->yy<<endl;
		ad<<"QUANTITY\n"<<add->qnty<<endl;
		ad<<"end\n";
		ad.close();
	}
		else
		cout<<"unable to open";
	}
		clrscr();
		con:
		cout<<"IF YOU WENT TO CONTINUOE PRESS(1)FOR YES OTHERWISE PRESS(0)FOR NO\n";
		cin>>y;
		clrscr();
		if(y==1)
		goto cont;
		else if(y!=0 &&y!=1)
{
		cout<<"ENTER EITHER 1 OR 0\n";
		goto con;
}
		else
		return 0;
}
		int ren_pro()
{
		float chan;
		cont:
		ofstream ad("renting.txt",ios::out|ios::app);
		if(ad.good())
{
		film*add=new film;
		cout<<"\tWHEN YOU ENTER A DATA INTO A FILE REPLACE SPACE WITH A DOT\n";
		cout<<"ENTER THE DAY OF THE CASSET RENT\n";
		cout<<"DAY:\n";
		cin>>add->dd;
		ad<<"DATE:\n"<<add->dd<<"-";
		cout<<"MONTH\n" ;
		cin>>add->mm;
		ad<<add->mm<<"-";
		cout<<"YEAR:\n";
		cin>>add->yy;
		ad<<add->yy<<endl;
		cout<<"ENTER THE CUSTOMER FIRST NAME\n";
		cin>>add->f_name;
		ad<<"THE CUSTOMER NAME\n"<<add->f_name<<" ";
		cout<<"ENTER THE CUSTOMER LAST NAME\n";
		cin>>add->l_name;
		ad<<add->l_name<<endl;
		cout<<"ENTER THE CUSTOMER ADDRESS\n";
		cin>>add->address;
		ad<<"THE CUSTOMER ADDRESS\n"<<add->address<<endl;
		cout<<"HOW MANY CASSET S/HE RENT\n";
		cin>>y;
		for(int i=1;i<=y;i++)
{
		cout<<"ENTER THE TITTLE OF THE "<<i<<" FILM:\n";
		cin>>add->tittle;
		ad<<"THE TITTLE OF THE "<<i<<" FILM:\n"<<add->tittle<<endl;
}
		cout<<"CUSTOMER CHANGE(BIRR)\n";
		cin>>add->chan;
		ad<<"CUSTOMER CHANGE(BIRR)\n"<<add->chan<<endl;
		ad<<"end\n";
		ad.close();
}

		cout<<"UNABLE TO OPEN";
		clrscr();
		con:
		cout<<"IF YOU WENT TO CONTINUOE PRESS(1)FOR YES OTHERWISE PRESS(0)FOR NO\n";
		cin>>y;
		if(y==1)
		goto cont;
		else if(y!=0 &&y!=1)
{
		cout<<"ENTER EITHER 1 OR 0\n";
		goto con;
}
		else
		return 0;
}

int del()
{
		char ch[max],a[max],b[max];
		int c;
		cout<<"\n WHEN YOU ENTER A DATA INTO A FILE REPLACE SPACE WITH A DOT\n";
		cout<<"ENTER THE TITTLE\n";
		cin>>a;                                                                        	 int f=0;
		ofstream add("temp.txt",ios::out,ios::binary);
		ifstream ad("film.txt",ios::in,ios::binary);
		if(ad.good())
 {
		add.clear();
		ad.seekg (0, ios::beg);
		while(!ad.eof())
	{
		ad.getline((char*)ch,max);
		c=strncmp(a,ch,4);
		if(c!=0)
		{
		do{
		if(add.good())
				{
		ad.getline((char*)ch,max);
		add<<ch<<endl;
		c=strncmp(ch,"end",3);
				}
		else
		cout<<"unable to open add";
} 		while(!ad.eof() &&c!=0);
		}
}
		ad.close();
		add.close();
		ifstream add("temp.txt",ios::in,ios::binary);
		ofstream ad("film.txt",ios::out,ios::binary);
		add.seekg (0, ios::beg);
		while(!ad.eof())
	{
		add.getline((char*)ch,max);
		ad<<ch<<endl;
		}
		ad.close();
		add.close();
	}
		else
		cout<<"unable to open ad";
		cout<<"\n";
		return 0;
}
int sear()
{
		char ch[max],a[max];
		int size=max,c;
		cout<<"\n WHEN YOU ENTER A DATA INTO A FILE REPLACE SPACE WITH A DOT\n";
		cout<<"ENTER THE TITTLE\n";
		cin>>a;
		ifstream ad("film.txt",ios::in,ios::binary);
		if(ad.good())
 {
		ad.seekg (0, ios::beg);
		while(!ad.eof())
	{
		ad.getline(ch,size);
		c=strncmp(a,ch,4);
		if(c==0)
	  {
		cout<<ch<<endl;
		do
		 {
		ad.getline(ch,size);
		cout<<"          "<<ch<<endl;
		c=strncmp(ch,"end",4);
 }		while(!ad.eof() &&c!=0);
	 } }
		ad.close();
  }
		else
		cout<<"unable to open";
		return 0;
}
int Sdisp()
{
		char ch[max],a[max];
		int size=max,c;
		cout<<"\n WHEN YOU ENTER A DATA INTO A FILE REPLACE SPACE WITH A DOT\n";
		cout<<"ENTER THE DATE LIKE(_ - _ - _)\n";
		cin>>a;
		ifstream ad("renting.txt",ios::in);
		if(ad.good())
 {
		ad.seekg (0, ios::beg);
		while(!ad.eof())
	{
		ad.getline(ch,size);
		c=strncmp(a,ch,5);
		if(c==0)
	  {
		cout<<ch<<endl;
		do
		 {
		ad.getline(ch,size);
		cout<<"          "<<ch<<endl;
		c=strncmp(ch,"end",4);
	  }while(!ad.eof() &&c!=0);
	 } }
		ad.close();
  }
		else
		cout<<"unable to open";
		return 0;
}
void Adisp()
{
		char ch[max];
		int size=max;
		ifstream ad("renting.txt",ios::in);
		if(ad.good())
{
		ad.seekg (0, ios::beg);
		cout<<endl;
		while(!ad.eof())
{
		ad.getline(ch,size);
		cout<<ch<<endl;
}
		ad.close();
}
		else
		cout<<"unable to open";
}
void developer()
{
cout<<"GROUP MEMBER           \t ID         \n";
cout<<"\n\n1.JEMAL EBARAHIM \t RCS-066/11 \n";
cout<<"\n\n2.MOHAMMED NESRO \t RCS-092/11 \n";
cout<<"\n\n3.NURHUSEN ADEM \t RCS-115/11 \n";
cout<<"\n\n4.OUMEREDIN ENDRIS \t RCS-116/11 \n";
cout<<"\n\n5.SIRAGE WODAGE \t RCS-134/11 \n ";
}
		int main()
{
		int x;
		cout<<"==============WEL-COME TO LIYU AUDIO VIDEO CENTER==============\n";
		start:
		cout<<"PRESS 1-FOR RECORDING\n";
		cout<<"PRESS 2-FOR SEARCHING\n";
		cout<<"PRESS 3-FOR RENTING PROSSES\n";
		cout<<"PRESS 4-FOR DISPLAYING UNRETURNED CUSTUMER NAME\n";
		cout<<"PRESS 5-FOR DELETING\n";
		cout<<"PRESS 6-FOR PROGRAMMER\n";
		cout<<"PRESS 0-FOR TERMINATE\n";
		start1:
		cout<<"ENTER YOUR CHOISE(1-4)\n";
		cin>>x;
		clrscr();
		if(x==0)
		return 0;
		else if(x==1)
{
		cout<<"PRESS 1-FOR RECORDING FILM\n";
		cout<<"PRESS 2-FOR RECORDING OTHER\n" ;
		pnt:
		cout<<"ENTER YOUR CHOISE(1-2)\n";
		cin>>x;
		clrscr();
		if(x==1)
{
		f_rec();
		goto start;
}
		else if(x==2)
{
		o_rec();
		goto start;
}
		else
		goto pnt;
}
		else if(x==2)
{
		sear();
		goto start;
}
		else if(x==3)
{
		ren_pro();
		goto start;
}
		else if(x==4)
{
		cout<<"PRESS 1-FOR DISPLAYING ALL\n";
		cout<<"PRESS 2-FOR DISPLAYING SPECIFIC INFORMATION\n" ;
		pnt1:
		cout<<"ENTER YOUR CHOISE(1-2)\n";
		cin>>x;
		clrscr();
		if(x==1)
		{
		Adisp();
		goto start;
		}
		else if(x==2)
		{
		Sdisp();
		goto start;
		}
		else
		goto pnt1;
}
		else if(x==5)
{
		del();
		goto start;
}
		else if(x==6)
		developer();
		else
		goto start1;
		return 0;
}

