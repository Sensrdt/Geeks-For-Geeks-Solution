#include<bits/stdc++.h>

using namespace std;
set<int> s;
int get_fibo(int n){
	int a = 0, b = 1;
	s.insert(a);
	s.insert(b);
	while(b <= n){
		int c = a + b;
		a = b;
		b = c;
		s.insert(c);
		//cout<<"Debug "<<c<<endl;
	} 
}
int main()
{
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		for (int i=0;i<n;i++) cin>>a[i];
		//for (int i=0;i<n;i++) b[i] = a[i];
		int m = *std::max_element(a, a+n);
		get_fibo(m);
		
		for (int i=0;i<n;i++){
			if (s.find(a[i]) != s.end()){
				cout<<a[i]<<" ";
			}
			
		}
		
		cout<<endl;
	}
}
