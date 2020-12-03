#include <bits/stdc++.h>

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

#define I inline void
#define S struct
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 7, mod = 1e9 + 7;
const ll inf = 2e18;

// How interesting!

int n;
vector<pair<double, double>> v;

bool check(pair<double, double> p1, pair<double, double> p2)
{
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i)
        {
                double e1 = hypot(p1.first - v[i].first, p1.second - v[i].second);
                double e2 = hypot(p2.first - v[i].first, p2.second - v[i].second);
                if (e1 == e2)
                        a++;
                else if (e1 > e2)
                        b++;
                else
                        c++;
        }
        //  cout << a << " " << b << " " << c << "\n";
        if (n & 1)
                return b == c && a == 1;
        return b == c;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
                int x, y;
                cin >> x >> y;
                v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        double X = v[n / 2].first, Y = v[n / 2].second;

        double xa = X + 1, ya = Y - (1e12);
        double xb = X - 1, yb = Y + (1e12);
        if (n % 2 == 0)
                yb -= 1.0;
        double dx = xa - xb;
        double dy = ya - yb;

        pair<double, double> ans1 = {xa - dy, ya + dx};
        pair<double, double> ans2 = {xa + dy, ya - dx};

        cout << fixed << setprecision(0) << ans1.first << " " << ans1.second << "\n";
        cout << fixed << setprecision(0) << ans2.first << " " << ans2.second << "\n";

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