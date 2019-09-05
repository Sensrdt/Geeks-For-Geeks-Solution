
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of a BST node is as follows:
struct Node
{
    int data;
    Node *left;
    Node *right;
};
*/
int getCountOfNode(Node *root, int low, int high)
{
    if (!root)
        return 0;

    if (root->data == high && root->data == low)
        return 1;

    if (root->data <= high && root->data >= low)
        return 1 + getCountOfNode(root->left, low, high) +
               getCountOfNode(root->right, low, high);

    else if (root->data < low)
        return getCountOfNode(root->right, low, high);

    else
        return getCountOfNode(root->left, low, high);
}