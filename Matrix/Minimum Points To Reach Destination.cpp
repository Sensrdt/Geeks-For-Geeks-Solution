#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        int m, n;
        cin >> m >> n;
        int a[m][n];
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                cin >> a[j][k];
        int ha[m][n];
        if (a[m - 1][n - 1] > 0)
            ha[m - 1][n - 1] = 1;
        else
            ha[m - 1][n - 1] = abs(a[m - 1][n - 1]) + 1;
        for (int j = m - 2; j >= 0; j--)
            ha[j][n - 1] = max(ha[j + 1][n - 1] - a[j][n - 1], 1);

        for (int j = n - 2; j >= 0; j--)
            ha[m - 1][j] = max(ha[m - 1][j + 1] - a[m - 1][j], 1);
        for (int j = m - 2; j >= 0; j--)
            for (int k = n - 2; k >= 0; k--)
            {
                int Mn = min(ha[j + 1][k], ha[j][k + 1]);
                ha[j][k] = max(Mn - a[j][k], 1);
            }
        cout << ha[0][0] << endl;
    }

    return 0;
}