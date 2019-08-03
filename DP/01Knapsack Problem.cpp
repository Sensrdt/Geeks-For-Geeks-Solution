
//Sridip => { sensrdt  � RCCIIT }
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
#define iu(x) int x ; cin>>x ;
#define il(x) ll x ; cin>>x ;
#define pr(x) cout<<x ;
#define all(v) (v).begin() , (v).end()
#define sz(v)  (long int)(v).size()
#define lp(i , n ) for ( int i = 0 ; i < n ; i++ )
#define lpt(i , n ) for ( int i = 0 ; i <= n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i <= b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )

#define cnt continue;
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define ct(t) cout<<t<<endl
#define inarr(n) int n ; cin>>n ; vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]
#define ouarr(n) lp ( i , n) cout<<v[i]<<" ";
#define fast ios::sync_with_stdio(false); cin.tie(0);

int max(int a, int b) { return (a > b)? a : b; } 

int knapSack(int W, int wt[], int val[], int n) 
{ 
int i, w; 
int K[n+1][W+1]; 

for (i = 0; i <= n; i++) 
{ 
	for (w = 0; w <= W; w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if (wt[i-1] <= w) {
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
				// cout<<"---------START------------"<<endl;
				// cout<<"i "<<i<<" w "<<w<<endl;
				// cout<<"i-1 "<<i-1<<endl;
				// cout<<"val[i-1] "<<val[i-1]<<endl;
				// cout<<"wt[i-1] "<<wt[i-1]<<endl;
				// cout<<"w-wt[i-1] "<<w-wt[i-1]<<endl;
				// cout<<"K[i-1][w-wt[i-1]] "<<K[i-1][w-wt[i-1]]<<endl;	
				// cout<<"---------------K[i][w]------------"<<K[i][w]<<endl;			
		} 
		else
				K[i][w] = K[i-1][w]; 
	} 
} 

return K[n][W]; 
} 

int main() 
{ 
	//int val[] = {60, 100, 120}; 
	//int wt[] = {10, 20, 30}; 
	//int W = 50; 
	//int n = sizeof(val)/sizeof(val[0]); 
	int W, n; cin>>W>>n;
	int val[n], wt[n];
	for(int i=0 ;i<n;i++) cin>>val[i];
	for(int j=0;j<n;j++) cin>>wt[j];
	cout<<knapSack(W,wt,val,n); 
	return 0; 
} 

