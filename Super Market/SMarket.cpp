#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#include<fstream.h>
#include<conio.h>
struct item
{
  char name[15];
  int price;
  char recv_date[15];
  char manif_date[15];
  char exp_date[15];
int generate_item(){//generate new item number
	int max=0;
	item newitem2;
	ifstream fin("true item data");
	if(!fin.fail())
	  {
		 fin.seekg(0,ios::beg);
		 while(!fin.eof())
			{
			  fin.read((char*)&newitem2,sizeof(newitem2));
			  if((newitem2.id)>max)
				 {
						max=newitem2.id;
				 }
			}
	 }
		 max++;
		 fin.close();
		 return max;
}//end of generate_item number
int id;
item()
{
  id=0;
}
void getdetails(int num=0){//to get item details
	  if(num==0){
	  id=generate_item();
		}else{
				id=num;
			  }
	  cout<<"the item number: "<<id<<endl;
	  cout<<endl<<"name of the item: ";
	  cin>>name;
	  cout<<endl<<"item price: ";
	  cin>>price;
	  cout<<endl<<"item recieved date: ";
	  cin>>recv_date;
	  cout<<endl<<"item manifactured date: ";
	  cin>>manif_date;
	  cout<<endl<<"item expiry date: ";
	  cin>>exp_date;
}//end 0of get details
void print_item(){//to display item
	  cout<<endl;
	  cout<<setw(40)<<"**********item number: "<<id<<"***************"<<endl;
	  cout<<setw(25)<<"\a*"<<"name: "<<setw(5)<<name<<endl;
	  cout<<setw(25)<<"\a*"<<"price: "<<setw(5)<<price<<endl;
	  cout<<setw(25)<<"\a*"<<"recieved date: "<<setw(5)<<recv_date<<endl;
	  cout<<setw(25)<<"\a*"<<"manifactured date: "<<setw(5)<<manif_date<<endl;
	  cout<<setw(25)<<"\a*"<<"expiry date: "<<setw(5)<<exp_date<<endl;
	  }//end of print item
};//end of struct
//******************global variables**********************
item newitem;
fstream filehandler;//opening afile in output mode
void show_item_details(){//details of the the item information
	  clrscr();
	 filehandler.close();
	 filehandler.open("true item data",ios::in);
	 filehandler.seekg(0,ios::beg);
	 cout<<endl<<"item list: ";
	 cout<<endl;
	 while(!(filehandler.eof())){
	 filehandler.read((char*)&newitem,sizeof(newitem));
	 if(!filehandler.eof()){
	 newitem.print_item();
	 }
	 cout<<endl;
	 getch();
	 }
}
void insert_data(){
	char ans;
	do{
		 filehandler.close();
		 newitem.getdetails();
		 filehandler.open("true item data",ios::app|ios::out|ios::in);
		 filehandler.write((char*)&newitem,sizeof(newitem));
		 cout<<endl<<"do you want to record more items? (y/n): ";
		 cin>>ans;
		 }while((ans=='y' || ans=='Y'));
}
int found_item(int num,item &newitem2){
	 filehandler.clear();
	 filehandler.seekg(0,ios::beg);
	 while(!filehandler.eof()){
	 filehandler.read((char*)&newitem2,sizeof(newitem2));
	 if(newitem2.id==num){
	 return 1;
	 }
	 }
	 return 0;
}
void delete_data(){
	 char ans;
	 item newitem2;
	 item temp;
	 int num;
	 cout<<endl<<"enter the item number: ";
	 cin>>num;
	 if(found_item(num,newitem2)){
	 newitem2.print_item();
	 cout<<endl<<"do you want to delete the current record? (y/n): ";
	 cin>>ans;
	 if(ans=='y'||ans=='Y'){
	 filehandler.close();
	 ifstream filehandler1("true item data");
	 ofstream filehandler2("temp_item");
	 filehandler.seekg(0,ios::beg);
	 while(!filehandler1.eof()){
	 filehandler1.read((char*)&newitem,sizeof(newitem));
	 if(!(newitem2.id==newitem.id)&&!(filehandler1.eof())){
	 filehandler2.write((char*)&newitem,sizeof(newitem));
	 }
	 }
	 filehandler2.close();
	 filehandler1.close();
	 filehandler1.open("temp_item");
	 filehandler2.open("true item data");
	 filehandler1.seekg(0,ios::beg);
	 while(!filehandler1.eof()){
	 newitem.id=0;
	 filehandler1.read((char*)&newitem,sizeof(newitem));
	 if(!(newitem.id==0)){
	 filehandler2.write((char*)&newitem,sizeof(newitem));
	 }
	 }
	 filehandler2.close();
	 filehandler1.close();
	 filehandler.open("true item data",ios::app|ios::out|ios::in);
	 }
	 }else{
			 cout<<"ERROR...item not found !!!";
			}
}
void search(){
		 clrscr();
	 item newitem2;
	 int num;
	 cout<<endl<<"enter the item number: ";
	 cin>>num;
	 if(found_item(num,newitem2))
	 {
	 newitem2.print_item();
	 }else{
			  cout<<endl<<"ERROR...item not found !!!"<<endl;
			}
			getch();
}
void update_data(){
	 char ans;
	 int num;
	 item newitem2,newobj;
	 cout<<endl<<"enter the item number to update: ";
	 cin>>num;
	 if(found_item(num,newitem2)){
	 cout<<endl<<"item details: ";
	 newitem2.print_item();
	 newobj.getdetails(num);
	 cout<<endl<<"do you want to update the current record? (y/n): ";
	 cin>>ans;
	 if(ans=='y'||ans=='Y'){
	 filehandler.close();
	 ifstream filehandler1("true item data");
	 ofstream filehandler2("temp_item");
	 filehandler.seekg(0,ios::beg);
	 while(!filehandler1.eof()){
	 newitem.id=0;
	 filehandler1.read((char*)&newitem,sizeof(newitem));
	 if(!(newitem2.id==newitem.id)&&!(filehandler1.eof())){
	 filehandler2.write((char*)&newitem,sizeof(newitem));
	 }else{
			  if(!(newitem2.id==newitem.id)){
			  filehandler2.write((char*)&newitem,sizeof(newitem));
			}
				}
	 }
	 filehandler2.close();
	 filehandler1.close();
	 filehandler1.open("temp_item");
	 filehandler2.open("true item data");
	 filehandler1.seekg(0,ios::beg);
	 while(!filehandler1.eof()){
	 newitem.id=0;
	 filehandler1.read((char*)&newitem,sizeof(newitem));
	 if(!(newitem.id==0)){
	 filehandler2.write((char*)&newitem,sizeof(newitem));
	 }
	 }
	 filehandler2.close();
	 filehandler1.close();
	 filehandler.open("true item data",ios::app|ios::out|ios::in);
	 }
	 }else{
			  cout<<"ERROR...item not found !!!"<<endl;
			}
}
void developers(){
clrscr();
cout<<endl<<"developers: \n\n";
cout<<endl<<"1.SAMUEL TESFAYE    RCS 126/11\n\n";
cout<<endl<<"2.SULTAN AMAN       RCS 136/11\n\n";
cout<<endl<<"3.SEADA SEID        RCS 129/11\n\n";
cout<<endl<<"4.NEBIAT S/DENGIL   RCS 099/11\n\n";
cout<<endl<<"5.LETA DEKEBO       RCS070/11\n";
cout<<endl<<"6.MULUGETA TESHOME  RCS096/119\n";
getch();
 }
int main(){
	 int choice;
	 filehandler.open("true item data",ios::in|ios::app|ios::out);
	 do{
		  cout<<endl<<"WELL-COME TO SENAIT SUPEMARKET";
		  cout<<endl<<setw(60)<<"8888888888888888888888888888888888888\n";
		  cout<<endl<<setw(60)<<"@              MENU                 @\n";
		  cout<<endl<<setw(60)<<"8888888888888888888888888888888888888\n";
		  cout<<endl<<setw(60)<<"@        1.RECORD NEW ITEM          @\n";
		  cout<<endl<<setw(60)<<"@        2.DELETE ITEM              @\n";
		  cout<<endl<<setw(60)<<"@        3.UPDATE ITEM INFORMATION  @\n";
		  cout<<endl<<setw(60)<<"@        4.THE COMPLETE ITEM LIST   @\n";
		  cout<<endl<<setw(60)<<"@        5.SEARCH FOR AGIVEN ITEM   @\n";
		  cout<<endl<<setw(60)<<"@        6.DEVELOPERS               @\n";
		  cout<<endl<<setw(60)<<"@        0.EXIT                     @\n";
		  cout<<endl<<setw(60)<<"8888888888888888888888888888888888888\n";
		  cout<<endl<<"select your choice: ";
		  cin>>choice;
		  switch(choice){
		  case 1:
		  filehandler.clear();
		  insert_data();
		  break;
		  case 2:
		  filehandler.clear();
		  delete_data();
		  break;
		  case 3:
		  filehandler.clear();
		  update_data();
		  break;
		  case 4:
		  filehandler.clear();
		  show_item_details();
		  break;
		  case 5:
		  filehandler.clear();
		  search();
		  break;
		  case 6:
		  filehandler.clear();
		  developers();
		  break;
		  case 0:
		  filehandler.clear();
		  filehandler.close();
		  exit(0);
		  defualt:
        }//end of switch
		}while(1);
		  return 0;
}//end of main

