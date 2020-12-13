#include <bits/stdc++.h>

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

using namespace std;

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

const int N = 3e5 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));

int n, m;
int tree[4 * N];

void update(int node, int L, int R, int ix, int val)
{
        if (L == R)
                return void(tree[node] ^= val);
        int mid = (L + R) >> 1;
        if (ix <= mid)
                update(node * 2 + 1, L, mid, ix, val);
        else
                update(node * 2 + 2, mid + 1, R, ix, val);
        tree[node] = (tree[node * 2 + 1] ^ tree[node * 2 + 2]);
}

int query(int node, int L, int R, int l, int r)
{
        if (l > R || r < L)
                return 0;
        if (L >= l && R <= r)
                return tree[node];
        int mid = (L + R) >> 1;
        return query(node * 2 + 1, L, mid, l, r) ^ query(node * 2 + 2, mid + 1, R, l, r);
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
                int x;
                cin >> x;
                update(0, 1, n, i, x);
        }
        while (m--)
        {
                int t, a, b;
                cin >> t >> a >> b;
                if (t == 1)
                        update(0, 1, n, a, b);
                else
                        cout << query(0, 1, n, a, b) << "\n";
        }
        return 0;
}
