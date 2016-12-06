/*
*nkoj 1023 A+B+C+D+... µÄÌôÕ½
*author:wmpeng 
*/
#include"stdio.h" 
int main()
{
	int ans=0,num=0;
	char c;
	while(scanf("%c",&c)!=-1)
	{
		if(c!=' ' && c!='\n')
		{
			num*=10;num+=c-'0';
		}
		else if(c==' ')
		{
			ans+=num;
			num=0;
		}
		else
		{
			ans+=num;
			printf("%d\n",ans);
			num=0;
			ans=0;
		}
	}
	return 0; 
}
