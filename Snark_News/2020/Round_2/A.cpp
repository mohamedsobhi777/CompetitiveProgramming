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

const int N = 1e6 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));

int n;
ll a[N];

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
      //  freopen("in.in", "r", stdin);
        cin >> n;
        ll ans = 0;
        ll lhs = 0, rhs = 0;
        for (int i = 0; i < n; ++i)
        {
                cin >> a[i];
                rhs += a[i];
        }
        for (int i = 0; i < n; ++i)
        {
                rhs -= a[i];
                lhs += 1ll * a[i] * a[i];
                ans = max(ans, 1ll * lhs * rhs);
        }
        cout << ans;
        return 0;
}
