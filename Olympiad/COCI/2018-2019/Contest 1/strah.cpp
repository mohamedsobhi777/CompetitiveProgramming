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

int n, m;
int v[N];
ll ans;
int R[N];

void solve()
{
        stack<int> stk;
        for (int i = 0; i < m; ++i)
        {
                while (stk.size() && v[stk.top()] > v[i])
                {
                        R[stk.top()] = i - 1;
                        stk.pop();
                }
                stk.push(i);
        }
        while (stk.size())
        {
                R[stk.top()] = m - 1;
                stk.pop();
        }
        for (int i = 0; i < m; ++i)
        {
                int j1 = i, j2 = i;
                while (j1 && v[j1 - 1] > v[i])
                        --j1;
                j2 = R[i];
                ll contr = 0;
                ll l1 = i - j1, l2 = j2 - i;
                ll cof = 1ll * v[i] * (v[i] + 1) / 2ll;
                ll mult = (l1 + 1) * (l2 + 1) * (l2 + 2) / 2ll;
                mult += (l2 + 1) * (l1 + 1) * (l1) / 2ll;
                ans += cof * mult * 1ll ; 
        }
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j < m; ++j)
                {
                        char c;
                        cin >> c;
                        if (c == '.')
                                v[j]++;
                        else
                                v[j] = 0;
                }
                solve();
        }
        cout << ans;
        return 0;
}