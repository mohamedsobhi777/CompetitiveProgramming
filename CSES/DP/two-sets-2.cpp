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

const int N = 3e5 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n;
ll dp[N];

ll faspow(ll x, ll y)
{
        if (!y)
                return 1ll;
        ll ret = faspow(x, y / 2);
        ret = 1ll * ret * ret % mod;
        if (y & 1)
                ret = 1ll * ret * x % mod;
        return ret;
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);

        cin >> n;
        int k = n * (n + 1) / 2;
        dp[0] = 1ll;
        for (int i = 1; i <= n; ++i)
        {
                for (int j = k; j >= i; --j)
                {
                        dp[j] = (dp[j] + dp[j - i]) % mod;
                }
        }
        if (k % 2 == 0)
                cout << dp[k / 2] * faspow(2, mod - 2) % mod;
        else
                cout << 0;
        return 0;
}