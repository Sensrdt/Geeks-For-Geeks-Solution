#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
bool *visited;
stack<int> s;
void check(int);
void toposort(int e)
{
	for (int i = 0; i < e; i++)
	{
		if (!visited[i])
		{
			check(i);
		}
	}
}
void check(int i)
{
	visited[i] = true;
	for (int j = 0; j < a[i].size(); j++)
	{
		int x = a[i][j];
		if (!visited[x])
		{
			toposort(x);
		}
	}
	s.push(i);
}

void display(int e)
{
	for (int i = 0; i < e; i++)
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int e;
		cin >> e;
		int u, v;
		visited = new bool[n];
		a.resize(e);
		for (int i = 0; i < e; i++)
		{
			cin >> u >> v;
			a[u].push_back(v);
		}

		toposort(e);
		display(e);
	}
}