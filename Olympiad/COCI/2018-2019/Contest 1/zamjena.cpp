#include <bits/stdc++.h>

/*
#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")*/

#define I inline void
#define S struct
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 7, mod = 1e9 + 7;
const int inf = N;
// How interesting!

int n;

string s[N], t[N];
int fat[N], val[N];
map<string, int> mp;
int T;

int find(int x)
{
        return fat[x] = (x == fat[x] ? x : find(fat[x]));
}

void link(int u, int v)
{
        u = find(u);
        v = find(v);
        if (u != v)
        {
                if (val[u] && val[v])
                {
                        cout << "NE";
                        exit(0);
                }
                fat[u] = v;
                val[v] += val[u];
                val[u] = 0;
        }
}

int comp(string x)
{
        if (mp[x])
                return mp[x];
        if (x[0] >= '0' && x[0] <= '9')
                val[T + 1] = 1;
        return mp[x] = ++T;
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        for (int i = 0; i < N; ++i)
                fat[i] = i;
        for (int i = 0; i < n; ++i)
                cin >> s[i];
        for (int i = 0; i < n; ++i)
                cin >> t[i];
        bool ok = 1;
        for (int i = 0; i < n; ++i)
        {
                int x = comp(s[i]);
                int y = comp(t[i]);
                link(x, y);
        }
        cout << "DA";
        return 0;
}