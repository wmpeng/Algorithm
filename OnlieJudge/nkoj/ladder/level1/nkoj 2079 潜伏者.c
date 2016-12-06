/*
*nkoj 2079 Ç±·üÕß
*author:wmpeng 
*/ 
#include"stdio.h"
#include"string.h"
int main()
{
	//FILE *in=fopen("2079.in","r");
	char a[105],b[105],c;
	int log[200]={0},len1,len2,i,logg[200]={0};
	
	scanf("%s%s",a,b);
	len1=strlen(a);
	
	for(i=0;i<=len1;i++)
	{
		if(log[a[i]]==0)
			log[a[i]]=b[i];
		if(log[a[i]]!=0 && log[a[i]]!=b[i]) {printf("Failed\n");return 0;}
	}
	for(i=0;i<=len1;i++)
	{
		if(logg[b[i]]==0)
			logg[b[i]]=a[i];
		if(logg[b[i]]!=0 && logg[b[i]]!=a[i]) {printf("Failed\n");return 0;}
	}
	
	for(i='A';i<='Z';i++)
		if(log[i]==0) {printf("Failed\n");return 0;}
	
	while(scanf("%c",&c)!=-1)
	{
		if(c<'A' || c>'Z') continue;
		printf("%c",log[c]);
	}
	printf("\n");
	//fclose(in);
	return 0;
} 
