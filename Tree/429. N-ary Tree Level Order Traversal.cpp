/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
static auto x = []() {std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> output;
        if (!root)
            return output;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 1; i <= n; i++)
            {
                Node *current = q.front();
                q.pop();
                temp.push_back(current->val);
                if (current->children.size() > 0)
                    for (auto child : current->children)
                        q.push(child);
            }
            output.push_back(temp);
        }
        return output;
    }
};