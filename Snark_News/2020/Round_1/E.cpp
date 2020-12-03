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

const int N = 3e5 + 7, mod = 1e9 + 7;
const ll inf = 2e18;

// How interesting!

int n, k;
vector<int> adj[N];
int st[N], en[N], t;
int hei[N], lcs[N];
int up[N][20], a[N];

void dfs(int x, int p)
{
        st[x] = ++t;
        up[x][0] = p;
        hei[x] = hei[p] + 1;
        for (int i = 1; i < 20; ++i)
                up[x][i] = up[up[x][i - 1]][i - 1];
        for (auto u : adj[x])
        {
                if (u == p)
                        continue;
                dfs(u, x);
        }
        en[x] = ++t;
}

inline bool upper(int u, int v) { return st[u] <= st[v] && en[u] >= en[v]; }

int lca(int u, int v)
{
        if (upper(u, v))
                return u;
        if (upper(v, u))
                return v;
        for (int i = 19; ~i; --i)
                if (!upper(up[u][i], v))
                        u = up[u][i];
        return up[u][0];
}

vector<int> dp[N];

int solve(int i, int j)
{
        if (i == n)
                return j ? 1e9 : 0;
        if (~dp[i][j])
                return dp[i][j];
        int ret = solve(i + 1, j);
        if (j)
                ret = min(ret, solve(i + 1, j - 1) + hei[a[i]]);
        if (i + 1 < n)
                ret = min(ret, solve(i + 2, j - 1) + hei[lcs[i + 1]]);
        return dp[i][j] = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        for (int i = 0; i <= n; ++i)
                dp[i] = vector<int>(k + 1, -1);
        for (int i = 0; i < n - 1; ++i)
        {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        dfs(1, 1);
        for (int i = 1; i < n; ++i)
                lcs[i] = lca(a[i - 1], a[i]);
        cout << solve(0, k);
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