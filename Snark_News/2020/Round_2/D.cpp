#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(_) for (int __ = 0; __ < (_); ++__)
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));

ll n, m, ans;
vector<ll> a, b;
vector<int> adj[N], adj2[N];
bool vis[N];
ll sub[N];
ll nod, val;
int st[N], low[N], t;

map<pii, int> bad, on;

void dfs(int x, int p)
{
        st[x] = low[x] = ++t;
        int skp = 1;
        for (auto u : adj[x])
        {
                if (u == p && skp)
                {
                       // skp = 0;
                        continue;
                }
                if (st[u])
                {
                        low[x] = min(low[x], st[u]);
                }
                else
                {
                        dfs(u, x);
                        low[x] = min(low[x], low[u]);
                }
                if (low[u] > st[x])
                {
                        bad[{u, x}] = bad[{x, u}] = 1;
                }
        }
}

void dfs1(int x)
{
        st[x] = nod;
        b[nod] += a[x];
        for (auto u : adj[x])
        {
                if (st[u] || bad[{x, u}])
                        continue;
                dfs1(u);
        }
}

ll dfz(int x, int p)
{
        sub[x] = b[x];
        vector<ll> v;
        for (auto u : adj2[x])
        {
                if (u == p)
                        continue;
                dfz(u, x);
                sub[x] = max(sub[x], b[x] + sub[u]);
                v.push_back(sub[u]);
        }
        if (v.size() > 1)
        {
                sort(v.begin(), v.end(), greater<ll>());
                ans = max(ans, v[0] + v[1] + b[x]);
        }
        return sub[x];
}

ll dfs2(int x, int p, ll d = 0)
{
        ll ret = sub[x] + d;
        ans = max(ans, ret);
        for (auto u : adj2[x])
        {
                if (u == p)
                        continue;
                ll d2 = b[x];
                for (auto u2 : adj2[x])
                {
                        if (u2 == p || u == u2)
                                continue;
                        d2 = max(d2, sub[u2] + b[x]);
                }
                ret = max(ret, dfs2(u, x, max(d, d2)));
        }
        return ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        a.resize(n + 1);
        b.resize(n + 1);
        for (int i = 1; i <= n; ++i)
                cin >> a[i];
        vii ed;
        for (int i = 0; i < m; ++i)
        {
                int u, v;
                cin >> u >> v;
                ed.push_back({u, v});
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        dfs(1, 1);
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; ++i)
        {
                if (st[i])
                        continue;
                nod++;
                dfs1(i);
        }
        for (auto u : ed)
        {
                if (bad[u] && !on[{st[u.first], st[u.second]}])
                {
                        adj2[st[u.first]].push_back(st[u.second]);
                        adj2[st[u.second]].push_back(st[u.first]);
                        on[{st[u.first], st[u.second]}] = on[{st[u.second], st[u.first]}] = 1;
                }
        }
        dfz(1, 1);
        dfs2(1, 1, 0);
        cout << max(ans, dfs2(1, 1, 0));
        return 0;
}
