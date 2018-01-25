/*
* Codeforces Round #402 (Div. 2) C - Dishonest Sellers 
* author: wmpeng
* time: 2017-02-26 19:22:45 
*/
#include<bits/stdc++.h>
using namespace std;
int k,n;
struct Item
{
	int a,b,c;
}item[200005];

bool cmp(Item x,Item y)
{
	return x.c>y.c;
}
int main()
{
	int cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&item[i].a);
	for(int i=1;i<=n;i++) scanf("%d",&item[i].b);
	for(int i=1;i<=n;i++) {item[i].c=item[i].b-item[i].a;cnt+=item[i].c>0;}
	sort(item+1,item+n+1,cmp);
	int ans=0;
	k=max(k,cnt);
//	for(int i=1;i<=n;i++) cout<<item[i].a<<" "; cout<<endl;
//	for(int i=1;i<=n;i++) cout<<item[i].b<<" "; cout<<endl;
//	for(int i=1;i<=n;i++) cout<<item[i].c<<" "; cout<<endl;
	
	for(int i=1;i<=k;i++) ans+=item[i].a;
	for(int i=k+1;i<=n;i++) ans+=item[i].b;
	
	cout<<ans<<endl;
	return 0;
}
