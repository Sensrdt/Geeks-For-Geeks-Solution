#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
Node* insert(Node* node, int data) 
{ 
	if (node == NULL) return newNode(data); 

	if (data < node->data) 
		node->left = insert(node->left, data); 
	else if (data > node->data) 
		node->right = insert(node->right, data); 

	return node; 
}
/*void preTrav(Node* ptr)
{
    if(ptr){
        printf("%lli\n", ptr->data);
        preTrav(ptr->left);
		 preTrav(ptr->right);
    }
}*/
//Morris Traversal in O(1) space
int k_smallest_element(Node *root, int k){
	int count = 0; 

	int ksmall = INT_MIN; 
	Node *curr = root;  

	while (curr != NULL) 
	{ 
		if (curr->left == NULL) 
		{ 
			count++; 

			if (count==k) 
				ksmall = curr->data; 

			curr = curr->right; 
		} 
		else
		{  
			Node *pre = curr->left; 
			while (pre->right != NULL && pre->right != curr) 
				pre = pre->right; 

			if (pre->right==NULL) 
			{ 
				pre->right = curr; 
				curr = curr->left; 
			} 

			else
			{ 
				pre->right = NULL; 

				count++; 

				if (count==k) 
					ksmall = curr->data; 

				curr = curr->right; 
			} 
		} 
	} 
	return ksmall; 
}
int main()
{
	
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int  x;
		Node *root = NULL;
		int k; cout<<"Enter kth term :- ";cin>>k;
		for (int i=0;i<n;i++){
			if (i == 0){
				cout<<"Insert root value :- ";
				cin>>x;
				root = insert(root, x);
			}else{
				cin>>x;
				insert(root, x);
			}
		}
		
		cout<<"O/P :- "<<k_smallest_element(root, k)<<endl;
	}
	
}
