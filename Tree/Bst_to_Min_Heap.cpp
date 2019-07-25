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

int convert_to_array(Node *root, //vector<int>& 
                             int a[], int *i){
	if (root == NULL) return 0;
	//int i = -1;
	// inorder traversal 
	convert_to_array(root->left, a, i);
	a[++*i] = root->data;
	// vcout<<"Debug i "<<i<<" Debug a[i] "<<a[i]<<endl;
	//a.push_back(root->data);
	convert_to_array(root->right, a, i);
}
int convert_array_to_min_heap(Node *root, //vector<int>& 
                               int a[], int *i){
	if (root == NULL) return 0;
	
	root->data = a[++*i];
	
	convert_array_to_min_heap(root->left, a, i);
	convert_array_to_min_heap(root->right, a, i);
}
void min_heap(Node *root, int n){
	int i = -1;
	int j = -1;
	int a[n] = {0};
	//vector<int> a;
	convert_to_array(root, a, &j);
	//after getting the array 
	//for (int j=0;j<n;j++) cout<<a[j]<<" ";
	convert_array_to_min_heap(root, a, &i);
}
void preorderTraversal(Node *root) 
{ 
    if (!root) 
        return; 
  
    cout << root->data << " "; 
   
    preorderTraversal(root->left); 
  
    preorderTraversal(root->right); 
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
		
		min_heap(root, n);
		preorderTraversal(root);
	}
}
