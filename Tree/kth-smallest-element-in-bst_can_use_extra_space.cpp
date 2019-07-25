
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
typedef struct Node Node;
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};
int KthSmallestElement(Node *root, int k);
Node *insert_node(Node *root, Node* node)
{
    Node *pTraverse = root;
    Node *currentParent = root;
 
    while(pTraverse)
    {
        currentParent = pTraverse;
 
        if( node->data < pTraverse->data )
        {
            pTraverse->lCount++;
            pTraverse = pTraverse->left;
        }
        else
        {
            pTraverse = pTraverse->right;
        }
    }
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        currentParent->left = node;
    }
    else
    {
        currentParent->right = node;
    }
 
    return root;
}
Node* binary_search_tree(Node *root, int keys[], int const size)
{
    int iterator;
    Node *new_node = NULL;
 
    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (Node *)malloc( sizeof(Node) );
 
        /* initialize */
        new_node->data   = keys[iterator];
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;
 
        /* insert into BST */
        root = insert_node(root, new_node);
    }
 
    return root;
}
 
 int main(void)
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
    int ele[n];
	for(int i=0;i<n;i++){
		cin>>ele[i];
	}
    int k;
	cin>>k;
    Node* root = NULL;
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));
        printf("%d",KthSmallestElement(root, k));
	}
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};*/
#include<stack>
int KthSmallestElement(Node *root, int k)
{
    stack<Node*> st;
    Node* cur  = root;
    while(cur != NULL || !st.empty()){
        if (cur != NULL){
            st.push(cur);
            cout<<"first "<<st.top()->data<<endl;
            cur = cur->left;
        }else{
            cur = st.top();
            int x = cur->data;
            cout<<"x "<<x<<endl;
            //cout<<"cur 1 "<<cur->data<<endl;
            st.pop();
            k--;
            if (k == 0){
                return cur->data;
            }
            cur = cur->right;
//            int y = cur->data;
//            cout<<"y "<<y<<endl;
            // cout<<"cur 2 "<<cur->data<<endl;
        }
    }
}
