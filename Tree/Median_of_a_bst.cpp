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
int inorder(Node *root, //vector<int>& 
						int a[], int *i){
	//cout<<"Debug"<<endl;
	if(root == NULL)  return 0;
	
	inorder(root->left, a, i);
	a[++*i] = root->data;
	//cout<<"Debug 1"<<endl;
	inorder(root->right, a, i);
}
int median_count(Node *root, int n){
	// Send to perform inorder 
	int i = -1;
	//vector<int> a;
	int a[n];
	inorder(root, a, &i);
	//int n = a.size();
	//cout<<n<<endl;
	for (int j=0;j<n;j++) cout<<a[j]<<" ";
	if (n%2 == 0){
		return (a[n/2 - 1]+a[n/2])/2;
	}else{
		return a[n/2];
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
		cout<<endl<<median_count(root, n);
	}
}
