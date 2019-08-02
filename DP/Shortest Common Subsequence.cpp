#include<bits/stdc++.h>

using namespace std;
/*
    1. Longest Common Subsequence ( LCS )
    2. Summation of the lengths of two strings
*/
int send(string X, string Y){
    int m = X.length(), n = Y.length();
    int L[m + 1][n + 1]; 
    int i, j; 
  
    for (i = 0; i <= m; i++) 
    { 
        for (j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], 
                               L[i][j - 1]); 
        } 
    } 
    return L[m][n];
    
}
int main()
{
    int t; cin>>t;
    while(t--){
        string s, s1; cin>>s>>s1;
        int n = s.length(), m = s1.length();
        int total_sum = n + m;
        int lcs_total = send(s, s1);
        cout<<total_sum - lcs_total<<endl;
    }
}
