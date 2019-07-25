#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h> 

#define MAX (1+(1<<6)) 
#define inf 0x7fffffff

int arr[20];
int tree[MAX];


void build_tree(int node, int a, int b) {
    if(a > b) return; 
  	
  	if(a == b) { 
    		tree[node] = arr[a]; 
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); 
	build_tree(node*2+1, 1+(a+b)/2, b); 
	
	tree[node] = max(tree[node*2], tree[node*2+1]); 
}


void update_tree(int node, int a, int b, int i, int j, int value) {
    
	if(a > b || a > j || b < i) 
		return;
    
  	if(a == b) { 
    		tree[node] += value;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); 
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); 

	tree[node] = max(tree[node*2], tree[node*2+1]); 
}


int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; 

	if(a >= i && b <= j) 
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); 
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 

	int res = max(q1, q2); 
	
	return res;
}

int main() {
    int N; cin>>N;
	for(int i = 0; i < N; i++) cin>>arr[i];

	build_tree(1, 0, N-1);
    int ql, qh, val; cin>>ql>>qh>>val;
	update_tree(1, 0, N-1, ql, qh, val); 
    int qql, qqh; cin>>qql>>qqh;
	cout << query_tree(1, 0, N-1, qql, qqh) << endl; 
}