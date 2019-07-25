#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int main()
{
    int v, e; cin>>v>>e;
    int s = 0;
    int x, y, w;
    vector< pair< int, int > > adj[v];

    for (int i=0; i<e; i++){
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }

    priority_queue< pair <int, int>, vector< pair< int, int> >, greater< pair <int, int> > > pq;
    pq.push(make_pair(s, 0));

    vector< int > key(v, inf);
    vector< int > parent(v, -1);
    vector< bool > mst(v, false);

    pq.push(make_pair(0, s));
    key[s] = 0;

    while(pq.empty() == false){
        int x = pq.top().second;
        pq.pop();

        for (auto i : adj[x]){
            int v = i.first;
            int w = i.second;

            if (mst[v] == false && key[v] > w){
                key[v] = w;
                pq.push(make_pair(key[v], w));  
                parent[v] = w;
            }
        }
    }

    for (int i=0; i<v; i++){
        cout<<"i "<<i<<" parent[i] "<<parent[i]<<endl;
    }
}