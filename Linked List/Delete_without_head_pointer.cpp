#include<bits/stdc++.h>

using namespace std;
void deleteNode(Node *pos)
{
   if (pos == NULL ) return;
   else {
       struct Node* temp = pos->next; 
  
       
        pos->data = pos->next->data;  
  
       
        pos->next = pos->next->next;  
  
        free(temp);
       
   }
   
   return ;
}
int main()
{
   

}