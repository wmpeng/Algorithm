/*
*poj 1077 Eight
*dfs,IDA*
*author:wmpeng
*time:2016-12-01 12:31:17
*这个博客写的挺好：http://blog.csdn.net/sdj222555/article/details/7233928
*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
int list[9];
int step[128];
int deep = 1;
int jc[9] = { 1,1,2,6,24,120,720,5040,40320 };
int mi;
char ans[100];
int cnt=0;

template<class T> T abs(T x)
{
	return (x < 0 ? -x : x);
}
int hash_(int list[])
{
	int ans = 0;
	for (int i = 0; i < 9; i++)
	{
		int cnt = 0;
		for (int j = 0; j < i; j++)
			if (list[i] < list[j])
				cnt++;
		ans += cnt * jc[i];
	}
	return ans;
}
int eval_(int list[])
{
	int ans = 0;
	for (int i = 0; i < 9; i++)
	{
		if (list[i] == 0)
		{
			continue;
			int h1, l1, h2, l2;
			h1 = i / 3;
			l1 = i % 3;
			h2 = 2;
			l2 = 2;
			ans += abs(h1 - h2) + abs(l1 - l2);
		}
		else
		{
			int h1, l1, h2, l2;
			h1 = i / 3;
			l1 = i % 3;
			h2 = (list[i] - 1) / 3;
			l2 = (list[i] - 1) % 3;
			ans += abs(h1 - h2) + abs(l1 - l2);
		}
	}
	return ans;
}
bool up(int* list,int* temp)
{
	for (int i = 0; i < 9; i++)
		temp[i] = list[i];
	for (int i = 0; i < 9; i++)
		if (temp[i] == 0)
		{
			if (i / 3 != 0)
			{
				temp[i] ^= temp[i - 3] ^= temp[i] ^= temp[i - 3];
				return true;
			}
			else
				return false;
		}
}
bool dn(int* list, int* temp)
{
	for (int i = 0; i < 9; i++)
		temp[i] = list[i];
	for (int i = 0; i < 9; i++)
		if (temp[i] == 0)
		{
			if (i / 3 != 2)
			{
				temp[i] ^= temp[i + 3] ^= temp[i] ^= temp[i + 3];
				return true;
			}
			else
				return false;
		}
}
bool lft(int* list, int* temp)
{
	for (int i = 0; i < 9; i++)
		temp[i] = list[i];
	for (int i = 0; i < 9; i++)
		if (temp[i] == 0)
		{
			if (i % 3 != 0)
			{
				temp[i] ^= temp[i - 1] ^= temp[i] ^= temp[i - 1];
				return true;
			}
			else
				return false;
		}
}
bool rt(int* list, int* temp)
{
	for (int i = 0; i < 9; i++)
		temp[i] = list[i];
	for (int i = 0; i < 9; i++)
		if (temp[i] == 0)
		{
			if (i % 3 != 2)
			{
				temp[i] ^= temp[i + 1] ^= temp[i] ^= temp[i + 1];
				return true;
			}
			else
				return false;
		}
}

bool finish(int list[])
{
	for (int i = 0; i < 8; i++)
		if (list[i] != i + 1)
			return false;
	if (list[8] != 0)
		return false;
	return true;
}
void prt(char *ans)
{
	for (int i = 0; ans[i] != 0;i++)
		cout << ans[i];
	cout << endl;
}

bool dfs(int *_list, int currDp, int pre)
{
	//cout << "!" << ++cnt << "!";
	if (finish(_list))
	{
		prt(ans);
		return true;
	}
	int h = eval_(_list);
	if (h < mi)
		mi = h;
	/*cout << "_list:";
	for (int i = 0; i < 9; i++)
		cout << _list[i];
	cout << endl;*/

	if (currDp+ h> deep)
		return false;
	int list[9];
	
	if (step['u'] + pre != 0 && up(_list, list))//如果前一步和后一步相反就不要走了
	{
		ans[currDp] = 'u';
		if (dfs(list, currDp + 1, step['u']))
			return true;
	}
	if (step['d'] + pre != 0 && dn(_list, list))
	{
		ans[currDp] = 'd';
		if (dfs(list, currDp + 1, step['d']))
			return true;
	}
	if (step['l'] + pre != 0 && lft(_list, list))
	{
		ans[currDp] = 'l';
		if (dfs(list, currDp + 1, step['l']))
			return true;
	}
	if (step['r'] + pre != 0 && rt(_list, list))
	{
		ans[currDp] = 'r';
		if (dfs(list, currDp + 1, step['r']))
			return true;
	}
	return false;
}
void init()
{
	step['u'] = 1;
	step['d'] = -1;
	step['l'] = 2;
	step['r'] = -2;
}

int main()
{
	init();
	int i, j;
	char c;
	for (i = 0; i < 9; i++)
	{
		cin >> c;
		if (c == 'x')
			list[i] = 0;
		else
			list[i] = c - '0';
	}
	
	while (1)
	{
		mi = 0x7fffffff;
		memset(ans, 0, sizeof(ans));
		if (dfs(list, 0, 0))
			break;
		deep+=mi;
		if (deep >= 50)
		{
			cout << "unsolvable" << endl;
			break;
		}
	}

	return 0;
}
