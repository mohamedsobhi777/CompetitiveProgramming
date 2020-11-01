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

const int N = 2e5 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n;

vector<pair<pii, int>> v;
ll dp[N];
vector<pair<int, ll>> dps;

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
                int x, y, z;
                cin >> x >> y >> z;
                v.push_back({{y, x}, z});
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; ++i)
        {
                int x = v[i].first.second;
                int y = v[i].first.first;
                int z = v[i].second;
                dp[i] = z;
                int j = lower_bound(dps.begin(), dps.end(), make_pair(x, -1ll)) - dps.begin();
                if (j--)
                        dp[i] = max(dp[i], dps[j].second + z);
                dps.push_back({y, max(dp[i], (i ? dps.back().second : 0))});
        }
        cout << *max_element(dp, dp + n);
        return 0;
}