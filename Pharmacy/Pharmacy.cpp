#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#include<fstream.h>
#include<conio.h>
struct drug
{
  char name[25];
  int price;
  char recv_date[25];
  char manif_date[25];
  char exp_date[25];
  int create_drug(){
  int str=0;
  drug newdrug2;
  ifstream fin("drug information");
  if(!fin.fail())
  {
  fin.seekg(0,ios::beg);
  while(!fin.eof())
  {
  fin.read((char*)&newdrug2,sizeof(newdrug2));
  if((newdrug2.id)>str)
  {
  str=newdrug2.id;
  }
  }
 }
 str++;
 fin.close();
 return str;
}
int id;
drug()
{
id=0;
}
void getdetails(int num=0){
if(num==0){
id=create_drug();
}else{
id=num;
	}
 cout<<"drug number: "<<id<<endl;
 cout<<endl<<"name of the drug: ";
 cin>>name;
 cout<<endl<<"drug price: ";
 cin>>price;
 cout<<endl<<"drug recieved date: ";
 cin>>recv_date;
 cout<<endl<<"drug manifactured date: ";
 cin>>manif_date;
 cout<<endl<<"drug expiry date: ";
 cin>>exp_date;
}
void print_drug(){
	  cout<<endl;
	  cout<<setw(25)<<"drug number: "<<id<<endl;
	  cout<<setw(15)<<"name: "<<setw(5)<<name<<endl;
	  cout<<setw(15)<<"price: "<<setw(5)<<price<<endl;
	  cout<<setw(25)<<"recieved date: "<<setw(5)<<recv_date<<endl;
	  cout<<setw(25)<<"manifactured date: "<<setw(5)<<manif_date<<endl;
	  cout<<setw(25)<<"expiry date: "<<setw(5)<<exp_date<<endl;
	  }
};
drug newdrug;
fstream file;
void show_drug_details(){
	  clrscr();
	 file.close();
	 file.open("drug information",ios::in);
	 file.seekg(0,ios::beg);
	 cout<<endl<<"drug list: ";
	 cout<<endl;
	 while(!(file.eof())){
	 file.read((char*)&newdrug,sizeof(newdrug));
	 if(!file.eof()){
	 newdrug.print_drug();
	 }
	 cout<<endl;
	 getch();
	 }
}
void insert_data(){
	char ans;
	do{
		 file.close();
		 newdrug.getdetails();
		 file.open("drug information",ios::app|ios::out|ios::in);
		 file.write((char*)&newdrug,sizeof(newdrug));
		 cout<<endl<<"do you want to record more drugs? (y/n): ";
		 cin>>ans;
		 }while((ans=='y' || ans=='Y'));
}
int found_drug(int num,drug &newdrug2){
	 file.clear();
	 file.seekg(0,ios::beg);
	 while(!file.eof()){
	 file.read((char*)&newdrug2,sizeof(newdrug2));
	 if(newdrug2.id==num){
	 return 1;
	 }
	 }
	 return 0;
}
void delete_data(){
	 char ans;
	 drug newdrug2;
	 drug temp;
	 int num;
	 cout<<endl<<"enter the drug number: ";
	 cin>>num;
	 if(found_drug(num,newdrug2)){
	 newdrug2.print_drug();
	 cout<<endl<<"do you want to delete the current record? (y/n): ";
	 cin>>ans;
	 if(ans=='y'||ans=='Y'){
	 file.close();
	 ifstream file1("drug information");
	 ofstream file2("temp_drug");
	 file.seekg(0,ios::beg);
	 while(!file1.eof()){
	 file1.read((char*)&newdrug,sizeof(newdrug));
	 if(!(newdrug2.id==newdrug.id)&&!(file1.eof())){
	 file2.write((char*)&newdrug,sizeof(newdrug));
	 }
	 }
	 file2.close();
	 file1.close();
	 file1.open("temp_drug");
	 file2.open("drug information");
	 file1.seekg(0,ios::beg);
	 while(!file1.eof()){
	 newdrug.id=0;
	 file1.read((char*)&newdrug,sizeof(newdrug));
	 if(!(newdrug.id==0)){
	 file2.write((char*)&newdrug,sizeof(newdrug));
	 }
	 }
	 file2.close();
	 file1.close();
	 file.open("drug information",ios::app|ios::out|ios::in);
	 }
	 }else{
			 cout<<"drug not found !!!";
			}
}
void search(){
		 clrscr();
	 drug newdrug2;
	 int num;
	 cout<<endl<<"enter the drug number: ";
	 cin>>num;
	 if(found_drug(num,newdrug2))
	 {
	 newdrug2.print_drug();
	 }else{
			  cout<<endl<<"drug not found !!!"<<endl;
			}
			getch();
}
void update_data(){
	 char ans;
	 int num;
	 drug newdrug2,newobj;
	 cout<<endl<<"enter the drug number to update: ";
	 cin>>num;
	 if(found_drug(num,newdrug2)){
	 cout<<endl<<"drug details: ";
	 newdrug2.print_drug();
	 newobj.getdetails(num);
	 cout<<endl<<"do you want to update the current record? (y/n): ";
	 cin>>ans;
	 if(ans=='y'||ans=='Y'){
	 file.close();
	 ifstream file1("drug information");
	 ofstream file2("temp_drug");
	 file.seekg(0,ios::beg);
	 while(!file1.eof()){
	 newdrug.id=0;
	 file1.read((char*)&newdrug,sizeof(newdrug));
	 if(!(newdrug2.id==newdrug.id) && !(newdrug.id==0)){
	 file2.write((char*)&newdrug,sizeof(newdrug));
	 }else{
			  if(!(newdrug2.id==newdrug.id)){
			  file2.write((char*)&newobj,sizeof(newobj));
			}
			}
			}
	 file2.close();
	 file1.close();
	 file1.open("temp_drug");
	 file2.open("drug information");
	 file1.seekg(0,ios::beg);
	 while(!file1.eof()){
	 newdrug.id=0;
	 file1.read((char*)&newdrug,sizeof(newdrug));
	 if(!(newdrug.id==0)){
	 file2.write((char*)&newdrug,sizeof(newdrug));
	 }
	 }
	 file2.close();
	 file1.close();
	 file.open("drug information",ios::app|ios::out|ios::in);
	 }
	 }else{
			cout<<"drug not found !!!"<<endl;
			}
}
int main(){
	 int choice;
	 file.open("drug information",ios::in|ios::app|ios::out);
	 do{
		  cout<<endl<<"WHAT DO YOU WANT TO DO???";
		  cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		  cout<<endl<<"@              MENU                      @\n";
		  cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		  cout<<endl<<"@        1.RECORD NEW DRUG               @\n";
		  cout<<endl<<"@        2.DELETE DRUG                   @\n";
		  cout<<endl<<"@        3.UPDATE DRUG INFORMATION       @\n";
		  cout<<endl<<"@        4.SHOW THE COMPLETE DRUG LIST   @\n";
		  cout<<endl<<"@        5.SEARCH FOR ASPECIFIC DRUG     @\n";
		  cout<<endl<<"@        0.EXIT                          @\n";
		  cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		  cout<<endl<<"select your choice: ";
		  cin>>choice;
		  switch(choice){
		  case 1:
		  file.clear();
		  insert_data();
		  break;
		  case 2:
		  file.clear();
		  delete_data();
		  break;
		  case 3:
		  file.clear();
		  update_data();
		  break;
		  case 4:
		  file.clear();
		  show_drug_details();
		  break;
		  case 5:
		  file.clear();
		  search();
		  break;
		  case 0:
		  file.clear();
		  file.close();
		  exit(0);
		  }
		}while(1);
		  return 0;
}
