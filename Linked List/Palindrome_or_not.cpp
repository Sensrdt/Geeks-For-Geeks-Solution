
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */#include<bits/stdc++.h>
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
#include<stack>
bool isPalindrome(Node *head)
{
    // Double pointer approach
    struct Node *slow = head;
    struct Node *fast = head;
    
    bool flag = true;
    
    stack<int> s;
   
    while(fast != NULL && fast->next != NULL){
    	s.push(slow->data);
    	slow = slow->next;
    	fast = fast->next->next;
	}
	// If linked list's length is odd 
	if (fast != NULL){
		slow = slow->next;
	}
    int j = 0;
    while(slow!=NULL){
        int i = s.top();
        cout<<"Checking the stack value "<<i<<endl;
        cout<<"Going into the stack "<<j++<<endl;
       
        if (slow->data!=i) {
            flag = 0;
            break;
        }
        slow = slow->next;
        s.pop();
    }
    
    if (flag == 0)return false;
    else return true;
}
