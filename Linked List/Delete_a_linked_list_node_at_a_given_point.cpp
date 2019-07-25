#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void insert_node(struct Node ** head, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

void delete_node(struct Node **head, int position)
{
	if (*head == NULL) return;

	struct Node* temp = *head;
	//temp is refering to head

	if(position == 0)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	for (int i=0; temp!=NULL && i<position-1; i++){
		 temp = temp->next;
		 cout<<"Call 1 "<<temp<<endl;
	}

	if (temp == NULL || temp->next == NULL) return;

	struct Node *next = temp->next->next;
	free(temp->next);

	temp->next = next;

}

void print(struct Node *node){
	while(node!=NULL){
		cout<<node->data;
		node = node->next;
	}
}
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
		int t;
		cin>>t;
		int x;
		while(t--)
		{
					int n; cin>>n;
					for (int i = 0; i < n; i++) {
						cin>>x;
						insert_node(&head, x);
					}

		    /*
				insert_node(&head, 7);
		    insert_node(&head, 1);
		    insert_node(&head, 3);
		    insert_node(&head, 2);
		    insert_node(&head, 8);
				*/
			    puts("Created Linked List: ");
			    print(head);
					int del;
					cout<<"From where ";
					cin>>del;
			    delete_node(&head, del);
			    print(head);
					//free(head);
		}
    return 0;
}
