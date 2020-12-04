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

const int N = 1e3 + 7;
const ll mod = 998244353;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));

int n;
string s;
int zero = 2000;
pii dp[N][N];

pii operator+(pii lhs, pii rhs)
{
        return {lhs.first + rhs.first, (lhs.second + rhs.second) % mod};
}

pii getm(int i, int v)
{
        if (~dp[i][v].first)
                return dp[i][v];
        if (v < zero)
                return make_pair(1e9, 0);
        if (i == n)
                return v == zero ? make_pair(0, 1) : make_pair((int)1e9, 0);

        pii c1 = getm(i + 1, v) + make_pair(1, 0);
        pii c2 = getm(i + 1, v + (s[i] == 'm' ? 1 : -1));
        int Min = min(c1.first, c2.first);
        pii ret = {Min, 0};
        if (c1.first == Min)
                ret.second += c1.second;
        if (c2.first == Min)
                ret.second += c2.second;
        ret.second %= mod;
        return dp[i][v] = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                        dp[i][j] = {-1, 0};

        cin >> s;
        n = (int)s.size();
        pii mn = getm(0, zero);
        cout << mn.second;
        return 0;
}
