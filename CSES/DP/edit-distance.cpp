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

int n, m;
string s, t;
int dp[N][N];

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> s >> t;
        n = (int)s.size();
        m = (int)t.size();
        for (int i = 0; i < N; ++i)
                fill(dp[i], dp[i] + N, inf);
        for (int i = n; ~i; --i)
        {
                for (int j = m; ~j; --j)
                {
                        if (i == n && j == m)
                                dp[i][j] = 0;
                        else
                        {
                                if (s[i] == t[j])
                                        dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                                else
                                {
                                        dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + 1);
                                        dp[i][j] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j]) + 1);
                                }
                        }
                }
        }
        cout << dp[0][0];
        return 0;
}