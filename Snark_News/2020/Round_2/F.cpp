#include <bits/stdc++.h>

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(_) for (int __ = 0; __ < (_); ++__)
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6 + 1000 + 7;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

auto ra = [] {char *p = new char ; delete p ; return ll(p) ; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (ra() | 1));

int n, m, add;
bool p[N];
int a[N], b[N], c[N];
vector<int> prm;

void sieve()
{
        for (int i = 2; i < N; ++i)
        {
                if (p[i])
                        continue;
                prm.push_back(i);
                for (int j = i + i; j < N; j += i)
                        p[j] = 1;
        }
}

void no()
{
        cout << "NO";
        exit(0);
}

void yes()
{
        cout << "YES\n";
        int bal = (m - add) / 2;
        for (int i = 0; i < n; ++i)
        {
                int neg = 0, pos = 0;
                (a[i] < b[i]) ? pos += b[i] - a[i] : neg += a[i] - b[i];
                cout << neg + bal << " " << pos + bal << "\n";
                bal = 0;
        }
        exit(0);
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sieve();
        //freopen("in.in", "r", stdin);

        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
                cin >> a[i];
                int j = lower_bound(prm.begin(), prm.end(), a[i]) - prm.begin();
                int mn = 1e9;

                for (int k = j - 1; k <= j + 2; ++k)
                {
                        if (k >= 0 && k < (int)prm.size())
                        {
                                if (abs(a[i] - prm[k]) < mn)
                                {
                                        mn = min(mn, abs(a[i] - prm[k]));
                                        b[i] = prm[k];
                                }
                        }
                }
                add += mn;
        }
        if (add > m)
                no();
        if (m % 2 == add % 2)
                yes();
        else
        {
                int ind = -1;
                int Min = 1e9;
                for (int i = 0; i < n; ++i)
                {
                        if (a[i] % 2)
                        {
                                if (b[i] % 2)
                                {
                                        c[i] = 2;
                                }
                                else
                                {
                                        c[i] = 1e9;
                                }
                        }
                        else
                        {
                                if (b[i] % 2)
                                {
                                        c[i] = 2;
                                }
                                else
                                {
                                        c[i] = 3;
                                }
                        }

                        if (abs(b[i] - c[i]) < Min)
                        {
                                ind = i;
                                Min = abs(c[i] - b[i]);
                        }
                }
                if (~ind)
                {
                        add -= abs(a[ind] - b[ind]);
                        add += abs(a[ind] - c[ind]);
                        b[ind] = c[ind];

                        if (add > m)
                                no();
                        else
                                yes();
                }
                else
                        no();
        }
        return 0;
}
