#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
Node *bTreeToCList(Node *root);
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
	itr=itr->left;
	do{
		cout<<itr->data<<" ";
		itr=itr->left;
	}while(head!=itr);
	cout<<itr->data<<endl;
}
int main()
{
	int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
		if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    Node *head = bTreeToCList(root);
    displayCList(head); 
  }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node *concat(Node *leftList, Node *rightList){
	if (leftList == NULL) return rightList;
	if (rightList == NULL) return leftList;
	
	Node *leftLast = leftList->left;
	Node *rightLast = rightList->left;
	
	leftLast->right = rightList; 
    rightList->left = leftLast; 
  
    leftList->left = rightLast; 
  
    rightLast->right = leftList; 
  
    return leftList; 
}
Node *bTreeToCList(Node *root)
{
	if (root == NULL) return NULL;
	
	Node *left = bTreeToCList(root->left);
	Node *right = bTreeToCList(root->right);
	
	root->left = root->right = root;
	
	return concat(concat(left, root), right);
}
