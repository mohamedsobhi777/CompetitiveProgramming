
//stupid solution 1
#include <bits/stdc++.h>

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(_) for (int __ = 0; __ < (_); ++__)
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using ll = long long;
using ld = long double;

const int N = 500 + 7;
const int NN = N * N;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));

int n;
int ret[NN];
vi a;
bitset<NN> pref[N], suff[N];

void eval(bitset<NN> &ret, int l, int r, int d)
{
        if (d == 1)
                for (int i = l; i <= r; ++i)
                        ret |= (ret << a[i]);
        else
                for (int i = r; i >= l; --i)
                        ret |= (ret << a[i]);
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);

        cin >> n;
        vi ans;
        a.resize(n);
        int sum = 0;
        for (auto &u : a)
                cin >> u;
        sum = accumulate(a.begin(), a.end(), 0);

        bitset<NN> ini, ini2;
        ini[0] = ini2[0] = 1;
        for (int i = 0; i < n; ++i)
        {
                ini |= (ini << a[i]);
                ini2 |= (ini2 << a[n - 1 - i]);
                suff[n - 1 - i] = ini2;
                pref[i] = ini;
        }

        if (sum & 1 || !pref[n - 1][sum / 2])
                return cout << 0, 0;

        for (int i = 0; i < n; ++i)
        {
                int sm = sum - a[i];
                int lhs = i, rhs = n - 1 - i;
                bitset<NN> bts;
                if (lhs > rhs)
                {
                        if (i)
                                bts = pref[i - 1];
                        eval(bts, i + 1, n - 1, 1);
                }
                else
                {
                        if (i + 1 < n)
                                bts = suff[i + 1];
                        eval(bts, 0, i - 1, -1);
                }
                for (int j = 0; j <= sm; ++j)
                {
                        if (bts[j])
                        {
                                if (2 * j != sm)
                                        ret[abs(j - (sm - j))]++;
                        }
                }
        }

        int sz = 0;
        for (int u = 1; u < NN; ++u)
        {
                if (ret[u] == 2 * n)
                        ans.push_back(u);
        }
        cout << (int)ans.size() << "\n";
        for (auto u : ans)
                cout << u << " ";
        return 0;
}
