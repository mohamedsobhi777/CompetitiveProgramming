#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(_) for (int __ = 0; __ < (_); ++__)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define f first
#define s second
#define sz(_) ((int)_.size())
#define all(_) _.begin(), _.end()
#define uni(_) unique(_)
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using ld = long double;

const int N = 1e5 + 7000;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n;

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        vi a(n);
        for (auto &u : a)
                cin >> u;
        sort(all(a));
        ll ans = 0;
        for (int i = 0; i < n; ++i)
                ans += partition_point(all(a), [&](int x) { return 10 * a[i] >= 9 * x; }) - a.begin() - i - 1;
        cout << ans;
        return 0;
}
