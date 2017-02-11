/*
* poj 3074 Sudoku
* dancing links
* 舞蹈链的典型应用，解数独，效率高的可怕
* 这个博客的讲解非常好：
* http://www.cnblogs.com/grenet/p/3145800.html ,
* http://www.cnblogs.com/grenet/p/3163550.html ,
* http://www.cnblogs.com/grenet/p/3138654.html .
* author: wmpeng
* time: 2017-02-01 20:30:25
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 1000000
#define MAXC (9 * 9 * 4)

using namespace std;
int cnt[MAX], st[MAX];
int L[MAX], R[MAX], U[MAX], D[MAX];
int row[MAX], col[MAX];
const int head = 0;
const int delta[] = { 1,82,163,244 };
//int coun = 0;
struct Ans
{
	int r, c, k;
}ans[MAX];
int M, K;

void remove(int c)
{
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	for (int i = D[c]; i != c; i = D[i])
		for (int j = R[i]; j != i; j = R[j])
		{
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			cnt[col[j]]--;
		}
}

void resume(int c)
{
	for (int i = U[c]; i != c; i = U[i])
	{
		for (int j = L[i]; j != i; j = L[j])
		{
			D[U[j]] = j;
			U[D[j]] = j;
			cnt[col[j]]++;
		}
	}
	L[R[c]] = c;
	R[L[c]] = c;
}

bool dfs(int k)
{
	//coun++;
	if (R[head] == head)//已经找到答案
	{
		char s[100] = { 0 };
		for (int i = 0; i < k; i++)
			s[ans[st[i]].r * 9 + ans[st[i]].c] = ans[st[i]].k + '0';
		cout << s << endl;
		return true;
	}
	
	int s = 100000000, c = 0;
	for (int i = R[head]; i != head; i = R[i])
		if (cnt[i] < s)
		{
			s = cnt[i];
			c = i;
		}

	remove(c);
	for (int i = D[c]; i != c; i = D[i])
	{
		st[k] = row[i];
		for (int j = R[i]; j != i; j = R[j])
			remove(col[j]);
		if (dfs(k + 1))
			return true;
		for (int j = L[i]; j != i; j = L[j])
			resume(col[j]);
	}
	resume(c);
	
	return false;
}

void init()
{
	L[head] = MAXC;
	R[head] = 1;
	U[head] = D[head] = head;
	for (int i = 1; i <= MAXC; i++)
	{
		L[i] = i - 1;
		R[i] = (i + 1)%(MAXC+1);
		U[i] = D[i] = i;
		cnt[i] = 0;
		col[i] = i;
		row[i] = 0;
	}
	//R[MAXC] = 0;
	M = 0;
	K = MAXC;
	//coun = 0;
}

int makeColHead(int c)
{
	K++;
	cnt[c]++;
	col[K] = c;
	row[K] = M;

	L[K] = R[K] = K;

	U[K] = c;
	D[K] = D[c];
	U[D[K]] = K;
	D[U[K]] = K;
	return K;
}

void addCol(int id, int c)
{
	K++;
	cnt[c]++;
	col[K] = c;
	row[K] = M;

	L[K] = id;
	R[K] = R[id];
	L[R[K]] = K;
	R[L[K]] = K;

	U[K] = c;
	D[K] = D[c];
	U[D[K]] = K;
	D[U[K]] = K;
}

void addRow(int i, int j, int k)
{
	int id;

	M++;
	ans[M].r = i;
	ans[M].c = j;
	ans[M].k = k + 1;

	id = makeColHead(9 * i + j + delta[0]);
	addCol(id, 9 * i + k + delta[1]);
	addCol(id, 9 * j + k + delta[2]);
	addCol(id, (i / 3 * 3 + j / 3) * 9 + k + delta[3]);
}

int main()
{
	char s[100];
	while (1)
	{
		cin >> s;
		if (s[0] == 'e')
			break;

		init();
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (s[i * 9 + j] == '.')
					for (int k = 0; k < 9; k++)
						addRow(i, j, k);
				else
					addRow(i, j, s[i * 9 + j] - '1');

		dfs(0);
		//cout << coun<<endl;
	}

	return 0;
}