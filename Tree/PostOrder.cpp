// Post-Order Traversal Left --> Right --> Root
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
		//setting the value of root by pointing to it
        (*root)->val = val;
        
	}else 
	if( (*root)->val > val)
	{
		//sending the address  
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

void postTrav(node *ptr)
{
    if(ptr){
    	
        preTrav(ptr->left);
        
    	preTrav(ptr->right);
    	
		printf("%lli\n", ptr->val);
    }
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
	        //sending he address
	        insert(&root, x);
	    }
	
	    scanf("%lli",&x);
	    
	    ptr = find(root,x);
	    std::cout<<"call 1 "<<ptr->val<<"\n";
	    postTrav(ptr);
	}
	
    return 0;
}















