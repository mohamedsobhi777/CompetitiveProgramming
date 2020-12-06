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

const int N = 700 + 10;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n, m;
int m1[4] = {1, -1, 0, 0}, m2[4] = {0, 0, 1, -1};
int d1[N][N];
int d2[N][N];
string s[N];
int vX, vY, yX, yY, tX, tY;

inline bool good(int i, int j) { return ~i && ~j && i < n && j < m && s[i][j] != 'I'; }

void bfs01(int stX, int stY)
{
        queue<pii> q;
        q.push({stX, stY});
        forn(i, N) fill(d1[i], d1[i] + N, mod);
        d1[stX][stY] = 0;
        while (sz(q))
        {
                pii t = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                        int nX = t.f + m1[i], nY = t.s + m2[i];
                        if (good(nX, nY) && d1[t.f][t.s] + 1 < d1[nX][nY])
                                d1[nX][nY] = 1 + d1[t.f][t.s],
                                q.push({nX, nY});
                }
        }
}

void precompute()
{
        forn(i, N) fill(d2[i], d2[i] + N, mod);
        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j < m; ++j)
                {
                        if (d1[i][j] <= mod)
                        {
                                for (int ii = i ; ii < n && good(ii, j); ++ii)
                                        d2[ii][j] = min(d2[ii][j], d1[i][j]);
                                for (int ii = i - 1; ~ii && good(ii, j); --ii)
                                        d2[ii][j] = min(d2[ii][j], d1[i][j]);

                                for (int jj = j + 1; jj < m && good(i, jj); ++jj)
                                        d2[i][jj] = min(d2[i][jj], d1[i][j]);
                                for (int jj = j - 1; ~jj && good(i, jj); --jj)
                                        d2[i][jj] = min(d2[i][jj], d1[i][j]);
                        }
                }
        }
}

void bfs10(int stX, int stY)
{
        queue<pii> q;
        q.push({stX, stY});
        forn(i, N) fill(d1[i], d1[i] + N, mod);
        d1[stX][stY] = 0;
        while (sz(q))
        {
                pii t = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                        int nX = t.f + m1[i], nY = t.s + m2[i];
                        if (good(nX, nY) && d1[t.f][t.s] + 1 < d2[nX][nY] && d1[t.f][t.s] + 1 < d1[nX][nY])
                                d1[nX][nY] = 1 + d1[t.f][t.s],
                                q.push({nX, nY});
                }
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
                cin >> s[i];
                for (int j = 0; j < m; ++j)
                {
                        if (s[i][j] == 'V')
                                vX = i, vY = j;
                        if (s[i][j] == 'Y')
                                yX = i, yY = j;
                        if (s[i][j] == 'T')
                                tX = i, tY = j;
                }
        }
        bfs01(vX, vY);
        precompute();
        bfs10(yX, yY);
        cout << (d1[tX][tY] < mod ? "YES" : "NO");
        return 0;
}