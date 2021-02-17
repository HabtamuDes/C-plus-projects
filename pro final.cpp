/* GROUP MEMBER
1.NATNAEL MEKONEN
2.MOHAMMED BASHIR
3.ROBEL ARAMSA
               SOURCE CODE BY NATNAEL MEKONEN
               SECTION B
    */

#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>

using namespace std;

char ch ='/';
void menuforitem();
void menuforsale();
void menuforpurchase();
void  menuforsearch();
void   menuforpurchasesearch();
void menuforsalesearch();
void report();
void saveSale();
void save_Item();
void savePurchase();
void menu_FOR_RECORD();
int getpurchesitemid();
float show_over_all_total_for_sale();
void profit();
void edit_Item();
void edit_Sale();
void Newitemchioce(int itemid);
void edit_Purchase();
int menu();
void date1();
int showquantity(int num);
void Newitemchioce(int itemid);
float showpriceitem(int num);
float showdiscount(int num);
int getsalenumber();

int main()
{
   char exitchoice;
 date1();
 menu();
return 0;
}

int menu(){
   char exitchoice;
 system("cls");
   int option;
	cout<<"\n\t\tThank you for using our program I hope you liked it.\n\n";
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to ITEM";
	cout<<"\n\tPress 2 to PURCHASE";
	cout<<"\n\tPress 3 to SOLD ";
	cout<<"\n\tPress 4 to RECORD";
	cout<<"\n\tPress 5 to EXIT";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;


	switch(option)
	{
		case 1: system("cls");
                menuforitem();
                break;

		case 2: system("cls");
		        menuforpurchase();
		        break;

        case 3: system("cls");
		        menuforsale();
				break;

         case 4: system("cls");
		       menu_FOR_RECORD();
				break;
         case 5: system("cls");
                cout<<"Are you sure you want to exit. press Y/N >>  " ;
                cin>>exitchoice;
                if(exitchoice=='Y'||exitchoice=='y')
                {
                    system("cls");
                    cout<<setw(20)<<"\n\n\n\tGOOD BYE\n\n\n\t"<<setw(20)<<endl;
                    exit(0);
                                }
                else menu();

                break;

            default :cout<<"Invalid Input...\n";
	 }

return 0;


}




struct date
{
    int mm,dd,yy;
};

struct Item
{
	int itemId,avaliQuantity;
	char itemName[100],itemLocation[100];
	float unitPrice,itemDiscount;
};
Item It;


void AddnewItem()
	{
		cout<<endl<<"Please Enter The Item Number: ";
		cin>>It.itemId;
		Newitemchioce(It.itemId);
	}

void Returntomainboard()
{
    char chioce;

cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    save_Item();
    }
else  menu();

}


		void show_product()
	{
		cout<<endl<<"Item #: "<<setw(15)<<"Item Name: "<<setw(15)<<"Location : "<<setw(15)<<"Price :"<<setw(15)<<"Quantity : "<<setw(15)<<"Discount : "<<endl;
		cout<<endl<<It.itemId<<setw(15)<<It.itemName<<setw(15)<<It.itemLocation<<setw(15)<<It.unitPrice<<setw(15)<<showquantity(It.itemId)-getsalenumber()<<setw(15)<<It.itemDiscount<<endl;

	Returntomainboard();

	}



    int getProduct()
	{

		return It.itemId;
	}

	float getPrice()
	{
		return It.unitPrice;
	}

	char* getName()
	{
		return It.itemName;
	}
	char* getlocation()
	{
	    return It.itemLocation;
	}

	float getDiscount()
	{
		return It.itemDiscount;
	}
	int getnumber()
	{
	    return showquantity(It.itemId);
	}


fstream fp;

void save_Item()
{
    char chioce;
	fp.open("Item.bin",ios::out|ios::app);
	 AddnewItem();
	fp.write((char*)&It,sizeof(Item));
	show_product();
	fp.close();
	cout<<endl<<endl<<"The Product Has Been Successfully Created...";
	getchar();

Returntomainboard();
}

void searchByItemId(int num)
{
    char chioce;
	bool found=false;
	fp.open("Item.bin",ios::in);
	while(fp.read((char*)&It,sizeof(Item)))
	{
		if(getProduct()==num)
		{
			system("cls");
			show_product();
			//found=true;
		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();

 cout<<"\n GOOD BYE"<<endl;
 exit(0);

}

void searchByItemName(string name)
{
    char chioce;
	bool found=false;
	fp.open("Item.bin",ios::in);
	while(fp.read((char*)&It,sizeof(Item)))
	{
		if(getName() == name)
		{
			system("cls");
			show_product();

		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
exit(0);

}

void searchByItemlocation(string location)
{
    char chioce;
	bool found=false;
	fp.open("Item.bin",ios::in);
	while(fp.read((char*)&It,sizeof(Item)))
	{
		if(getlocation()==location)
		{
			system("cls");
			show_product();

		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
cout<<"\n GOODBYE "<<endl;
exit(0);

}

void edit_Item()
{
    char chioce;
	int num;
	bool found=false;
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The Item #: ";
	cin>>num;

	fp.open("Item.bin",ios::in|ios::out);
	while(fp.read((char*)&It,sizeof(Item)) && found==false)
	{
		if(getProduct()==num)
		{
			//show_product();
			cout<<"\nPlease Enter The New Details of Product: "<<endl;
            AddnewItem();
			int pos=-1*sizeof(It);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&It,sizeof(Item));
			cout<<endl<<endl<<"\t Record Successfully Updated...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"Record Not Found...";
getchar();

cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    edit_Item();
    }
else menu();

}
void  menuforsearch()
{
    int X;
    string one,two;
	system("cls");
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to SEARCH BY ID";
	cout<<"\n\tPress 2 to SEARCH BY NAME";
	cout<<"\n\tPress 3 to SEARCH BY LOCATION";
	cout<<"\n\tPress 4 to GET BACK TO MAIN BOARD";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				cout<<"Please Enter Item Id : ";
				cin>>X;
				searchByItemId(X);
				break;

		case 2: system("cls");
		        cout<<"Please Enter Item Name : ";
		        cin>>one;
		        searchByItemName(one);
				break;

		case 3:system("cls");
		       cout<<"Please Enter Item Location : ";
		        cin>>two;
		        searchByItemlocation(two);
                break;
		case 4:system("cls");
		       menu();
                break;

		default :cout<<"Invalid Input...\n";

	}

}
void  menuforitem()
{
	system("cls");
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to ADD NEW ITEM";
	cout<<"\n\tPress 2 to SEARCH";
	cout<<"\n\tPress 3 to EDIT ";
	cout<<"\n\tPress 4 to BACK TO MAIN SWITCH BOARD";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				save_Item();
            break;

		case 2: system("cls");
		        menuforsearch();
				break;

		case 3:system("cls");
		        edit_Item();
				break;

         case 4:system("cls");
		        menu();
				break;
            default :cout<<"Invalid Input...\n";
	}
}


float showprice(int num)
{
	bool found=false;
	fp.open("Item.bin",ios::in);
	while(fp.read((char*)&It,sizeof(Item)))
	{
	if(getProduct()==num)
		{

			getPrice();

		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();

	return getPrice();
}

float showdiscount(int num)
{
	bool found=false;
	fp.open("Item.bin",ios::in);
	while(fp.read((char*)&It,sizeof(Item)))
	{
		if(getProduct()==num)
		{

			getDiscount();

		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();

	return getDiscount();
}



struct saleOut{
    int saleId,itemId,quantity,invoiceNo;
    date d;
    float discount,unitPrice;
    };

saleOut sa;

void date1(){
cout<<endl<<"DATE : ";
		cin>>sa.d.mm>>ch>>sa.d.dd>>ch>>sa.d.yy;
}
int datemonth(){

return sa.d.mm;
}
int dateday(){
return sa.d.dd;
}
int dateyear(){
return sa.d.yy;
}

void Newsalechioce(int itemid)
{ int sum;
    char character;
    bool found=false;
	fp.open("Item.bin",ios::in);
	while(fp.read((char*)&It,sizeof(Item)))
	{
		if(getProduct()==itemid)
		{
        cout<<endl<<" Quantity : ";
        cin>>sa.quantity;
    if(sa.quantity>showquantity(It.itemId)){
    cout << "Sorry there is only " <<showquantity(It.itemId) << " left." << endl;
   cout<<"/n/nPlease press m/M to return to main board  :  ";
   cin>>character;
   if(character=='M'||character=='m')
    menu();
   else exit(0);

  }
		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
}



void Newsale()
{
   char chioce;
     cout<<endl<<"ITEM ID : ";
		cin>>sa.itemId;

cout<<endl<<" Discount : "<<showdiscount(sa.itemId);
Newsalechioce(sa.itemId);

}


void Returntomainboardforsale()
{
    char chioce;

cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    saveSale();
    }
else menu();

}1


	int getsealid()
	{
		return (rand()%4);
	}

	int getsaleitemid()
	{
		return sa.itemId;
	}
	int getsaleinvoice()
	{
	        int lowest=20, highest=100;
    int range=(highest-lowest)+1;

	    return  lowest+int(range*rand()/(RAND_MAX + 1.0));
	}
	float getsalePrice()
    {
        return sa.unitPrice;
    }
	float getsaleDiscount()
	{
		return sa.discount;
	}
	int getsalenumber()
	{
	    return sa.quantity;

	}
float total()
{
    float gross;
           gross = showprice(sa.itemId)+(showprice(sa.itemId)*(15/100));
    return sa.quantity*(gross-(gross*(showdiscount(sa.itemId)/100)));
}

void sale_Ticket()
 {
     float gross;
gross = showprice(sa.itemId)+(showprice(sa.itemId)*(15/100));
cout<<"\n\n\n\t\t*********************************************";
cout<<"\n\t\t                 DETAILS OUT                 ";
cout<<"\n\t\t*********************************************";
cout<<"\n\t\tDate                        :"<<datemonth()<<"/"<<dateday()<<"/"<<dateyear();
cout<<"\n\t\tINVOICE NO                  :"<<getsealid();
cout<<"\n\t\tSale No                     :"<<getsaleinvoice();
cout<<"\n\n\t\tPRICE                     :"<<showprice(sa.saleId);
cout<<"\n\n\t\tQUANTITY                  :"<<sa.quantity;
cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<showdiscount(sa.itemId);
cout<<"\n\n\n\t\tNET AMOUNT              :Br."<<sa.quantity*(gross-(gross*(showdiscount(sa.itemId)/100)));
cout<<"\n\t\t*********************************************";
	}



fstream fb;

void saveSale()
{
    char chioce;
	fb.open("sale.bin",ios::out|ios::app);
	 Newsale();
	 system("cls");
	 sale_Ticket();
	fb.write((char*)&sa,sizeof(saleOut));
	fb.close();
	cout<<endl<<endl<<"The Product Has Been Successfully Created...";
	getchar();
Returntomainboardforsale();
}
void searchBysaleId(int num)
{
	bool found=false;
	fb.open("sale.bin",ios::in);
	while(fb.read((char*)&sa,sizeof(saleOut)))
	{
		if(getsealid()==num)
		{
			system("cls");
			sale_Ticket();

		}
	}

	fb.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();


cout<<"\n GOODBYE "<<endl;
exit(0);
}

void searchByinvoiceNo(int invoice)
{
	bool found=false;
	fb.open("sale.bin",ios::in);
	while(fb.read((char*)&sa,sizeof(saleOut)))
	{
		if(getsaleinvoice()==invoice)
		{
			system("cls");
			sale_Ticket();

		}
	}

	fb.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
 char chioce;

cout<<"\n GOODBYE "<<endl;
}

void searchBysaledate(int mm,int dd,int yy)
{
	bool found=false;
	fb.open("sale.bin",ios::in);
	while(fb.read((char*)&sa,sizeof(saleOut)))
	{
		if(datemonth()== mm&&dateday()== dd&&dateyear()==yy)
		{
			system("cls");
			sale_Ticket();
					}
	}

	fb.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
 char chioce;

cout<<"\n GOODBYE "<<endl;
exit(0);
}

void searchBysaleItemId(int num)
{
	bool found=false;
	fb.open("sale.bin",ios::in);
	while(fb.read((char*)&sa,sizeof(saleOut)))
	{
		if(getsaleitemid()==num)
		{
			system("cls");
			sale_Ticket();
			//found=true;
		}
	}

	fb.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
 char chioce;

cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    menuforsalesearch();
    }
else menu();
}

void edit_Sale()
{
    char chioce;
	int num;
	bool found=false;
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The Product #: ";
	cin>>num;

	fb.open("sale.bin",ios::in|ios::out);
	while(fb.read((char*)&sa,sizeof(saleOut)) && found==false)
	{
		if(getsealid()==num)
		{
			sale_Ticket();
			cout<<"\nPlease Enter The New Details of Product: "<<endl;
            Newsale();
			int pos=-1*sizeof(sa);
			fb.seekp(pos,ios::cur);
			fb.write((char*)&sa,sizeof(saleOut));
			cout<<endl<<endl<<"\t Record Successfully Updated...";
			//found=true;
		}
	}
	fb.close();
	if(found==false){
		cout<<endl<<endl<<"Record Not Found...";}



cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    edit_Sale();
    }
else menu();
}

void  menuforsalesearch()
{
    int A,B,C,D,E,F;
	system("cls");
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to SEARCH BY SALE ID";
	cout<<"\n\tPress 2 to SEARCH BY INVOICE NO";
	cout<<"\n\tPress 3 to SEARCH BY DATE";
	cout<<"\n\tPress 4 to SEARCH BY ITEM ID";
	cout<<"\n\tPress 5 to BACK TO MAIN BOARD";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				cout<<"Please Enter Sale Id : ";
				cin>>A;
				searchBysaleId(A);
				break;

		case 2: system("cls");
		        cout<<"Please Enter Invoice No : ";
		        cin>>B;
		        searchByinvoiceNo(B);
				break;

		case 3:system("cls");
		       cout<<"Please Enter Date : ";
		        cin>>C>>E>>F;
		        searchBysaledate(C,E,F);
                break;

        case 4:system("cls");
		       cout<<"Please Enter Item ID : ";
		        cin>>D;
		        searchBysaleItemId(D);
                break;
         case 5:system("cls");
		        menu();
                break;
		default :cout<<"Invalid Input...\n";
	}

}


void  menuforsale()
{
	system("cls");
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to NEW SALE";
	cout<<"\n\tPress 2 to SEARCH";
	cout<<"\n\tPress 3 to EDIT ";
	cout<<"\n\tPress 4 to BACK TO MAIN SWITCH BOARD";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				saveSale();
				system("cls");
				sale_Ticket();
            break;

		case 2: system("cls");
		        menuforsalesearch();
				break;

		case 3:system("cls");
		        edit_Sale();
				break;

        case 4:system("cls");
		        menu();
				break;
		default :cout<<"Invalid Input...\n";

	}
}

struct purchaseIn{
   int purchaseId,PurinvoiceNo,puritemId,prqualitity;
  float purunitPrice;
   };
   purchaseIn pr;


void Newpurchase()
{
 char chioce;



		cout<<endl<<"ITEM ID : ";
		cin>>pr.puritemId;
		cout<<endl<<"UNIT PRICE : ";
		cin>>pr.purunitPrice;
        cout<<endl<<" Quantity : ";
        cin>>pr.prqualitity;
        cout<<endl<<"Total price : "<<pr.purunitPrice*pr.prqualitity<<endl;

}

void Returntomainboardforpurchase()
{
    char chioce;

cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    savePurchase();
    }
else menu();

}


	int getpurchaseid()
	{
		return (rand()%10)+2;
	}

	int getpurchesitemid()
	{
		return pr.puritemId;
	}
	int getpurchesinvoice()
	{
	    return  rand() % 4;
	}

	float getpurchesPrice()
    {
        return pr.purunitPrice;
    }

	int getpurchesquantity()
	{
	    return pr.prqualitity;

	}

	float gettotalpurchase()
	{
	    return showprice(pr.puritemId)*pr.prqualitity;
	}

void Showpurchase()
 {


cout<<"\n\n\n\t\t*********************************************";
cout<<"\n\t\t                 DETAILS OUT                 ";
cout<<"\n\t\t*********************************************";
cout<<"\n\t\tDate                        :"<<datemonth()<<"/"<<dateday()<<"/"<<dateyear();
cout<<"\n\t\tINVOICE NO                  :"<<getpurchesinvoice();
cout<<"\n\t\tSale No                     :"<<getpurchaseid();
cout<<"\n\t\tItem ID                     :"<<pr.puritemId;
cout<<"\n\n\t\tPRICE                     :"<<pr.purunitPrice;
cout<<"\n\n\t\tQUANTITY                  :"<<pr.prqualitity;
cout<<"\n\n\n\t\tNET AMOUNT              :Br."<<pr.purunitPrice*pr.prqualitity;
cout<<"\n\t\t*********************************************";
	}




fstream fs;

void savePurchase()
{

	fs.open("purchase.bin",ios::out|ios::app);
	 Newpurchase();
	 system("cls");
	 Showpurchase();
	fs.write((char*)&pr,sizeof(purchaseIn));
	fs.close();
	cout<<endl<<endl<<"The Product Has Been Successfully Created...";
 Returntomainboardforpurchase();
}


int showquantity(int num)
{
	bool found=false;
	fs.open("purchase.bin",ios::in);
	while(fs.read((char*)&pr,sizeof(purchaseIn)))
	{
		if(getpurchesitemid()==num)
		{

			getpurchesquantity();

		}
	}

	fs.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
    return getpurchesquantity();

}



void Newitemchioce(int itemid)
{
    bool found=false;
	fs.open("purchase.bin",ios::in);
	while(fs.read((char*)&pr,sizeof(purchaseIn)))
	{
		if(getpurchesitemid()==itemid)
		{
        cout<<endl<<"Please Enter The Name of The Item: ";
		cin.ignore();
		cin.getline(It.itemName ,100);
		cout<<endl<<"Please Enter The Price of The Item: ";
		cin>>It.unitPrice;
		cout<<endl<<"Please Enter The Discount (%): ";
		cin>>It.itemDiscount;
		cout<<endl<<"Please Enter The  Av Quantity : ";
        cout<<showquantity(It.itemId);
		cout<<endl<<"please Enter the Item location : ";
		cin.ignore();
		cin.getline(It.itemLocation ,99);
		}
	}

	fs.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
}





void searchBypurchaseId(int num)
{
     char chioce;
     bool found=false;
	fs.open("purchase.bin",ios::in);
	while(fs.read((char*)&pr,sizeof(purchaseIn)))
	{
		if(getpurchaseid()==num)
		{
			system("cls");
			Showpurchase();
			found=true;
		}
	}

	fs.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
 cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

   menuforpurchasesearch() ;
    }
else menu();

}

void searchBypurchaseinvoiceNo(int invoice)
{
    char chioce;
	bool found=false;
	fs.open("purchase.bin",ios::in);
	while(fs.read((char*)&pr,sizeof(purchaseIn)))
	{
		if(getpurchesinvoice()==invoice)
		{
			system("cls");
			Showpurchase();
			found=true;
		}
	}

	fs.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

   menuforpurchasesearch() ;
    }
else menu();

}

void searchBypurchasedate(int mm,int dd,int yy)
{
    char chioce;
	bool found=false;
	fs.open("purchase.bin",ios::in);
	while(fs.read((char*)&pr,sizeof(purchaseIn)))
	{
		if(datemonth()==mm&&dateday()==dd&&dateyear()==yy)
		{
			system("cls");
			Showpurchase();
			found=true;
		}
	}

	fs.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

   menuforpurchasesearch() ;
    }
else menu();

}

void searchBypurchaseItemId(int num)
{
    char chioce;
	bool found=false;
	fs.open("purchase.bin",ios::in);
	while(fs.read((char*)&sa,sizeof(saleOut)))
	{
		if(getpurchesitemid()==num)
		{
			system("cls");
			Showpurchase();
			//found=true;
		}
	}

	fs.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

   menuforpurchasesearch() ;
    }
else menu();

}


void edit_Purchase()
{
    char chioce;
	int num;
	bool found=false;
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The Prurchase Id #: ";
	cin>>num;

	fs.open("purchase.bin",ios::in|ios::out);
	while(fs.read((char*)&pr,sizeof(purchaseIn)) && found==false)
	{
		if(getpurchaseid()==num)
		{
		    			Showpurchase();
			cout<<"\nPlease Enter The New Details of Product: "<<endl;
            Newpurchase();
			int pos=-1*sizeof(pr);
			fs.seekp(pos,ios::cur);
			fs.write((char*)&pr,sizeof(purchaseIn));
			cout<<endl<<endl<<"\t Record Successfully Updated...";
			found=true;
		}
	}
	fs.close();
	if(found==false){
		cout<<endl<<endl<<"Record Not Found...";}
cout<<"\n Press Y/N to continue or to get back to main board "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

   edit_Purchase();
    }
else menu();



}


void  menuforpurchasesearch()
{
    int ID,Invoice,mm,dd,yy,itemid;
    char ch;
	system("cls");
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to SEARCH BY Purchase ID";
	cout<<"\n\tPress 2 to SEARCH BY INVOICE NO";
	cout<<"\n\tPress 3 to SEARCH BY Purchase DATE";
	cout<<"\n\tPress 4 to SEARCH BY ITEM ID";
    cout<<"\n\tPress 5 to BACK TO MAIN BOARD";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				cout<<"Please Enter Purchase Id : ";
				cin>>ID;
				searchBypurchaseId(ID);
				break;

		case 2: system("cls");
		        cout<<"Please Enter Invoice No : ";
		        cin>>Invoice;
		        searchBypurchaseinvoiceNo(Invoice);
				break;

		case 3:system("cls");
		       cout<<"Please Enter Date : ";
		        cin>>mm>>ch>>dd>>ch>>yy;
		        searchBypurchasedate( mm, dd, yy);
                break;

        case 4:system("cls");
		       cout<<"Please Enter Item ID : ";
		        cin>>itemid;
		        searchBypurchaseItemId(itemid);
                break;
        case 5:system("cls");
		       menu();
                break;
			default :cout<<"Invalid Input...\n";
	}

}


void  menuforpurchase()
{
	system("cls");
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to NEW PURCAHSE";
	cout<<"\n\tPress 2 to SEARCH";
	cout<<"\n\tPress 3 to EDIT ";
	cout<<"\n\tPress 4 to BACK TO MAIN SWITCH BOARD";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				savePurchase();
				system("cls");
				Showpurchase();
            break;

		case 2: system("cls");
		        menuforpurchasesearch();
				break;

		case 3:system("cls");
		        edit_Purchase();
				break;
       case 4:system("cls");
		        menu();
				break;
      		default :cout<<setw(25)<<"\n Invalid Input...\n";

      }
}


void show_over_all_total_for_purchase1()
{
    float T_total=0;
    fs.open("purchase.bin",ios::in);
      cout<<"Total for purchase in : \n";
    	while(fs.read((char*)&pr,sizeof(purchaseIn)))
    	{
    	  T_total += gettotalpurchase();
    	cout<<"\t\tTotal :"<<T_total;

    	}

      cout<<"\n";
    	fs.close();
}

void show_over_all_total_for_sale2()
{
   float T_TOTAL2=0;
fb.open("sale.bin",ios::in);
    cout<<"Total for sale in : ";
      while(fb.read((char*)&sa,sizeof(saleOut)))
    	{  T_TOTAL2 += total();
            cout<<"\t\tTotal :"<<T_TOTAL2;
            }
   fb.close();

}

float show_over_all_total_for_purchase()
{float T_total=0;
    fs.open("purchase.bin",ios::in);
      cout<<"Total for purchase in : \n";
    	while(fs.read((char*)&pr,sizeof(purchaseIn)))
    	{
    	  T_total += gettotalpurchase();
    	cout<<"\t\tTotal :"<<T_total;

    	}

      cout<<"\n";
    	fs.close();

return T_total;

}

float show_over_all_total_for_sale()
{  float T_TOTAL2=0;
fb.open("sale.bin",ios::in);
    cout<<"Total for sale in : ";
      while(fb.read((char*)&sa,sizeof(saleOut)))
    	{  T_TOTAL2 += total();
            cout<<"\t\tTotal :"<<T_TOTAL2;
            }
   fb.close();

return T_TOTAL2;
}

void profit()
{
    float profit;
    char chioce;

    profit = show_over_all_total_for_purchase() - show_over_all_total_for_sale() ;
  cout<<"\n";
     if(profit>0){
    cout<<"Profit = "<<profit;
   }
   else if(profit<0){
    cout<<"Loss = "<<profit;
   }
else cout<<"Neither Profit Nor Loss";

cout<<"\n \t Press Y/N to get back to main board or exit "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

   menu();
    }
else exit(0);
	getchar();


}

    void show_all_product_Item_In()
    {
        char chioce;
    	system("cls");
    	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    	cout<<endl<<"\t\tRECORDS FOR ITEM IN.";
    	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    	fs.open("purchase.bin",ios::in);
      cout<<"Item ID"<<setw(15)<<"Unit price"<<setw(15)<<"Quantity"<<setw(15)<<"Total Price "<<setw(15)<<"\n"<<endl;
    	while(fs.read((char*)&pr,sizeof(purchaseIn)))
    	{
        cout<<setfill('-')<<setw(50)<<"\n";


          cout<<"\n"<<getpurchesitemid()<<setfill(' ')<<setw(15)<<showprice(pr.puritemId)<<setw(15)<<getpurchesquantity()<<setw(15)<<gettotalpurchase()<<endl;
    	}
    	cout<<"\n";
    	system("cls");
        show_over_all_total_for_purchase1();

    	fs.close();
cout<<"\n \t Press Y/N to get back to main board or exit"<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    menu();
    }
else exit(0);
	getchar();


    }

void show_all_product_Item_Out()
    {
 char chioce;
        system("cls");
    	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    	cout<<endl<<"\t\tRECORDS FOR ITEM OUT.";
    	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    	fb.open("sale.bin",ios::in);
      cout<<"Item ID"<<setw(15)<<"Unit price"<<setw(15)<<"Quantity"<<setw(15)<<"Total Price "<<setw(15)<<"\n"<<endl;
    	while(fb.read((char*)&sa,sizeof(saleOut)))
    	{
          cout<<endl<<setfill('-')<<setw(50)<<"\n";
          cout<<getsaleitemid()<<setfill(' ')<<setw(15)<<showprice(sa.itemId)<<setw(15)<<getsalenumber()<<setw(15)<<total()<<endl;

    	}
    	cout<<"\n";
    	system("cls");
        show_over_all_total_for_sale2();
    	fb.close();
    cout<<"\n \t Press Y/N to get back to main board or to exit "<<endl;
cin>>chioce;
 if(chioce=='Y'||chioce=='y'){

    menu();
    }
else exit(0);
	getchar();

    }


void menuRecord_for_item_in_out()
{
int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to ITEM IN ";
	cout<<"\n\tPress 2 to ITEM OUT";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				show_all_product_Item_In();
				break;

		case 2: system("cls");
		        show_all_product_Item_Out();
				break;

      		default :cout<<setw(25)<<"\n Invalid Input...\n";
	}
}

void menu_FOR_RECORD()
{
char exitchoice;
int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to ITEM IN AND OUT ";
	cout<<"\n\tPress 2 to Sale";
	cout<<"\n\tPress 3 to Purchase ";
	cout<<"\n\tPress 4 to Profit ";
	cout<<"\n\tPress 5 to Back To Main Switch Board ";
    cout<<"\n\tPress 6 to Exit ";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				menuRecord_for_item_in_out();

            break;

		case 2: system("cls");
		        show_all_product_Item_Out();
				break;

        case 3: system("cls");
		        show_all_product_Item_In();
				break;
       case 4: system("cls");
		        profit();
				break;
        case 5: system("cls");
		        menu();
				break;
         case 6:  system("cls");
                cout<<"Are you sure you want to exit. press Y/N >>  " ;
                cin>>exitchoice;
                if(exitchoice=='Y'||exitchoice=='y')
                {
                    system("cls");
                    cout<<setw(20)<<"\n\n\n\tGOOD BYE\n\n\n\t"<<setw(20)<<endl;
                    exit(0);
                }
                else menu();

                break;


      		default :cout<<setw(25)<<"\n Invalid Input...\n";
	}
}


