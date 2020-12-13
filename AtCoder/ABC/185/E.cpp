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

const int N = 1e3 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n, m;
vi a, b;
int dp[N][N];

int solve(int i, int j)
{
        if (i == n || j == m)
                return n + m - i - j;
        if (~dp[i][j])
                return dp[i][j];
        int ret = 1e9;
        ret = min(ret, solve(i + 1, j + 1) + !(a[i] == b[j]));
        ret = min(ret, min(solve(i + 1, j), solve(i, j + 1)) + 1);
        return dp[i][j] = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        memset(dp, -1, sizeof dp);
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        for (auto &u : a)
                cin >> u;
        for (auto &u : b)
                cin >> u;
        cout << solve(0, 0);
        return 0;
}
