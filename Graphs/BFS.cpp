#include <bits/stdc++.h> 
#define pb push_back 

/*
	5 4
	3
	1 2
	1 3
	3 4
	2 5
	4 2
*/

using namespace std; 

vector<bool> visited; 
vector<vector<int> > adj; 

void bfs(int u) 
{ 
	queue<int> q; 

	q.push(u); 
	visited[u] = true; 

	while (!q.empty()) { 

		int f = q.front(); 
		q.pop(); 

		cout << f << " "; 

		for (auto i = adj[f].begin(); i != adj[f].end(); i++) { 
			if (!visited[*i]) { 
				q.push(*i); 
				visited[*i] = true; 
			} 
		} 
	} 
} 

int main() 
{ 
	int n, e; 
	cin >> n >> e; 
    int bfst; cin>>bfst;
	visited.assign(n, false); 
	adj.assign(n, vector<int>()); 

	int a, b; 
	for (int i = 0; i < e; i++) { 
		cin >> a >> b; 
		adj[a].pb(b); 
	} 
    
    if (visited[bfst] == false){
        bfs(bfst);
    }
	return 0; 
} 

