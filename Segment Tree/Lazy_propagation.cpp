#include<bits/stdc++.h>
#define MAX (1+(1<<6)) 
#define inf 0x7fffffff
using namespace std;

int seg[MAX];

void build(int a[], int l, int h, int root){
    if (l == h){
        seg[root] = a[l];
    }
    int mid = ( l + h ) / 2;

    build(a, l, mid, 2*root+1);
    build(a, mid+1, h, 2*root+2);

    seg[root] = seg[2*root+1] + seg[2*root+2];
}

void print(){
    int n = sizeof(seg) / sizeof(int);
    for (int i=0; i<n; i++) cout<<seg[i]<<" ";

    cout<<endl;
}

void
int main(){
    int n; cin>>n;
    int a[n];
}