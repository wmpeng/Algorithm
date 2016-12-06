/*
*nkoj 1395 Quicksum
*author:wmpeng 
*/ 
#include"stdio.h"
int main()
{
	char c;
	int i=0,ans=0;
	//FILE *in=fopen("1395.in","r"); 
	while(scanf("%c",&c)!=-1)
	{
		if(c=='#') break;
		if(c!='\n')
		{ 
			i++;
			if(c!=' ')
				ans+=(c-'A'+1)*i;
		}
		else
		{
			printf("%d\n",ans);
			ans=0;
			i=0;
			//ans=0;
		}
	}
	return 0;
}
