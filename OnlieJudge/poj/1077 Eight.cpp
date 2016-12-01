/*
*poj 1077 Eight
*dfs,A*
*author:wmpeng
*time:2016-11-30 22:15:45
*
*这个博客写的很好，代码很快: http://blog.csdn.net/sdj222555/article/details/7233928
*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
int list[9];
int jc[9] = { 1,1,2,6,24,120,720,5040,40320 };
int ansid = 322560;
bool v[400000];
struct rec
{
	int id;
	int list[9];
	int g;
	int h;
	string ans;
	rec operator=(rec _r)
	{
		id = _r.id;
		for (int i = 0; i < 9; i++)
			list[i] = _r.list[i];
		g = _r.g;
		h = _r.h;
		ans = _r.ans;
		return *this;
	}
	rec() {}
	rec(int _id, int* _list, int _g, int _h, string _ans)
	{
		id = _id;
		for (int i = 0; i < 9; i++)
			list[i] = _list[i];
		g = _g;
		h = _h;
		ans = _ans;
	}
};

template<class T> T abs(T x)
{
	return (x < 0 ? -x : x);
}
bool operator<(rec r1, rec r2)
{
	return r1.h + r1.g > r2.h + r2.g;
}

int hash_(int list[], int len = 9)
{
	int ans = 0;
	for (int i = 0; i < len; i++)
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

rec up(rec curr)
{
	for (int i = 0; i < 9; i++)
		if (curr.list[i] == 0)
		{
			if (i / 3 != 0)
			{
				curr.list[i] ^= curr.list[i - 3] ^= curr.list[i] ^= curr.list[i - 3];
				return rec(hash_(curr.list), curr.list, curr.g + 1, eval_(curr.list), curr.ans + 'u');
			}
			else
				return curr;
		}
}
rec dn(rec curr)
{
	for (int i = 0; i < 9; i++)
		if (curr.list[i] == 0)
		{
			if (i / 3 != 2)
			{
				curr.list[i] ^= curr.list[i + 3] ^= curr.list[i] ^= curr.list[i + 3];
				return rec(hash_(curr.list), curr.list, curr.g + 1, eval_(curr.list), curr.ans + 'd');
			}
			else
				return curr;
		}
}
rec lft(rec curr)
{
	for (int i = 0; i < 9; i++)
		if (curr.list[i] == 0)
		{
			if (i % 3 != 0)
			{
				curr.list[i] ^= curr.list[i - 1] ^= curr.list[i] ^= curr.list[i - 1];
				return rec(hash_(curr.list), curr.list, curr.g + 1, eval_(curr.list), curr.ans + 'l');
			}
			else
				return curr;
		}
}
rec rt(rec curr)
{
	for (int i = 0; i < 9; i++)
		if (curr.list[i] == 0)
		{
			if (i % 3 != 2)
			{
				curr.list[i] ^= curr.list[i + 1] ^= curr.list[i] ^= curr.list[i + 1];
				return rec(hash_(curr.list), curr.list, curr.g + 1, eval_(curr.list), curr.ans + 'r');
			}
			else
				return curr;
		}
}

void prt(rec r)
{
	for (int i = 0; i < r.ans.length(); i++)
		cout << r.ans[i];
	cout << endl;
	/*for (int i = 0; i <= 8; i++)
	{
	cout << r.list[i];
	if ((i + 1) % 3 == 0)
	cout << endl;
	}*/

}
void prtmat(int list[])
{
	for (int i = 0; i <= 8; i++)
	{
		cout << list[i];
		if ((i + 1) % 3 == 0)
			cout << endl;
	}
	cout << endl;
}
void bh(char c)
{
	for (int i = 0; i < 9; i++)
		if (list[i] == 0)
		{
			if (c == 'd')
				list[i] ^= list[i + 3] ^= list[i] ^= list[i + 3];
			else if (c == 'u')
				list[i] ^= list[i - 3] ^= list[i] ^= list[i - 3];
			else if (c == 'r')
				list[i] ^= list[i + 1] ^= list[i] ^= list[i + 1];
			else if (c == 'l')
				list[i] ^= list[i - 1] ^= list[i] ^= list[i - 1];
			return;
		}

}
int main()
{
	int cnt = 0;
	//memset(_hash, 127, sizeof(_hash));
	//memset(_eval, 127, sizeof(_eval));
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
	priority_queue<rec> que;
	que.push(rec(hash_(list), list, 0, eval_(list), ""));
	v[hash_(list)] = true;
	//string ans;
	while (!que.empty())
	{
		rec curr = que.top();
		que.pop();
		//prt(curr);
		if (curr.id == ansid)
		{
			//ans = curr.ans;
			prt(curr);
			break;
		}
		rec temp;
		temp = up(curr);
		if (!v[temp.id])
		{
			v[temp.id] = true;
			que.push(temp);
			cnt++;
		}
		temp = dn(curr);
		if (!v[temp.id])
		{
			v[temp.id] = true;
			que.push(temp);
			cnt++;
		}
		temp = lft(curr);
		if (!v[temp.id])
		{
			v[temp.id] = true;
			que.push(temp);
			cnt++;
		}
		temp = rt(curr);
		if (!v[temp.id])
		{
			v[temp.id] = true;
			que.push(temp);
			cnt++;
		}
	}
	cout << endl << cnt << endl;

	/*prtmat(list);
	ans = "ldruullddrurdllurrd";
	for (i = 0; i < ans.length(); i++)
	{
	bh(ans[i]);
	prtmat(list);
	}*/
	return 0;
}