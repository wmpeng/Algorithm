/*
* Codeforces Round #402 (Div. 2) B - Weird Rounding 
* author: wmpeng
* time: 2017-02-26 19:22:45 
*/
#include<bits/stdc++.h>
using namespace std;
int k;
char n[20];

int main()
{
	scanf("%s%d",&n,&k);
	reverse(n,n+strlen(n));
	int ans=-1,cnt=0;
	for(int i=0;i<strlen(n);i++)
	{
		if(n[i]=='0')
			cnt++;
		if(cnt==k)
		{
			ans=i+1-k;
			break;
		}
	}
	if(ans==-1) ans=strlen(n)-1;
	cout<<ans<<endl;
	return 0;
}
