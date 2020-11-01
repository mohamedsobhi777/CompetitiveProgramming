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

const int N = 500 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n, m;
int dp[N][N];

int solve(int x, int y)
{
        if (x == y)
                return 0;
        if (~dp[x][y])
                return dp[x][y];
        int ret = 1e9;
        for (int i = 1; i < x; ++i)
                ret = min(ret, solve(i, y) + solve(x - i, y) + 1);
        for (int i = 1; i < y; ++i)
                ret = min(ret, solve(x, i) + solve(x, y - i) + 1);
        return dp[x][y] = ret;
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        memset(dp, -1, sizeof dp);
        cin >> n >> m;
        cout << solve(n, m);
        return 0;
}