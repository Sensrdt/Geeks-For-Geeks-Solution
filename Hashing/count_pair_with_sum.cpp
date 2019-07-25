#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		int a[n];
		int count = 0;
		for (int i=0;i<n;i++) cin>>a[i];
		
		map<int, int> mp;
		for (int i=0;i<n;i++) mp[a[i]]++;
		
		for (int i=0;i<n;i++){
			count += mp[k - a[i]];
			//cout<<"Debug "<<count<<endl;
			
			if (k - a[i] == a[i]) {
				count--;
				//cout<<"Debug 1 "<<count<<endl;	
			}
			
		}
		
		cout<<count/2<<endl;
	}
}
