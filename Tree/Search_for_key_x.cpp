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

int find_iteratively(Node *root, int x){
	//cout<<"Debug "<<endl;
	if (root == NULL) return false;
	queue<Node *> q;
	q.push(root);
	
	while(q.empty() == false){
		struct Node *temp = q.front();
		//cout<<"Debug 1 "<<temp->data<<endl;
		if (temp->data == x) {
			//cout<<"Debug "<<temp->data<<endl;
			return true;	
		}
		q.pop();
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
	
	return false;
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
		
		int f; cout<<"Enter the key to find :-"; cin>>f;
		bool get = find_iteratively(root, f);
		cout<<get;
		
	}
}
