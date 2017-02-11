/*
* hdu 3498 whosyourdaddy
* �赸��(dancing links),��ֵ����֦
* ���⣺��n����λ�ĵ��ˣ�����˭��˭���ڣ���ĳ�����˽��й���ʱ�õ����Լ�����ֱ�����ڵĵ��˶��ᱻ����
* ��һ���Ƚ����Ե��ظ���������
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define MAXN 60
using namespace std;

int L[MAXN*MAXN], R[MAXN*MAXN], U[MAXN*MAXN], D[MAXN*MAXN];//�ĸ���������
int C[MAXN*MAXN];//��¼ÿ���ڵ�������һ��
int H[MAXN];//������¼��һ�е�����һ���ڵ�
int cnt[MAXN], vis[MAXN];//cnt�������е�Ԫ�ظ���
vector<int> E[MAXN];
int n, m, id, fans;

/*��ʼ��*/
void init()
{
	for (int i = 0; i <= n; i++)
	{
		E[i].clear();
		E[i].push_back(i);
		cnt[i] = 0;
		U[i] = D[i] = i;
		L[i + 1] = i;
		R[i] = i + 1;
	}
	R[n] = 0;
	id = n + 1;
	memset(H, -1, sizeof(H));//head���-1
}

/*��r,c���뵽ʮ������*/
void link(int r, int c)
{
	cnt[c]++;
	C[id] = c;
	U[id] = U[c];
	D[U[c]] = id;
	D[id] = c;
	U[c] = id;
	if (H[r] == -1)
		H[r] = L[id] = R[id] = id;
	else
	{
		L[id] = L[H[r]];
		R[L[H[r]]] = id;
		R[id] = H[r];
		L[H[r]] = id;
	}
	id++;
}

/*ɾ����*/
void remove(int size)
{
	for (int j = D[size]; j != size; j = D[j])
	{
		L[R[j]] = L[j];
		R[L[j]] = R[j];
	}
}

/*�ָ���*/
void resume(int size)
{
	for (int j = D[size]; j != size; j = D[j])
		L[R[j]] = R[L[j]] = j;
}

/*��ֵ���� ����������Ҫ���ٴβ��ܽ���*/
int h()
{
	int sum = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = R[0]; i != 0; i = R[i])
	{
		if (vis[i])
			continue;
		sum++;
		for (int j = D[i]; j != i; j = D[j])
			for (int k = R[j]; k != j; k = R[k])
				vis[C[k]] = 1;
	}
	return sum;
}

void dance(int k)//�Ѿ�����k����������������
{
	int mm = MAXN, pos;

	/*��֦
	*�Ѿ��ߵļ���������Ҫ�ߵ��Ѿ����������ҵ������Ž⣬��ô��������ȥҲ�����������Ž�*/
	if (k + h() >= fans) 
		return;

	//cout << "R[0]="<<R[0] << endl;
	if (R[0] == 0)//�Ѿ���һ����
	{
		//cout << "!"<< endl;
		if (k < fans)
			fans = k;
		return;
	}

	//ѡ���ٵ�һ��
	for (int i = R[0]; i != 0; i = R[i])
		if (mm > cnt[i])
		{
			mm = cnt[i];
			pos = i;
		}

	//������һ�е�ÿһ����,�����Ž�
	for (int i = D[pos]; i != pos; i = D[i])
	{
		remove(i);
		for (int j = R[i]; j != i; j = R[j])
   			remove(j);
		dance(k + 1);
		for (int j = R[i]; j != i; j = R[j])
			resume(j);
		resume(i);
	}
}

int main()
{
	int u, v;
	while (scanf("%d %d", &n, &m) != -1)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			for (vector<int>::iterator it = E[i].begin(); it != E[i].end(); it++)
				link(i, *it);
		fans = n;//����
		dance(0);
		printf("%d\n", fans);
	}
	return 0;
}