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


int min1(int a,int b, int c){
        int l = min(a, b);
        return min(l, c);
    }
    
int main()
{
	/*fast
	int n, m;
	cin>>n>>m;
	int c[n][m];
	int dp[n+1][m+1];
	for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
               {
               		cin>>c[i][j];
               		cout<<"i "<<i<<" j "<<j<<" "<<c[i][j]<<endl;
				} 
    dp[0][0] = c[0][0];     
    
    for (int j = 1; j < n; j++) {
    	dp[j][0] = dp[j-1][0] + c[j][0]; 
    	cout<<"dp[j-1][0] "<<" j-1 "<<j-1<<" "<<dp[j-1][0]<<endl;
    	cout<<"c[j][0] "<<" j "<<j<<" "<<c[j][0]<<endl;
    	cout<<"dp[j][0] "<<" j "<<j<<" "<<dp[j][0]<<endl<<endl<<endl;
	}
        
    for (int i = 1; i < m; i++){
    	dp[0][i] = dp[0][i-1] + c[0][i];
    	cout<<"---------------------\n dp[0][i-1] "<<" i-1 "<<i-1<<" "<<dp[0][i-1]<<endl;
    	cout<<"c[0][i-1] "<<" i-1 "<<i-1<<" "<<c[0][i-1]<<endl;
    	cout<<"dp[0][i] "<<" i "<<i<<" "<<dp[0][i]<<endl<<endl<<endl;
	} 
        
	
	for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j] = min(  
                           dp[i-1][j],  
                           dp[i][j-1]) + c[i][j];
                cout<<" dp[i-1][j-1] "<<" i-1 "<<i-1<<" j-1 "<<j-1<<" "<<dp[i-1][j-1]<<endl;
                cout<<" dp[i-1][j] "<<" i-1 "<<i-1<<" j "<<j<<" "<<dp[i-1][j]<<endl;
                cout<<" dp[i][j-1] "<<" i "<<i<<" j-1 "<<j-1<<" "<<dp[i][j-1]<<endl;
                cout<<" c[i][j] "<<" i "<<i<<" j "<<j<<" "<<c[i][j]<<endl;
                cout<<" dp[i][j] "<<"i "<<i<<" j "<<j<<" "<<dp[i][j]<<endl<<endl<<endl;
            }
        }
		
		cout<<dp[n-1][m-1];
		
		return 0;	    */
		
		
		fast 
		iu(n);
		iu(m);
		
		ul c[n][m];
		
		rep(i,0,n,1){
			rep(j,0,m,1){
				cin>>c[i][j];
			}
		}
		ul dp[n+1][m+1];
		
		dp[0][0] = c[0][0];
		
		rep(i,1,n,1) dp[i][0] = dp[i-1][0] + c[i][0]; 
		rep(j,1,m,1) dp[0][j] = dp[0][j-1] + c[0][j];
		
		rep(i,1,n,1){
			rep(j,1,n,1){
				dp[i][j] = min(  
                           dp[i-1][j],  
                           dp[i][j-1]) + c[i][j];
			}
		}
		
		cout<<dp[n-1][m-1];
		
		return 0;
		
		/* If we need to move diagoanl then this following code is applicable
			dp[i][j] = min1(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + c[i][j];
			min1 is declared above which will return minimum of 3 numbers
		*/	
}

