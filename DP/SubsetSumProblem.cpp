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

int main()
{
	fast
	int n; cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++) cin>>a[i];
	int r; cin>>r;
	
	bool dp[n+1][r+1];
	
	for (int i=0;i<r+1;i++) dp[0][i] = false;
	for (int i = 0; i <= n; i++) 
      	dp[i][0] = true; 
   
	for (int i=1;i<n+1;i++){
		for (int j=1;j<r+1;j++){
			if(j<a[i-1]) //if a[i] or the value in the array is greater than the sum value then take it from the top 
         		dp[i][j] = dp[i-1][j]; 
         	if (j >= a[i-1]) //if any of the value .i.e. from top or from moving j-a[i-1] steps back is true it will return true
           		dp[i][j] = dp[i-1][j] ||  
                                 dp[i - 1][j-a[i-1]]; 
		}
	}
	cout<<dp[n][r];
	
	return 0;
}

