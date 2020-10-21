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

ll n, m;

void make(vector<ll> &v)
{
        vector<ll> ret;
        int sz = (int)v.size();
        for (int i = 0; i < (1 << sz); ++i)
        {
                ll sum = 0;
                for (int j = 0; j < sz; ++j)
                {
                        if (i & (1 << j))
                        {
                                sum += v[j];
                        }
                }
                ret.push_back(sum);
        }
        sort(ret.begin(), ret.end());
        v = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        vector<ll> lhs, rhs;
        for (int i = 0; i < n; ++i)
        {
                ll x;
                cin >> x;
                if (i < n / 2)
                        lhs.push_back(x);
                else
                        rhs.push_back(x);
        }
        make(lhs);
        make(rhs);
        ll ans = 0;
        int j = (int)rhs.size() - 1;
        for (int i = 0; i < (int)lhs.size(); ++i)
        {
                while (j >= 0 && lhs[i] + rhs[j] > m)
                        --j;
                ans += j + 1;
        }
        cout << ans;
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