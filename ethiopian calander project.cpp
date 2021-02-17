/* 
*/
#include <iostream> // input output
#include <string>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#include <conio.h>
/*Given an etiopian year this program displays the corresponding date in gregorian calander for the first day of the given ethiopian year
and also the weekday for that day*/
const long ZEMENBLUE = 5500;
const string ethWeekDays[]={"Seg","Mak", "Reb", "Ham", "Arb", "Kid", "Ehu"};
int main(){
    string gmont[13]={"AGU/SEP","SEP/OCT","OCT/NOV","NOV/DEC","DEC/JAN","JAN/FEB","FEB/MAR","MAR/APRIL","APRIL/MAY","MAY/JUNE","JUNE/JULY","JULY/AGU","AGU"};
    string gmonth[13]={"SEP/OCT","OCT/NOV","NOV/DEC","DEC/JAN","JAN/FEB","FEB/MAR","MAR/APRIL","APRIL/MAY","MAY/JUNE","JUNE/JULY","JULY/AGU","AGU/SEP", "SEP"};
    string wer[13]={"MESKEREM","TIKIMIT","HIDAR","TAHASAS","TIRI","YEKATIT","MEGABIT","MIYAZIYA","GINBOT","SENA","HAMLE","NEHASSA","PAUGME"};
	int day,month, greDay, greMonth, year, leapYear, gNDaysCur,sd,m,gsd,k,lY;
	long ethNDays, ameteAlem, startDay, greNDays, greYear;
    int gMonSize[12]={31,28,31,30,31,30,31,31,30,31,30,31};


    cout << "Enter Ethiopian year" << endl;
	cin >>  year;
	//system("cls");
	/* calculating the number of days up to the first day of the given ethiopian year*/
	ameteAlem= ZEMENBLUE + year;
	leapYear=((ameteAlem + 1)%4 == 0);//1 if year is leap year 0 otherwise
	ethNDays= (ameteAlem-1)*365 + (ameteAlem-1)/4 ;//no of ethiopian days up to the current year
	if((ameteAlem-1)%4 ==3) ethNDays += 1; //ethiopian leap year occurs every 4 year at the third year. Add 1 if we pass the third year
	ethNDays +=1; // add one b/c we are considering the first day of the current year
	startDay= ethNDays%7;  //get the  start day for the year
	/* calculating the number of days up to the first day of the given ethiopian year.
	First we take any  date from gregorian calander and the corresponding date in ethiopian calander. we determine
	the number of days for each calander and calculate the difference. This difference is always constant and it is 2006080. using this
	value we determine the number of gregorian days from the number of ethiopian days.*/
	greNDays=ethNDays-2006080; //convert the ethiopian no of days to the gregorian no of days.
	/*determining the corresponding gregorian year from the number of gregorian days*/
	greYear=(greNDays/146097)*400 + ((greNDays%146097)/36524)*100 + (((greNDays%146097)%36524)/1461)*4 + (((greNDays%146097)%36524)%1461)/365 +1; //finding the corresponding gregorian year from the number of gregorian days
	/*determining the corresponding gregorian day and month. To do that first find number of days passed the already found greggorian year
	*/
	gNDaysCur=(((greNDays%146097)%36524)%1461)%365; //The number of days passed after  the already calculated gregorian year
	//based on the corresponding gregorian year detemine the no of days for february
	if(greYear%4==0 && greYear%100!=0 || greYear%400==0 )
			gMonSize[1]=29;
	else
			gMonSize[1]=28;
    //calculating gregorian month
	greMonth=1;
	while(gNDaysCur>= gMonSize[greMonth-1] ){
			gNDaysCur =gNDaysCur-gMonSize[greMonth-1];
			greMonth++;
	}
	greDay=gNDaysCur;
	cout << "the corresponding gregorian date is: " << greDay << "/" << greMonth << "/" <<greYear << endl;
	cout<< " Number of ethiopian days up to the current year :"<< ethNDays<<endl;
	cout << "the Week day: " << ethWeekDays[startDay] <<endl;
	cout << "Ethiopian leap year: "  << (leapYear==1? "Yes":"No");
    cout<<endl;



    //Determining Zemen
    if((year-7)%4==0)
    {
        cout<<"\t"<<"YOHANESS"<<endl;
    }
    else if((year-7)%4==1)
    {
        cout<<"\t"<<"Matewos"<<endl;
    }
    else if((year-7)%4==2)
    {
        cout<<"\t"<<"Mareqos"<<endl;
    }
    else
    {
        cout<<"\t"<<"Luqas"<<endl;
    }

sd=(ethNDays%7)+1;
/* the calander calculator*/


   for(int p=0;p<=12;p++){
          cout<<"\n"<<setw(16)<<wer[p]<<"  "<<year<<setw(36)<<gmonth[p]<<endl;
          cout << endl <<"\t"<<"EHU\tSEG\tMAK\tREB\tHAM\tARB\tKID\n";
          cout<<"\t"<<"_____________________________________________________"<<endl;
for(int i=1;i<=sd;i++){
    cout<<"\t";
if(sd==7)
   sd=0 ;

}

		for (int j = 1; j <= 30; j++)

	{

    	if (((j +sd-1 ) % 7 == 0))
         cout <<endl<<"\n";
         		cout<<"\t"<<j<<" "<<greDay++;
           if(greDay==31)
            greDay=1;


if(p==1)
    greDay==31;




if(p==12)
{
if((ameteAlem)%4 ==3){
       if(j==6)
          break;
}
       else {
            if(j==5)

          break;}
}


	}

if(p==0)
    cout<<endl<<"MESKERM 1 NEW YEAR"<<endl<<endl<<endl<<"MESKEM 17 MESKEL"<<endl;
else if (p==3)
    cout<<endl<<endl<<"TAHASAS 2 THE PROPHET'S BIRTH"<<endl<<endl<<endl<<"TAHASSA 28/29 ETHIOPIAN CHRISMASS";
else if(p==4)
    cout<<endl<<endl<<"TIR 11 EPIPHANY";
else if (p==5)
    cout<<endl<<endl<<"YEKATIT 23 ADWA VICTORY DAY ";
else if(p==7)
    cout<<endl<<endl<<"MIYAZIYA 23 INTERNATIONAL LABOR DAY"<<endl<<endl<<"MIYAZIYA 27 PATRIOTS DAY";
else if (p==8)
    cout<<endl<<endl<<"GINBOT 20 DER DOWNFALL DAY";
else if(p==9)
    cout<<endl<<endl<<" SENA 25 EID AL FITR";

sd=sd+2;
if(sd==8){
sd=1;
if(sd==7)
sd==1;

}
	cout << endl << endl;


   }
  cout<<"Thank you for using this";

  getch();
	return 0;
}






