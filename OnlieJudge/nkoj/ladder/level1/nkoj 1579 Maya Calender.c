/*
*nkoj 1579 Maya Calender
*author:wmpeng 
*/

#include"stdio.h"
#include"string.h"

int n;
//FILE *in;
void major()
{
	int day,year,mon=-1,num=-1,year2,day1,day2;
	char month[10]={0},month2[10];
	scanf("%d. %s %d",&day,month,&year);
	
	//pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
	if(strcmp(month,"pop")==0) mon=0;
	else if(strcmp(month,"no")==0) mon=1;
	else if(strcmp(month,"zip")==0) mon=2;
	else if(strcmp(month,"zotz")==0) mon=3;
	else if(strcmp(month,"tzec")==0) mon=4;
	else if(strcmp(month,"xul")==0) mon=5;
	else if(strcmp(month,"yoxkin")==0) mon=6;
	else if(strcmp(month,"mol")==0) mon=7;
	else if(strcmp(month,"chen")==0) mon=8;
	else if(strcmp(month,"yax")==0) mon=9;
	else if(strcmp(month,"zac")==0) mon=10;
	else if(strcmp(month,"ceh")==0) mon=11;
	else if(strcmp(month,"mac")==0) mon=12;
	else if(strcmp(month,"kankin")==0) mon=13;
	else if(strcmp(month,"muan")==0) mon=14;
	else if(strcmp(month,"pax")==0) mon=15;
	else if(strcmp(month,"koyab")==0) mon=16;
	else if(strcmp(month,"cumhu")==0) mon=17;
	else if(strcmp(month,"uayet")==0) mon=18;
	num=year*365+mon*20+day;num++;
	//printf("%2d  %s  %2d  %2d  %10d\n",day,month,year,mon,num);
	
	year2=(num-1)/260;//////////¥Ì‘⁄’‚¿Ô 
	num%=260;
	day1=num%13;if(day1==0) day1=13;
	day2=num%20;if(day2==0) day2=20;
	//printf("%d %d %d\n",day1,day2,year2);
	//imix, ik, akbal, kan, ;chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau
	if(day2==1) printf("%d imix %d\n",day1,year2) ;
	if(day2==2) printf("%d ik %d\n",day1,year2) ;
	if(day2==3) printf("%d akbal %d\n",day1,year2) ;
	if(day2==4) printf("%d kan %d\n",day1,year2) ;
	if(day2==5) printf("%d chicchan %d\n",day1,year2) ;
	if(day2==6) printf("%d cimi %d\n",day1,year2) ;
	if(day2==7) printf("%d manik %d\n",day1,year2) ;
	if(day2==8) printf("%d lamat %d\n",day1,year2) ;
	if(day2==9) printf("%d muluk %d\n",day1,year2) ;
	if(day2==10) printf("%d ok %d\n",day1,year2) ;
	if(day2==11) printf("%d chuen %d\n",day1,year2) ;
	if(day2==12) printf("%d eb %d\n",day1,year2) ;
	if(day2==13) printf("%d ben %d\n",day1,year2) ;
	if(day2==14) printf("%d ix %d\n",day1,year2) ;
	if(day2==15) printf("%d mem %d\n",day1,year2) ;
	if(day2==16) printf("%d cib %d\n",day1,year2) ;
	if(day2==17) printf("%d caban %d\n",day1,year2) ;
	if(day2==18) printf("%d eznab %d\n",day1,year2) ;
	if(day2==19) printf("%d canac %d\n",day1,year2) ;
	if(day2==20) printf("%d ahau %d\n",day1,year2) ;
}


int main()
{
	int i,j;
	//in=fopen("1579.in","r");
	
	scanf("%d",&n);
	printf("%d\n",n);
	for(i=1;i<=n;i++)
		major();
	
	return 0;
} 
