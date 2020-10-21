#include <bits/stdc++.h>

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

#define I inline void
#define S struct
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 10000 + 7, mod = 1e6 + 7;
const ll inf = 2e18;

// How interesting!

int n;
int a[N], b[N];
int Max;
int c[N][N];

int mul(int x, int y) { return 1ll * x * y % mod; }
int add(int x, int y) { return (x + y) >= mod ? x + y - mod : x + y; }

int dp[N], ndp[N];

void dodp()
{

        for (int i = 0; i <= n; ++i)
        {
                ndp[i] = add(dp[i + 1], mul(i, dp[i]));
        }
        for (int i = 0; i <= n; ++i)
        {
                dp[i] = ndp[i];
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);

        cin >> n;
        for (int i = 0; i < n; ++i)
                dp[i] = 1;
        for (int i = 0; i < n; ++i)
        {
                cin >> a[i];
                if (i)
                        b[i] = max(b[i - 1], a[i]);
                else
                        b[i] = a[i];
        }
        int ans = 0;
        for (int i = n - 1; ~i; --i)
        {
                int x = a[i];
                for (int j = 1; j < x; ++j)
                {
                        int k = (i ? b[i - 1] : 0);
                        ans = add(ans, dp[max(j, i ? b[i - 1] : 0)]);
                }
                Max = max(Max, x);
                dodp();
        }
        cout << add(ans, 1);
        return 0;
}

/*
        - bounds sir (segtree = 4N, eulerTour = 2N, ...)
        - a variable defined twice?
        - will overflow?
        - is it a good complexity?
        - don't mess up indices (0-indexed vs 1-indexed)
        - reset everything between testcases. 
*/