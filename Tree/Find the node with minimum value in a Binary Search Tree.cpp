#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define ll long long 	

typedef struct node
{
	
    ll val;
    struct node *left,*right;
    
}node;

void insert(node** root, ll val)
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

void minelement(node *ptr)
{
    /*if(ptr){
        printf("%lli\n", ptr->val);
        preTrav(ptr->left), preTrav(ptr->right);
    }*/
    struct node* x = ptr;
    while(x->left != NULL){
    	x = x->left;
	}
    std::cout<<x->val<<"\n";
}


int main()
{
	int t; std::cin>>t;
	while(t--)
	{
		ll n, x;
		scanf("%lli", &n);
		
		node *root = NULL,*ptr;
		
	    for(ll i = 0; i < n; i++)
		{
	        scanf("%lli", &x);
	        insert(&root, x);
	    }
	
	    scanf("%lli",&x);
	    
	    ptr = find(root,x);
	    std::cout<<"call 1 "<<ptr->val<<"\n";
	    minelement(ptr);
	}
	
    return 0;
}















