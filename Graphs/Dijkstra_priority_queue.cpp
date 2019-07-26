#include<bits/stdc++.h>
#define MAX (1+(1<<6)) 
#define inf 0x7fffffff
using namespace std;

int dist[1000] = {10000};

void dijkstra(int from, vector<pair<int, int>> adj[]){
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, from));
    //dist[from] = 0;
    for (int i=0; i<1000; i++) {
        dist[i] = inf;
    }
    dist[from] = 0;
   
    while(pq.empty() == false){
        int u = pq.top().second;
        
        pq.pop();
        for (auto i : adj[u]){
            int v = i.first;
            int w = i.second;
            
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
               
            }
        }
    }

    
}

int main()
{
    int t; cin>>t;
    while(t--){
        vector< pair<int, int>> adj[10001];
        int v, e; cin>>v>>e;
        int x, y, w;
        
        for (int i=0; i<e; i++){
            cin>>x>>y>>w;
            adj[x].push_back(make_pair(y, w));
        }

        int from, to;
        cin>>from>>to;
        dijkstra(from, adj);
        //for (int i=0; i<v; i++) cout<<dist[i]<<" ";
        //cout<<endl;
        if (dist[to] < inf ){
            cout<<dist[to]<<endl;
        }else{
            cout<<"NO\n";
        }
    }
}