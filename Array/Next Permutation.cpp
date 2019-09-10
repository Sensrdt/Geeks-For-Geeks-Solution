#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;

        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }

        next_permutation(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }

        cout << endl;
    }
}