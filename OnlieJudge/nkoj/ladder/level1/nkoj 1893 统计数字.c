/*
*nkoj 1893 统计数字
*author:wmpeng 
*/ 
#include"stdio.h"
int a[200005],n;

void shell()//就是一个排序 可以直接用algorithm中的sort()
{
	int k,i,j,t;
	k=n/2;
	while(k>0)
	{
	  for(i=k+1;i<=n;i++)
	  {
	  	j=i-k;
	  	t=a[i];
	  	while(j>=1 && a[j]>t)
	  	{
	  		a[j+k]=a[j];
	  		j-=k;
		}
		a[j+k]=t;
	  }
	  k/=2;
	}
}

int main()
{
	int i,x,num=0;
	//FILE *in=fopen("1893_统计数字.in","r");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	shell();

	x=a[1];
	for(i=1;i<=n+1;i++)
	{
		if(a[i]==x) num++;
		else
		{
			printf("%d %d\n",x,num);
			x=a[i];
			num=1; 
		}
	}
	
	
	return 0;
}
