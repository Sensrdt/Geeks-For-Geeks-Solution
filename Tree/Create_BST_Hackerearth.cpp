/*
Create a Binary Search Tree from list A containing N elements. Insert elements in the same order as given. Print the pre-order traversal of the subtree with root node data equal to Q (inclusive of Q), separating each element by a space.

Input:
First line contains a single integer N – number of elements.
Second line contains N space-separated integers. 
Third line contains a single integer Q – the element whose subtree is to be printed in pre-order form.

Output:
Print K space-separated integers – where K is the number of elements in the subtree of Q (inclusive of Q)

Constraints:



SAMPLE INPUT 
4
2 1 3 4
3
SAMPLE OUTPUT 
3
4
*/
// Pre-Order Traversal Root --> Left --> Right
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define ll long long 	

typedef struct node
{
	
    ll val;
    struct node* left;
    struct node* right;
    
}node;

void insert(node ** root, ll val)
{
	if(*root == NULL)
	{
		*root = (node*)calloc(1, sizeof(node));
        (*root)->val = val;
        
	}else 
	if( (*root)->val > val)
	{
		 insert( &(*root)->left, val);
		 
	}else{
		
		insert( &(*root)->right, val);

	}
}

node * find(node *ptr, ll key)
{
    if(ptr){
        if(ptr->val == key)
            return ptr;
        else if(ptr->val > key)
            return find(ptr->left, key);
        else
            return find(ptr->right, key);   
    }else
        return NULL;
}

void preTrav(node* ptr)
{
    if(ptr){
        printf("%lli\n", ptr->val);
        preTrav(ptr->left), preTrav(ptr->right);
    }
}


int main()
{
	int t; std::cin>>t;
	while(t--)
	{
		ll n, x;
		scanf("%lli", &n);
		
		node* root ,*ptr;
		root = NULL;
		
	    for(ll i = 0; i < n; i++)
		{
	        scanf("%lli", &x);
	        insert(&root, x);
	    }
	
	    scanf("%lli",&x);
	    
	    ptr = find(root,x);
	    std::cout<<"call 1 "<<ptr->val<<"\n";
	    preTrav(ptr);
	}
	
    return 0;
}















