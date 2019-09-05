{
#include <bits/stdc++.h>
#define MAX_SIZE 100
    using namespace std;
    struct node
    {
        int val;
        struct node *left, *right;
    };
    bool isPairPresent(struct node * root, int target);
    struct node *NewNode(int val)
    {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->val = val;
        tmp->right = tmp->left = NULL;
        return tmp;
    }
    struct node *insert(struct node * root, int a)
    {
        if (root == NULL)
            return NewNode(a);
        if (root->val > a)
        {
            root->left = insert(root->left, a);
        }
        if (root->val < a)
        {
            root->right = insert(root->right, a);
        }
        return root;
    }
    void inorder(struct node * root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n, target;
            cin >> n >> target;
            struct node *root = NULL;
            while (n--)
            {
                int a;
                cin >> a;
                if (root == NULL)
                {
                    root = NewNode(a);
                }
                else
                {
                    insert(root, a);
                }
            }
            //inorder(root);
            cout << isPairPresent(root, target) << endl;
        }
        return 0;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
#include <bits/stdc++.h>

void send(struct node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    send(root->left, v);
    v.push_back(root->val);
    send(root->right, v);
}
bool isPairPresent(struct node *root, int target)
{
    if (root == NULL)
        return false;

    //inorder
    vector<int> v;
    int flag = 0;
    send(root, v);
    int n = v.size(), i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (v[i] + v[j] == target)
            return true;
        else if (v[i] + v[j] < target)
            i++;
        else
            j--;
    }
    return false;
}