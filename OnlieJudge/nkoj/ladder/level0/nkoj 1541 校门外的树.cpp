/*
*nkoj 1541 校门外的树
*author:wmpeng 
*/ 

#include"stdio.h"
short a[10005]={0};

int main()
{
	int l,m,i,j,x,y,ans=0;
	
	scanf("%d%d",&l,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		for(j=x;j<=y;j++)
			a[j]=1;
	}
	for(i=0;i<=l;i++)
		if(a[i]==0) ans++;
	printf("%d\n",ans);
	
	return 0;
} 
