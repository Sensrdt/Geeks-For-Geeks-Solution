#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin>>t;
	while(t--){
			int op = 0;
			int n; cin>>n;
			int a[n];
			for (int i=0;i<n;i++) cin>>a[i];
			int max = INT_MIN;
			map<int, int> mp;
			for (int i=0;i<n;i++) mp[a[i]]++;
			
			for(int i=0;i<mp.size();i++){
				if (max < mp[a[i]]){
					max = mp[a[i]];
					op = a[i];
				}
			}
			cout<<op<<endl;
	}
}
