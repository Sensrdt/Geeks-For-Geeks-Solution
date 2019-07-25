#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
//Position this line where user code will be pasted.
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* split(Node *head){
	Node *fast = head, *slow = head;
	
}
Node* mergeSort(Node* head) {
    /*
    	1. Split the linked list into 2 halves
    	2. Then reccursively split the 2 halves
    	3. Arrange different parts sortedly 
    */
    
    if (head == NULL || head->next == NULL) return head;
    
    struct Node *second = split(head);
    
}

