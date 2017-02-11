/*
* hdu 3498 whosyourdaddy
* 舞蹈链(dancing links),估值，剪枝
* 题意：有n个单位的敌人，给出谁和谁相邻，对某个敌人进行攻击时该敌人以及与其直接相邻的敌人都会被消灭。
* 是一个比较明显的重复覆盖问题
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define MAXN 60
using namespace std;

int L[MAXN*MAXN], R[MAXN*MAXN], U[MAXN*MAXN], D[MAXN*MAXN];//四个方向链表
int C[MAXN*MAXN];//记录每个节点属于哪一列
int H[MAXN];//用来记录这一行的其中一个节点
int cnt[MAXN], vis[MAXN];//cnt列链表中的元素个数
vector<int> E[MAXN];
int n, m, id, fans;

/*初始化*/
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
	memset(H, -1, sizeof(H));//head填充-1
}

/*把r,c加入到十字链中*/
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

/*删除列*/
void remove(int size)
{
	for (int j = D[size]; j != size; j = D[j])
	{
		L[R[j]] = L[j];
		R[L[j]] = R[j];
	}
}

/*恢复列*/
void resume(int size)
{
	for (int j = D[size]; j != size; j = D[j])
		L[R[j]] = R[L[j]] = j;
}

/*估值函数 返回最少需要多少次才能结束*/
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

void dance(int k)//已经走了k步，继续往下搜索
{
	int mm = MAXN, pos;

	/*剪枝
	*已经走的加上至少需要走的已经超过现在找到的最优解，那么继续找下去也不可能是最优解*/
	if (k + h() >= fans) 
		return;

	//cout << "R[0]="<<R[0] << endl;
	if (R[0] == 0)//已经是一个解
	{
		//cout << "!"<< endl;
		if (k < fans)
			fans = k;
		return;
	}

	//选最少的一列
	for (int i = R[0]; i != 0; i = R[i])
		if (mm > cnt[i])
		{
			mm = cnt[i];
			pos = i;
		}

	//尝试这一列的每一个点,找最优解
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
		fans = n;//最差解
		dance(0);
		printf("%d\n", fans);
	}
	return 0;
}