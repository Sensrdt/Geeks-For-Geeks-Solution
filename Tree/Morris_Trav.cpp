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
	if (root == NULL){
		return newNode(data);
	}
	if (data < root->data) root->left = insert(root->left, data);
	if (data > root->data) root->right = insert(root->right, data);
	
	return root;
}

int Morris_Traversal(Node *root){
	struct Node *current, *pre; 
    current = root; 
    while (current != NULL) { 
  
        if (current->left == NULL) { 
            printf("%d ", current->data); 
            current = current->right; 
        } 
        else { 
  
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            if (pre->right == NULL) { 
                pre->right = current; 
                current = current->left; 
            } 
  
            else { 
                pre->right = NULL; 
                printf("%d ", current->data); 
                current = current->right; 
            } 
        } 
    } 
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
		
		cout<<Morris_Traversal(root)<<endl;
	}
}
