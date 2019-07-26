#include<bits/stdc++.h>
#define MAX (1+(1<<6)) 
#define inf 0x7fffffff

using namespace std;

int seg[MAX];

void build(int a[], int l, int h, int root){

    if (l == h){
        seg[root] = a[l];
        return;
    }
    int mid = ( l + h ) / 2;
    build(a, l, mid, 2*root + 1);
    build(a, mid+1, h, 2*root + 2);

    seg[root] = seg[2*root + 1] ^ seg[2*root + 2];
}

void print()
{
    int n = sizeof(seg) / sizeof(int);
    for (int i=0; i<n; i++) cout<<seg[i]<<" ";

    cout<<endl;
}

int range_query(int a[], int l, int h, int root, int ql, int qh){
    cout<<"in \n";
    // Total overlap
    if(l >= ql && h <= qh) 
		return seg[root];
    // No overlap
    if (ql > l && qh < h){
        return 0;
    }

    // Pratial overlap
    int mid = ( l +  h ) / 2;
    int first = range_query(a, l, mid, 2*root + 1, ql, qh);
    int second = range_query(a, mid+1, h, 2*root + 2, ql, qh);
    
    int temp = first ^ second;
    
    return temp;

}

int main()
{
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];

    build(a, 0, n-1, 0);
    print();
    int ql, qh; cin>>ql>>qh;
    // a, l, h, root, ql, qh
    int ans = range_query(a, 0, n-1, 0, ql, qh);
    cout<<ans;
}