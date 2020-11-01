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

const int N = 1e6 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n, c;
ll dp[N];

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        fill(dp + 1, dp + N, inf);
        cin >> n >> c;
        for (int i = 0; i < n; ++i)
        {
                int x;
                cin >> x;
                for (int j = x; j <= 1e6; ++j)
                        dp[j] = min(dp[j], dp[j - x] + 1);
        }
        cout << (dp[c] == inf ? -1 : dp[c]);
        return 0;
}