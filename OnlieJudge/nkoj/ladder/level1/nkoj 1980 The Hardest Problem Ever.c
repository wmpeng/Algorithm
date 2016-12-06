/*
*nkoj 1980 The Hardest Problem Ever
*author:wmpeng 
*/ 
#include"stdio.h"
int main()
{
	char c[10]={0},a[100]={0};
	int i;
	while(1)
	{
		gets(c);
		if(c[3]=='O') break;
		gets(a);
		for(i=0;a[i]!='\0';i++)
		if(a[i]<='Z' && a[i]>='A')
		{
			a[i]-='A';
			a[i]+=26;
			a[i]-=5;
			a[i]%=26;
			a[i]+='A';
		}
		printf("%s",a);
		printf("\n");
			/*if(a<='Z' && a>='A')
			{
				a-='A';
				a+=26;
				a-=5;
				a%=26;
				a+='A';
			}*/
		gets(c);
	}
	
	return 0;
} 