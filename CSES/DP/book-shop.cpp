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

int n, x;
ll dp[N];
int a[N], b[N];

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> x;
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        for (int i = 0; i < n; ++i)
                cin >> b[i];
        for (int i = 0; i < n; ++i)
        {
                for (int j = x; j >= a[i]; --j)
                {
                        dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
                }
        }
        cout << *max_element(dp, dp + 1 + x);
        return 0;
}