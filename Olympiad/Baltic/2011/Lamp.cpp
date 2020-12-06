#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(_) for (int __ = 0; __ < (_); ++__)
#define forn(i, _) for (int i = 0; i < _; ++i)
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

const int N = 3e5 + 7000;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n, m;
int d[N];
string s[N];
vector<pii> adj[N];

void edge(int u, int v, int w)
{
        adj[u].pb({v, w});
        adj[v].pb({u, w});
}

inline int id(int x, int y) { return x * (m + 1) + y; }

int bfs01(int s, int t)
{
        fill(d + 1, d + N, 1e9);
        deque<int> q;
        q.push_back(s);
        while (sz(q))
        {
                int x = q.back();
                q.pop_back();
                for (auto u : adj[x])
                {
                        if (d[x] + u.s < d[u.f])
                        {
                                d[u.f] = d[x] + u.s;
                                if (u.s)
                                        q.push_front(u.f);
                                else
                                        q.pb(u.f);
                        }
                }
        }
        return d[t];
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        forn(i, n)
        {
                string x;
                cin >> x;
                forn(j, m)
                {
                        edge(id(i, j), id(i + 1, j + 1), (x[j] == '/'));
                        edge(id(i, j + 1), id(i + 1, j), (x[j] == '\\'));
                }
        }
        int ans = bfs01(0, ++n * ++m - 1);
        if (ans >= 1e7)
                cout << "NO SOLUTION";
        else
                cout << ans;
        return 0;
}
