#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for (int i=0; i<n; i++) cin>>a[i];

        int dp[n];

        for (int i=0; i<n; i++){
            for (int j=1; j<i; j++){
                if (a[i] > a[j] && (a[i]+a[j]%2 == 0)){
                    dp[i] = dp[] 
                }
            }
        }
    }
}