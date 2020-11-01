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

const int N = 1e3 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n;
string s[N];
int dp[N][N];

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        for (int i = 0; i < n; ++i)
                cin >> s[i];
        dp[0][0] = (s[0][0] == '.');
        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j < n; ++j)
                {
                        if (s[i][j] == '*')
                                continue;
                        if (i)
                                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                        if (j)
                                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                }
        }
        cout << dp[n - 1][n - 1];
        return 0;
}