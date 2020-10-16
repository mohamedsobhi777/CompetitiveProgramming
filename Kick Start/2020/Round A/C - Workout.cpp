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

int n, k;
int a[N];

bool check(int x)
{
        int ret = 0;
        for (int i = 1; i < n; ++i)
        {
                int diff = a[i] - a[i - 1];
                ret += diff / x - !(diff % x);
        }
        return ret <= k;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        int t;
        cin >> t;
        for (int tc = 1; tc <= t; ++tc)
        {
                cin >> n >> k;
                for (int i = 0; i < n; ++i)
                        cin >> a[i];
                int lo = 1, hi = 1e9;
                int ans = 1e9;
                while (lo <= hi)
                {
                        int mid = (lo + hi) >> 1;
                        if (check(mid))
                        {
                                hi = mid - 1;
                                ans = mid;
                        }
                        else
                                lo = mid + 1;
                }
                cout << "Case #" << tc << ": " << ans << "\n";
        }
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