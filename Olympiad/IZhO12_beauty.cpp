/*
        Problem : IZhO12_beauty
        Link : https://oj.uz/problem/view/IZhO12_beauty
        handle : mohamedsobhi777

        hint1 : N is very small, 2^(N) is doable

        Solution : 
                we represent the array as a graph, with an edge between 2 indices i and j, if (i and j) can be put adjacent
                from each starting node 0 to n-1, we count the number of paths that visits each node exactly once(doesn't form any cycles) 
                so we keep a mask of the nodes we visited to make sure we don't visit the same node twice, and calculate the number of paths with dp

        O(N * 2 ^ N)

*/


#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
int r2[N], r3[N];
int a[N];
vector<int> p;
long long dp[N][(1 << N)];

int solve1(int x, int base)
{
        int ret = 0;
        while (x)
        {
                ret += (x % base == 1);
                x /= base;
        }

        return ret;
}
vector<int> adj[N];

long long solve(int x, int mask)
{
        if (dp[x][mask] != -1)
                return dp[x][mask];
        if (mask == (1 << n) - 1)
        {
                return 1LL;
        }
        long long ret = 0;
        for (auto u : adj[x])
        {
                if (mask & (1 << u))
                        continue;
                ret += solve(u, (mask | (1 << u)));
        }
        return dp[x][mask] = ret;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
                r2[i] = solve1(a[i], 2);
                r3[i] = solve1(a[i], 3);
        }
        for (int i = 0; i < n; i++)
        {
                p.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
                for (int j = i + 1; j < n; j++)
                {
                        if (r2[i] == r2[j] || r3[i] == r3[j])
                        {
                                adj[i].push_back(j);
                                adj[j].push_back(i);
                        }
                }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
                ans += solve(i, (1 << i));
        }
        cout << ans;
        return 0;
}
