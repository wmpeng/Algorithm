/*
*2015 CCPC final F Battle of Guandu
*hdu 5545 F Battle of Guandu
*最短路
*auther:wmpeng
*time:2016-11-23 21:13:41
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#define INF 2100000000000000000ll
using namespace std;
int n, m, x[100005], y[100005], c[100005], w[100005];
bool vis[100005];
long long dis[100005];

typedef pair<int, int> edge;
typedef pair<int, long long> node;
vector<edge> adjList[100005];
bool operator<(node n1, node n2)
{
	return n1.second < n2.second;
}
void peng()
{
	int i, j;
	priority_queue<node> q;
	for (i = 0; i <= 100004; i++)
	{
		adjList[i].clear();
		dis[i] = INF;
		vis[i] = false;
	}
	for (i = 1; i <= n; i++)
	{
		if (w[y[i]] == 0)/////////////////////////////////////不是这的错
			adjList[0].push_back(edge(x[i], c[i]));//把所有为0的点归到一起
		else if (w[x[i]] == 0)
			adjList[y[i]].push_back(edge(0, c[i]));
		else
			adjList[y[i]].push_back(edge(x[i], c[i]));
	}
	
	q.push(node(0 ,0));///////////////////////////////不是这的错
	dis[0] = 0;
	while (!q.empty())
	{
		int curr = (q.top()).first;
		q.pop();
		vis[curr] = true;
		for (vector<edge>::iterator it = adjList[curr].begin(); it != adjList[curr].end(); it++)
			if (dis[curr] + it->second < dis[it->first])
			{
				dis[it->first] = dis[curr] + it->second;
				q.push({ it->first,dis[it->first] });

			}
	}
	//for (i = 1; i <= m; i++)
	//	cout << dis[i] << " ";
	//cout << endl;
	long long ans = 0;
	for (i = 1; i <= m; i++)
		if (w[i] == 2)
		{
			if (vis[i] == false)
			{
				cout << -1 << endl;
				return;
			}
			else
				ans += dis[i];
		}
	cout << ans << endl;
}

int main()
{
	int i, j, t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d%d", &n, &m);
		for (j = 1; j <= n; j++)
			scanf("%d", &x[j]);
		for (j = 1; j <= n; j++)
			scanf("%d", &y[j]);
		for (j = 1; j <= n; j++)
			scanf("%d", &c[j]);
		for (j = 1; j <= m; j++)
			scanf("%d", &w[j]);
		printf("Case #%d: ", i);
		peng();

	}
}