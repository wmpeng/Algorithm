/*
* Codeforces Round #402 (Div. 2) A - Pupils Redistribution 
* author: wmpeng
* time: 2017-02-26 19:22:45 
*/
#include<bits/stdc++.h>
using namespace std;
int a[6],b[6],c[6];
int mabs(int x)
{
	return x<0?(-x):x;
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&x);a[x]++;}
	for(int i=1;i<=n;i++) {scanf("%d",&x);b[x]++;}
	for(int i=1;i<=5;i++) c[i]=a[i]-b[i];
	
	for(int i=1;i<=5;i++) if(c[i]%2!=0) {cout<<-1<<endl;return 0;}
	
	int ans=0;
	for(int i=1;i<=5;i++)
		if(c[i]>0)
			ans+=c[i]/2;
	
	cout<<ans<<endl;
	return 0;
}
