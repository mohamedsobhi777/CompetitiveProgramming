#include <bits/stdc++.h>

#define I inline void
#define S struct
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 500 + 7, mod = 1e9 + 7;
const ll inf = 2e18;

// How interesting!

int n, m, k;
string s[N], t;
int mn[N][N][27];

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        //freopen("in.in", "r", stdin);
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
                cin >> s[i];
        cin >> t;
        for (int i = 0; i < N; ++i)
        {
                for (int j = 0; j < N; ++j)
                {
                        for (int c = 0; c < 27; ++c)
                                mn[i][j][c] = 1e5;
                }
        }
        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j < m; ++j)
                {
                        for (int c = 0; c < n; ++c)
                        {
                                int z = s[c][j] - 'a';
                                mn[i][j][z] = min(mn[i][j][z], (c <= i ? i - c : n - c + i));
                        }
                }
        }
        int ans = 1e5;

        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j <= m - k; ++j)
                {
                        int ret = 0 ; 
                        for (int r = 0; r < k; ++r)
                                ret += (mn[i][j + r][t[r] - 'a']);
                        ans = min(ans, ret);
                }
        }
        cout << (ans >= 1e5 ? -1 : ans);
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