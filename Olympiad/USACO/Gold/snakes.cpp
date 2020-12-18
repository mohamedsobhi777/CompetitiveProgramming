#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

const int N = 400 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n, k;
ll dp[N][N];
vll a;

ll solve(int i, int r)
{
        if (r < 0)
                return 2e10;
        if (i == n)
                return 0;
        if (~dp[i][r])
                return dp[i][r];
        ll ret = 2e10;
        ll sum = 0, Max = 0;
        for (int j = i; j < n; ++j)
        {
                sum += a[j];
                Max = max(Max, a[j]);
                ret = min(ret, solve(j + 1, r - 1) + (j - i + 1) * Max - sum);
        }
        return dp[i][r] = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        memset(dp, -1, sizeof dp);
        freopen("snakes.in", "r", stdin);
        freopen("snakes.out", "w", stdout);
      //  freopen("in.in", "r", stdin);
        cin >> n >> k;
        a.resize(n);
        for (auto &u : a)
                cin >> u;
        cout << solve(0, k + 1);
        return 0;
}
