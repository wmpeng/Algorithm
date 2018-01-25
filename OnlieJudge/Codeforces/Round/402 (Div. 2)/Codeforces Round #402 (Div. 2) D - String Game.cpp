/*
* Codeforces Round #402 (Div. 2) D - String Game 
* author: wmpeng
* time: 2017-02-26 19:22:45 
*/
#include<bits/stdc++.h>
using namespace std;
char t[200005],p[200005];
int a[200005],len;
char flag[200005];
char* del(int k)
{
	char* ret=new char[len-k+5];
	int prt=0;
	memset(flag,0,len+4);
	memset(ret,0,len-k+5);
	for(int i=1;i<=k;i++) flag[a[i]]=1;
	for(int i=1;i<=len;i++)
		if(flag[i]==0)//没有被删 
			ret[++prt]=t[i];
	return ret;
}
//判断s1中是否存在s2 
bool inclusion(char *s1,char *s2)
{
	int prt1=1,prt2=1;
	int l1=strlen(s1+1),l2=strlen(s2+1);
	for(prt1=1;prt1<=l1;prt1++)
	{
		if(s1[prt1]==s2[prt2])
			prt2++;
		if(prt2>l2)
			return true;
	}
	return false;
}


int main()
{
	cin>>t+1>>p+1;
	len=strlen(t+1);
	for(int i=1;i<=len;i++) cin>>a[i];
	int l=0,r=len;
	while(r-l>=2)
	{
		int m=(r+l)/2;
		if(inclusion(del(m),p))
			l=m;
		else
			r=m;
	}
	cout<<l<<endl;
		
	return 0;
}
