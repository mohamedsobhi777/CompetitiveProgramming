#include <bits/stdc++.h>

using namespace std;

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

int n;
int st[N], en[N];
int a[N];
int bit[N];

void add(int x, int d)
{
        for (; x < N; x += x & -x)
                bit[x] += d;
}

int upto(int x)
{
        int ret = 0;
        for (; x; x -= x & -x)
                ret += bit[x];
        return ret;
}

int get(int x, int y)
{
        return upto(y) - upto(x - 1);
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen("circlecross.in", "r", stdin);
        freopen("circlecross.out", "w", stdout);
        //        freopen("in.in", "r", stdin);
        cin >> n;
        for (int i = 0; i < 2 * n; ++i)
        {
                cin >> a[i];
                (st[a[i]] ? en[a[i]] : st[a[i]]) = i + 1;
        }
        ll ans = 0;
        for (int i = 0; i < n * 2; ++i)
        {
                if (i + 1 == st[a[i]])
                        ans += get(st[a[i]], en[a[i]]),
                            add(en[a[i]], 1);
                else
                        add(en[a[i]], -1);
        }
        cout << ans;
        return 0;
}
