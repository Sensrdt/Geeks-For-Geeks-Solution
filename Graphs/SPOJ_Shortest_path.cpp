#include<bits/stdc++.h>

using namespace std;

int dist[1000];

void dijkstra(vector< pair<int, int> > adj[], int from, int to){
    for (int i=0; i<1000; i++){
        dist[i] = 10000;
    }
    
    dist[from] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, from));
    
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

void print(){
    int n = sizeof(dist) / sizeof(int);
    for (int i=0; i<n; i++) cout<<dist[i]<<" ";
    cout<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int nc; cin>>nc;
        string city;
        int nn, d, w;
        map<string, int> mp;
        vector< pair<int, int> > adj[10000];
        for (int i=0; i<nc; i++){
            cin>>city;
            mp[city] = i;
            cin>>nn;
            for (int j=0; j<nn; j++){
                cin>>d>>w;
                adj[i].push_back(make_pair(d, w));   
            }
        }
        int no; cin>>no;
        string from, to;
        while(no--){
            cin>>from>>to;
            int from_i = mp[from];
            int to_i = mp[to];
            dijkstra(adj, from_i, to_i);
           // print();
           cout<<dist[to_i]<<endl;
        }
        
    }
}