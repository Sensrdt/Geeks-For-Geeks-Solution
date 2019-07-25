#include<bits/stdc++.h>
/*
	5 4
	1 2
	1 3
	3 4
	2 5
	4 2
*/
using namespace std;

vector<vector<int> > adj(100,vector<int>());
vector<bool> visited(0, false);	

void dfs(int i){
	visited[i] = true;
	cout<<"adj size "<<adj[i].size()<<endl;
	for (int j=0; j<adj[i].size(); j++){
		cout<<"i "<<i<<" j "<<j<<endl;
		int u = adj[i][j];
		cout<<"u "<<u<<endl;
		if (visited[u] == false){
			cout<<u<<" "<<endl;
			dfs(u);
		}
	}
}
int main()
{
	int n, e; cin>>n>>e;
	int u, v;
	for (int i=0; i<n; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}	
	for (int i=0; i<n; i++){
		if (visited[i] == false){
			//cout<<"i "<<i<<endl;
			dfs(i);
		}
	}
}
