#include <bits/stdc++.h>

using namespace std;

int code(int n)
{
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    vector<char> coded;

    while (n != 0)
    {
        int rem = n % 62;
        //cout<<"rem "<<rem <<" coded "<<alpha[rem]<<endl;
        coded.push_back(alpha[rem]);
        n = n / 62;
    }

    reverse(coded.begin(), coded.end());
    for (int i = 0; i < coded.size(); i++)
    {
        cout << coded[i];
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int copy = n;

        /* 
            1. Code
            2. Decode
        */

        code(n);
        cout << copy << endl;
    }
}