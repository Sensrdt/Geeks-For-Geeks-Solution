#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>m>>n;
        int g[m][n];
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                cin>>g[i][j];
            }
        }

        int dp[n][m];

        for (int col=n-1; col>=0; col--) 
        { 
            for (int row=0; row<m; row++) 
            {  
                int r = (col==n-1)? 0: dp[row][col+1]; 
    
                int rp = (row==0 || col==n-1)? 0: 
                                dp[row-1][col+1]; 
    
                int rd = (row==m-1 || col==n-1)? 0: 
                                dp[row+1][col+1]; 
    
                dp[row][col] = g[row][col] + 
                                max(r, max(rp, rd)); 
                                                        
            } 
        } 
    
        int res = dp[0][0]; 
        for (int i=1; i<m; i++) 
            res = max(res, dp[i][0]);
            
        cout<<res;    
    }

}