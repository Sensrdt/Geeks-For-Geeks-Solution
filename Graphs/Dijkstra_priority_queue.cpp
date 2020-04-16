#include<bits/stdc++.h>
#define inf 10000
using namespace std;

int dis[10000] = {10000};
/**
  1
  4
  5
  1 2 5
  1 3 6
  2 3 5
  2 4 5
  3 4 5
  1 4
*/

void dijkstra(int source, vector< pair< int, int > > graph[]){

  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;  /**
    (0, 1)
    (5, 2)
    (6, 3)
  */

  pq.push(make_pair(0, source));

  for (int i=0; i<10000; i++)
    dis[i] = inf;

  dis[source] = 0;

  while(pq.empty() == false){
    int t = pq.top().second;

    pq.pop();

    for (auto i : graph[t]){
      int vertex = i.first;
      int weight = i.second;

      if (dis[vertex] > dis[t] + weight){
        dis[vertex] = dis[t] + weight;
        pq.push(make_pair(dis[vertex], vertex));
      }
    }
  }

}

int main()
{
  int t; cin >> t;

  while(t--)
  {
    int e, v;
    cin >> v >> e;

    vector< pair< int, int > > graph[10001];
    int x, y, w;

    for (int i=0; i<e; i++){
      cin >> x >> y >> w;

      graph[x].push_back(make_pair(y, w));
    }

    int source, destination;
    cin >> source >> destination;

    dijkstra(source, graph);

    if (dis[destination] < inf){
      cout <<endl << dis[destination]<< "\n";
    }else{
      cout<<"\nNO\n";
    }
  }
}
