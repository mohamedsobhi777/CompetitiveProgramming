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

int n;
ll dp[N];

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        fill(dp + 1, dp + N, inf);
        for (int i = 1; i <= n; ++i)
        {
                int ii = i;
                while (ii)
                {
                        dp[i] = min(dp[i], dp[i - ii % 10] + 1);
                        ii /= 10;
                }
        }
        cout << dp[n];
        return 0;
}