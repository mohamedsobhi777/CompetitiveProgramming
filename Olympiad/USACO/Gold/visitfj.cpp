#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define sz(_) ((int)_.size())
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)

using ll = long long;
const int N = 1e2 + 7;

int n, t;
int a[N][N];
ll d[3][N * N];
vector<pair<int, ll>> adj[N * N];

inline bool good(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }
inline int id(int x, int y) { return x * n + y; }
inline void edge(int u, int v, ll w)
{
        adj[u].pb({v, w});
        adj[v].pb({u, w});
}

void dijkstra(int st)
{
        inc(i, 0, 2) fill(d[i], d[i] + N * N, 1e15);
        d[0][st] = 0;
        priority_queue<pair<ll, pair<int, int>>> q;
        q.push({0, {st, 0}});
        while (sz(q))
        {
                ll dst = -q.top().f;
                pii node = q.top().s;
                q.pop();
                for (auto u : adj[node.f])
                {
                        int nx = u.f / n, ny = u.f % n;
                        ll add = (node.s == 2 ? a[nx][ny] : 0);
                        if (dst + u.s + add < d[(node.s + 1) % 3][u.f])
                        {
                                d[(node.s + 1) % 3][u.f] = dst + u.s + add;
                                q.push({-d[(node.s + 1) % 3][u.f], {u.f, (node.s + 1) % 3}});
                        }
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen("visitfj.in", "r", stdin);
        freopen("visitfj.out", "w", stdout);
        cin >> n >> t;
        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j < n; ++j)
                {
                        cin >> a[i][j];
                        int mid = id(i, j);
                        if (i)
                                edge(id(i - 1, j), mid, t);

                        if (j)
                                edge(id(i, j - 1), mid, t);
                }
        }
        dijkstra(0);
        int mid = id(n - 1, n - 1);
        cout << min(d[0][mid], min(d[1][mid], d[2][mid]));
        return 0;
}
/*
......*......
.....*.*.....
....*.*.*....
...*.*^*.*...
....*.*.*....
.....*.*.....
......*......
*/