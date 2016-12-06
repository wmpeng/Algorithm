/*
*nkoj 1019 计算 A+B (超级大数相加)
*author:wmpeng 
*/ 

#include"stdio.h"
#include"string.h"
int main()
{
	char a[105]={0},b[105]={0};
	int i,c[105]={0},d[105]={0},la,lb,l;
	
	scanf("%s %s",a,b);
	
	la=strlen(a);
	lb=strlen(b);
	for(i=0;i<la;i++)
		c[la-i]=a[i]-'0';
	for(i=0;i<lb;i++)
		d[lb-i]=b[i]-'0';
	
	if(la>lb) l=la;
	else l=lb;
	
	for(i=1;i<=l+1;i++)
	{
		c[i]+=d[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	
	
	if(c[l+1]!=0) l++; 
	for(i=l;i>=1;i--)
		printf("%d",c[i]);
	printf("\n");
	return 0;
}
