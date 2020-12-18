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
#define vll vector<ll>
#define vii vector<pair<int, int>>
#define vvi vector<vi>
#define vvii vector<vii>
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
#define si set<int>
#define ms multiset<int>
#define qi queue<int>
#define pq prioriry_queue<int>
#define mi map<int, int>
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)

using ll = long long;
using ld = long double;

const int N = 1e5 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n;
vi a, b;
bool vis[N];

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
//        freopen("in.in", "r", stdin);
        freopen("cardgame.in", "r", stdin);
        freopen("cardgame.out", "w", stdout);
        cin >> n;
        a.resize(n / 2);
        b.resize(n / 2);
        for (auto &u : a)
                cin >> u;
        for (auto &u : b)
                cin >> u;

        sort(all(a));
        sort(all(b));
        for (auto u : a)
                vis[u] = 1;
        for (auto u : b)
                vis[u] = 1;
        vi A, B;

        for (int i = 1; i <= n * 2; ++i)
        {
                if (!vis[i])
                {
                        if (sz(A) < n / 2)
                                A.pb(i);
                        else
                                B.pb(i);
                }
        }

        int ans1 = 0, ans2 = 0;

        int lo = 1, hi = n / 2;
        while (lo <= hi)
        {
                int mid = (lo + hi) >> 1;
                bool ok = 1;
                for (int i = 0; i < mid; ++i)
                {
                        if (a[i] > B[n / 2 - mid + i])
                                ok = 0;
                }
                if (ok)
                {
                        ans1 = mid;
                        lo = mid + 1;
                }
                else
                        hi = mid - 1;
        }
        lo = 1, hi = n / 2;
        while (lo <= hi)
        {
                int mid = (lo + hi) >> 1;
                bool ok = 1;
                for (int i = 0; i < mid; ++i)
                {
                        if (b[n / 2 - mid + i] < A[i])
                                ok = 0;
                }
                if (ok)
                {
                        ans2 = mid;
                        lo = mid + 1;
                }
                else
                        hi = mid - 1;
        }
        cout << ans1 + ans2;
        return 0;
}
