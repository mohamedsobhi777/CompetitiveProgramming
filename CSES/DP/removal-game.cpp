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

const int N = 5e3 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n;
int a[N];

ll dp[N][N][2];

ll solve(int l, int r, int t)
{
        if (l > r)
                return 0;
        if (~dp[l][r][t])
                return dp[l][r][t];
        if (t == 0)
                return dp[l][r][t] = max(solve(l + 1, r, !t) + a[l], solve(l, r - 1, !t) + a[r]);
        return dp[l][r][t] = min(solve(l + 1, r, !t), solve(l, r - 1, !t));
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        memset(dp, -1 , sizeof dp) ; 
        cin >> n;
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        cout << solve(0, n - 1, 0);
        return 0;
}