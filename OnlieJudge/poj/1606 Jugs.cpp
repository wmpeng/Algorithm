/*
*poj 1606 Jugs
*描述:用两个杯子倒水倒出目标量的水
*普通dfs
*其实好像模拟也可以过，可以去看题目的discuss
*author:wmpeng
*time:2016-12-08 21:51:21
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
int a, b, n;
typedef pair<int, int> Cap;

class Status
{
public:
	Cap cap;
	vector<char*> ans;//可以不用String类型
	bool nextStatus();
};
map<Cap, bool> rec;
queue<Status*> que;

bool Status::nextStatus()
{
	if (cap.first == n || cap.second == n)
	{
		ans.push_back("success");
		return true;
	}

	///fill A 
	if (!rec[Cap(a, cap.second)])
	{
		que.push(new Status());
		que.back()->cap.first = a;
		que.back()->cap.second = cap.second;
		rec[que.back()->cap] = true;
		que.back()->ans = ans;
		que.back()->ans.push_back("fill A");
	}

	///fill B
	if (!rec[Cap(cap.first, b)])
	{
		que.push(new Status());
		que.back()->cap.first = cap.first;
		que.back()->cap.second = b;
		rec[que.back()->cap] = true;
		que.back()->ans = ans;
		que.back()->ans.push_back("fill B");
	}
	///empty A
	if (!rec[Cap(0, cap.second)])
	{
		que.push(new Status());
		que.back()->cap.first = 0;
		que.back()->cap.second = cap.second;
		rec[que.back()->cap] = true;
		que.back()->ans = ans;
		que.back()->ans.push_back("empty A");
	}

	///empty B
	if (!rec[Cap(cap.first, 0)])
	{
		que.push(new Status());
		que.back()->cap.first = cap.first;
		que.back()->cap.second = 0;
		rec[que.back()->cap] = true;
		que.back()->ans = ans;
		que.back()->ans.push_back("empty B");
	}

	///pour A B
	if (!rec[Cap(cap.first - min(cap.first, b - cap.second), cap.second + min(cap.first, b - cap.second))])
	{
		que.push(new Status());
		que.back()->cap.first = cap.first - min(cap.first, b - cap.second);
		que.back()->cap.second = cap.second + min(cap.first, b - cap.second);
		rec[que.back()->cap] = true;
		que.back()->ans = ans;
		que.back()->ans.push_back("pour A B");
	}


	///pour B A
	if (!rec[Cap(cap.first + min(cap.second, a - cap.first), cap.second - min(cap.second, a - cap.first))])
	{
		que.push(new Status());
		que.back()->cap.first = cap.first + min(cap.second, a - cap.first);
		que.back()->cap.second = cap.second - min(cap.second, a - cap.first);
		rec[que.back()->cap] = true;
		que.back()->ans = ans;
		que.back()->ans.push_back("pour B A");
	}

	return false;
}

void prt(Status* temp)
{
	//cout << temp->cap.first << " " << temp->cap.second << endl;
	int aa = 0, bb = 0;
	cout << temp->cap.first << " " << temp->cap.second << "~";
	for (int i = 0; i < temp->ans.size(); i++)
	{
		if (string(temp->ans[i]) == string("fill A"))
		{
			aa = a;
		}
		else if (string(temp->ans[i]) == string("fill B"))
		{
			bb = b;
		}
		else if (string(temp->ans[i]) == string("empty A"))
		{
			aa = 0;
		}
		else if (string(temp->ans[i]) == string("empty B"))
		{
			bb = 0;
		}
		else if (string(temp->ans[i]) == string("pour B A"))
		{
			int mi = min(bb, a - aa);
			aa += mi;
			bb -= mi;
		}
		else if (string(temp->ans[i]) == string("pour A B"))
		{
			int mi = min(aa, b - bb);
			bb += mi;
			aa -= mi;
		}
		else
		{
			cout << "!" << endl;
		}
		cout << temp->ans[i] << endl;
		cout << aa << " " << bb << endl;
	}
}
void prt2(Status* temp)
{
	for (int i = 0; i < temp->ans.size(); i++)
	{
		cout << temp->ans[i] << endl;
	}
}

int main()
{
	while (cin >> a >> b >> n)
	{
		rec.clear();
		while (!que.empty())
		{
			delete que.front();
			que.pop();
		}
		que.push(new Status());
		que.back()->cap.first = 0;
		que.back()->cap.second = 0;
		
		while (!que.empty())
		{
			Status *curr = que.front();
			que.pop();
			if (curr->nextStatus())///curr就是答案了
			{
				//prt(curr);
				prt2(curr);
				break;
			}
			delete curr;
		}
	}
	return 0;
}