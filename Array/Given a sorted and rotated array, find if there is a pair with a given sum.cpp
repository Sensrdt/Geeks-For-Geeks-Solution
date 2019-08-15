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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int d;
        cin >> d;
        int i;
        for (i = 0; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                break;
            }
        }
        int l = i + 1;
        int r = i;
        bool flag = false;
        while (l != r)
        {
            if (a[r] + a[l] == d)
            {
                flag = true;
                break;
            }

            if (a[r] + a[l] < d)
            {
                l = l + 1;
            }
            else
                r = n + r - 1;
        }

        if (flag)
        {
            cout << "true\n";
        }
        else
            cout << "false\n";
    }
}