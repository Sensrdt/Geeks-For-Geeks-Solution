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

int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   
   rep(i,1,n+1,1) 
   { 
       int max_val = INT_MIN; 
       rep(j,0,i,1) 
        {
			max_val = max(max_val, price[j] + val[i-j-1]);
			cout<<"price[j]= "<<price[j]<<" j= "<<j<<endl;
			cout<<"val[i-j-1]= "<<val[i-j-1]<<" j= "<<j<<" i= "<<i<<" i-j-1= "<<i-j-1<<endl;
			cout<<"max_val= "<<max_val<<endl;
		}  
       val[i] = max_val; 
       cout<<"i= "<<i<<" val[i] = "<<val[i]<<endl;
   } 
  
   return val[n]; 
} 
int main()
{
	fast
	int n; cin>>n;
	
	int val[n];

	rep(i,0,n,1) cin>>val[i];
	int x = cutRod(val, n);
	
	cout<<x;
	return 0;
}

