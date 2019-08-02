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

int getSum(int freq[], int i, int j){
        int sum = 0;
        for(int x = i; x <= j; x++){
            sum += freq[x];
        }
        return sum;
    }

int opbst(int k[], int f[], int n)
{
	int c[n][n];
	rep(i,0,n,1)
	{
		c[i][i] = f[i];
	}
	
	rep(l,2,n+1,1)
	{
		rep(i,0,n,1){
			int j = i + l -1;
                c[i][j] = INT_MAX;
                int sum = getSum(f, i, j);
                
                for(int k=i; k <= j; k++){
                     int val = sum + (k-1 < i ? 0 : c[i][k-1]) +
                            (k+1 > j ? 0 : c[k+1][j]) ;
                     if(val < c[i][j]){
                         c[i][j] = val;
                     }
                }
		}
	}
	
	return c[0][n-1];
}

int main()
{
	fast
	int n; cin>>n;
	int k[n], f[n]; 
	rep(i,0,n,1) cin>>k[i];
	rep(i,0,n,1) cin>>f[i];
	
	int result = opbst(k, f, n);
	cout<<result<<endl;
	return 0;
}

