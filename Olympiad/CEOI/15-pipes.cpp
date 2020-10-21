#include <bits/stdc++.h>

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
const ll inf = 2e18;

// How interesting!

int n, m, t;
vector<int> adj[N];
int low[N], tim[N];

void dfs(int x, int p)
{
        low[x] = tim[x] = ++t;
        int ban = 0;
        for (auto u : adj[x])
        {
                if (u == p && !ban++)
                        continue;
                if (low[u])
                {
                        low[x] = min(low[x], tim[u]);
                }
                else
                {
                        dfs(u, x);
                        if (low[u] > tim[x])
                        {
                                cout << x << " " << u << "\n";
                        }
                        low[x] = min(low[x], low[u]);
                }
        }
}

struct dsu
{
        int fat[N];
        dsu()
        {
                for (int i = 0; i < N; ++i)
                        fat[i] = i;
        }
        int find(int x) { return fat[x] = (x == fat[x] ? x : find(fat[x])); }

        void link(int u, int v)
        {
                u = find(u);
                v = find(v);
                if (u != v)
                {
                        fat[u] = v;
                }
        }

        bool same(int u, int v)
        {
                return find(u) == find(v);
        }
} d1, d2;
int u, v;

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
                cin >> u >> v;
                if (!d1.same(u, v))
                {
                        d1.link(u, v);
                }
                else if (!d2.same(u, v))
                {
                        d2.link(u, v);
                }
                else
                        continue;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
        {
                if (!tim[i])
                        dfs(i, i);
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