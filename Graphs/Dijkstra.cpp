//Sridip => { sensrdt  © RCCIIT }
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ;
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007
#define vec vector
#define inf 1e5+5
#define iu(x) ul x ; cin>>x ;
#define il(x) ll x ; cin>>x ;
#define pr(x) cout<<x ;
#define all(v) (v).begin() , (v).end()
#define sz(v)  (long int)(v).size()
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )

#define f first
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define ct(t) cout<<t<<endl
#define inarr(n) int n ; cin>>n ; vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]
#define ouarr(n) lp ( i , n) cout<<v[i]<<" ";
#define fast ios::sync_with_stdio(false); cin.tie(0);


void add(vp adj[], int x, int y, int w){
	adj[x].push_back(make_pair(y, w));
	adj[y].push_back(make_pair(x, w));
}

void dijkstra(vp adj[], int v, int from){
	priority_queue< pll, vp, greater<pll> > pq;
	vll dist(v, inf);
	pq.push(make_pair(0, from));
	dist[from] = 0;
	
	while(pq.empty() == false){
		int u = pq.top().second;
		pq.pop();
		
		for (auto i : adj[u]){
			int v = i.first;
			int w = i.second;
			
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[u], v));
			}
		}
	}
	
	for (int i = 0; i < v; ++i) 
       cout<<"i "<<i<<" dist[i] "<<dist[i]<<endl;
}

int main()
{
	fast
	int v = 9;
	vp adj[v];
	int x, y, w;
	add(adj, 0, 1, 4); 
    add(adj, 0, 7, 8); 
    add(adj, 1, 2, 8); 
    add(adj, 1, 7, 11); 
    add(adj, 2, 3, 7); 
    add(adj, 2, 8, 2); 
    add(adj, 2, 5, 4); 
    add(adj, 3, 4, 9); 
    add(adj, 3, 5, 14); 
    add(adj, 4, 5, 10); 
    add(adj, 5, 6, 2); 
    add(adj, 6, 7, 1); 
    add(adj, 6, 8, 6); 
    add(adj, 7, 8, 7); 
	dijkstra(adj, v, 0);
	return 0;
}
