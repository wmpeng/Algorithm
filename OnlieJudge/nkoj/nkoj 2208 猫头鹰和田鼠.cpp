/*
*nkoj 2208 √®Õ∑”•∫ÕÃÔ Û
*≈≈–Ú 
*author:wmpeng
*time:2016-12-02 20:20:13 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct Child
{
	int a;
	int b;
}children[10005];

bool cmp(Child c1,Child c2)
{
	return c1.b<c2.b;
}

int main()
{
	int n,i;
	long long k;
	while(cin>>n>>k)
	{
		for(i=1;i<=n;i++)
			cin>>children[i].a>>children[i].b;
		sort(children+1,children+n+1,cmp);
		
		for(i=1;i<=n;i++)
		{
			if(k>=children[i].b)
				k+=children[i].a;
			else
				break;
		}
		cout<<i-1<<endl;
	}
	return 0;
} 
