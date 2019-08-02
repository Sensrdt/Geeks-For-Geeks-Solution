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

int min (int a, int b) { return (a < b)? a : b; } 
   

int pp(string str) 
{ 
    
    int n = str.length(); 
   
    
    int C[n]; 
    bool P[n][n]; 
   
    int i, j, k, L;
    for (i=0; i<n; i++) 
    { 
        P[i][i] = true; 
    } 
   
    
    for (L=2; L<=n; L++) 
    { 
        for (i=0; i<n-L+1; i++) 
        { 
            j = i+L-1; 
         
            if (L == 2) 
                P[i][j] = (str[i] == str[j]); 
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1]; 
        } 
    } 
  
    for (i=0; i<n; i++) 
    { 
        if (P[0][i] == true) 
            C[i] = 0; 
        else
        { 
            C[i] = INT_MAX; 
            for(j=0;j<i;j++) 
            { 
                if(P[j+1][i] == true && 1+C[j]<C[i]) 
                    C[i]=1+C[j]; 
            } 
        } 
    } 
   
    return C[n-1]; 
} 

int main()
{
	fast
	string s; cin>>s;
	int n = s.length();
	
	int result = pp(s);
	
	cout<<result<<endl;
	return 0;
}

