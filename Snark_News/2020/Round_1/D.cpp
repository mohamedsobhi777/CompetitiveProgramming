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

const int N = 2e5 + 7, mod = 1e9 + 7;
const ll inf = 2e18;

// How interesting!

int n, m, k;
int dp[2][11][(1 << 19)];

ll faspow(int x, int y)
{
        if (!y)
                return 1ll;
        ll ret = faspow(x, y / 2);
        ret = 1ll * ret * ret % k;
        if (y & 1)
                ret = 1ll * ret * x % k;
        return ret;
}

int solve(int i, int ls, int msk)
{
        if (i == n)
                return 1;
        int ret = 0;
        if (~dp[i][ls][msk])
                return dp[i][ls][msk];
        for (int j = 1; j <= m; ++j)
        {
                int nm = 0;
                int nmask = 0;
                if (ls)
                {
                        nm = j - ls + 9;
                        if (msk & (1 << nm))
                                continue;
                        nmask = (msk | (1 << nm));
                }
                ret = (ret + solve(i + 1, j, nmask)) % k;
        }
        return dp[i][ls][msk] = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen("in.in", "r", stdin);
        memset(dp, -1, sizeof dp);
        cin >> n >> m >> k;
        if (n > 20)
                return cout << faspow(m,n), 0;
        for (int i = 1; i <= m; ++i)
        {
                dp[i][0] = 1;
        }
        for (int i = 1; i < n; ++i)
        {
                for (int j = 1; j <= m; ++j)
                {

                        for (int r = 0; r < (1 << 19); ++r)
                        {
                                int ndel = ()
                        }
                }
        }
        cout << ((faspow(m, n) - solve(0, 0, 0) + k) % k + k) % k;
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