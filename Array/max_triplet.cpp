//Sridip => { sensrdt  © RCCIIT }
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ul;
typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vp;

#define MOD 1000000007
#define vec vector
#define iu(x) \
    ul x;     \
    cin >> x;
#define il(x) \
    ll x;     \
    cin >> x;
#define pr(x) cout << x;
#define all(v) (v).begin(), (v).end()
#define sz(v) (long int)(v).size()
#define lp(i, n) for (ll i = 0; i < n; i++)
#define lpp(i, n) for (ll i = n - 1; i >= 0; i--)
#define rep(i, a, b, n) for (int i = a; i < b; i += n)
#define repp(i, a, b, n) for (ll i = b - 1; i >= a; i -= n)

#define f first
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) \
    ul t;     \
    cin >> t; \
    while (t--)
#define ct(t) cout << t << endl
#define inarr(n) \
    int n;       \
    cin >> n;    \
    vll v(n, 0); \
    lp(i, n) cin >> v[i]
#define ouarr(n) lp(i, n) cout << v[i] << " ";
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);

int main()
{
    fast
        tc(t)
    {
        int n;
        cin >> n;
        int a[n];

        rep(i, 0, n, 1) cin >> a[i];

        int ar[n + 1];
        ar[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            ar[i] = max(ar[i + 1], a[i]);
        }
        rep(i, 0, n, 1) cout << ar[i] << " ";

        set<int> s;
        int ans = 0;
        s.insert(INT_MIN);
        for (int i=0;i<n-1;i++){
            if (ar[i+1] > a[i])
            {
                ans = max(ans, getLowValue(lowValue, 
                                       arr[i]) 
                               + arr[i] + maxSuffArr[i + 1]); 
    
                // Insert arr[i] in set<> for further 
                // processing 
                lowValue.insert(arr[i]);
            }
        }
    }

    return 0;
}