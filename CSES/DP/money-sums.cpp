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
bitset<1000000> bs;

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);
        cin >> n;
        bs[0] = 1;
        for (int i = 0; i < n; ++i)
        {
                int x;
                cin >> x;
                bs |= (bs << x);
        }
        cout << bs.count() - 1 << "\n";
        for (int i = 1; i < 1e6; ++i)
        {
                if (bs[i])
                        cout << i << " ";
        }
        return 0;
}