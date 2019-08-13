#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

Node *newNode(int item){
	Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	
	return temp;
}

Node *insert(Node *root, int data){
	if (root == NULL) return newNode(data); 

	if (data < root->data) 
		root->left = insert(root->left, data); 
	else if (data > root->data) 
		root->right = insert(root->right, data); 

	return root;	
}
bool same_or_not(Node *root1, Node *root2){
	if (root1 == NULL && root2 == NULL) return 1;
	if (root1 != NULL && root2 != NULL){
		return (root1->data == root2->data && same_or_not(root1->left, root2->left) && same_or_not(root1->right, root2->right));
	}
	
	return 0;
}
int main()
{
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		Node *root = NULL;
		int x;
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
		
		
	}
}
