#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};

struct Node *sortDoubly(struct Node *head);
//Position this line where user code will be pasted.
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */
// Function to merge two DLLs
 Node* split(Node *head)
{
    Node *slow = head,*fast = head->next;
    
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    
    Node *second = slow->next;
    slow->next = NULL;
    cout<<"Split Second "<<second->data<<endl;
    return second;
}

Node *merge(Node *first,Node *second)
{
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    cout<<"First 1 "<<first->data<<endl;
    cout<<"Second 1 "<<second->data<<endl;
	if(first->data < second->data)
    {
        first->next = merge(first->next,second);
        //cout<<"Debug "<<first->next->prev->data<<endl;
        //cout<<"Change "<<first->data<<endl;
        first->next->prev = first;
        first->prev = NULL;
        cout<<"First "<<first->data<<endl;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
       //out<<"Debug 1 "<<second->next->prev->data<<endl;
       //cout<<"Change 1 "<<second->data<<endl;
        second->next->prev = second;
        second->prev = NULL;
        cout<<"Second "<<second->data<<endl;
        return second;
    }
}

// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head)
{
	if(head==NULL || head->next==NULL)
	    return head;
	   
	Node *second = split(head);
	
	head = sortDoubly(head);
	second = sortDoubly(second);
	cout<<"head "<<head->data<<endl;
	head = merge(head,second);
	return head;
}
