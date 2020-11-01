#include <bits/stdc++.h>

/*
#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")*/

#define I inline void
#define S struct
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n, m;
int a[N];
ll dp[N];
ll dp2[N];

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
                cin >> a[i];

        for (int i = 1; i <= n; ++i)
        {
                if (!a[i])
                {
                        for (int j = 1; j <= m; ++j)
                        {
                                dp2[j] = (dp[j - 1] + dp[j] + dp[j + 1]) % mod;
                                if (i == 1)
                                        dp2[j] = 1;
                        }
                        for (int j = 1; j <= m; ++j)
                        {
                                dp[j] = dp2[j];
                        }
                }
                else
                {
                        ll x = (dp[a[i] - 1] + dp[a[i]] + dp[a[i] + 1]) % mod;
                        if (i == 1)
                                x = 1;
                        memset(dp, 0, sizeof dp);
                        dp[a[i]] = x;
                }
        }
        cout << accumulate(dp + 1, dp + m + 1, 0ll) % mod;
        return 0;
}