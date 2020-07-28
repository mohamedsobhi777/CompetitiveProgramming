/*
        Problem : Baltic 17-Railway
        Link : https://open.kattis.com/problems/railway2
        handle : mohamedsobhi777

        Solution : 

                an edge is used by a minister if it lies sperates the nodes chosen by him into at least two sets, 
                some of them are down the subtree of the deeper node and the others aren't in it.

                in other words, if (u , v) is an edge, such that node v is deeper than u, then to be counted by minister x,
                the subtree rooted at v, should contain some of the nodes choses by x (but not all the nodes)

                to count the number of nodes in the subtree, we create an euler tour of the tree, and define : 
                        st[y] to be the time we enter node y 
                        en[y] to be the time we exit from node y
                
                now we will do some preprocessing on the ministers
                        for each minister x we keep a sorted list lst[x] of the st values of the nodes chosen by x
                        
                an edge (u , v) is chosen by a minister x if some of the values in lst intersect with st[v] and en[v] (inclusive)

                if all lst[i] are in [st[v]... en[v]] then the edge is not used because all the nodes are in its subtree

                        so we can for the edge(u , v) ignore all ministers with  (st[v] <=  lst[0] && lst.back() <= en[v])

                also we need to ignore all ministers with no intersections between their lists and [st[v]... en[v]], 
                we will manipulate that part by representing lst as some segments, that doesn't contain the numbers in the list

                for example if lst = {3 , 5 , 77} 
                        then the segments will be [1 , 2] , [4 , 4] , [6 , 76] , [78, infinity]
                if [st[v]... en[v]] lies entirely in one of those segments then it can't intersect with any of the nodes in the list
                of minister x

                so we need to perform the following operation quickly

                        for some L , R, how many pairs, (l , r) such that (L<=l <=r <= R)
                        for some L , R, how many pairs, (l , r) such that (l<=L <=R <= r)
                if we represent the segments as points we can transform it so some 2d range sum with 2d dynamic segment tree
                but it is not fast enough, and gets TLE, we can solve that problem offline with bit, and sorting
        
        submission with 2d dynamic segment tree (TLE) : 

*/


#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 18);

int n, m, k;
int st[N], en[N];
vector<int> deps[N], ans;
int t = 3, r, r2;
int L[N], R[N] ,er[N];
vector<pair<int, int>> adj[N];
vector<pair<pair<int, int>, int>> eve, eve2;

int an1[N], an2[N];
int bit[N][2];

void add(int x, int idx = 0, int val = 1)
{
        for (; x < N; x += x & -x)
                bit[x][idx] += val;
}
int get(int x, int idx = 0, int val = 1)
{
        int ret = 0;
        for (; x; x -= x & -x)
                ret += bit[x][idx];
        return ret;
}

void solve1()
{
        sort(eve.begin(), eve.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
                if (a.first.first == b.first.first)
                {
                        return a.second < b.second;
                }
                return a.first < b.first;
        });
        vector<int> ends;
        map<int, int> qu;
        map<int, int> frs;
        for (auto u : eve)
        {
                if (u.second == 0)
                        qu[u.first.second] = u.first.first;

                else if (u.second == 1)

                        frs[u.first.second] = u.first.first;

                else if (u.second == 2)
                {
                        ends.push_back(frs[u.first.second]);
                        add((frs[u.first.second]));
                }
                else

                        an1[u.first.second] = get(N - 1) - get(qu[u.first.second] - 1);
        }
}

void solve2()
{
        memset(bit, 0, sizeof bit);
        sort(eve2.begin(), eve2.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
                if (a.first.first == b.first.first)
                {
                        return a.second < b.second;
                }
                return a.first < b.first;
        });
        vector<int> ends;
        map<int, int> qu;
        map<int, int> frs;
        for (auto u : eve2)
        {

                if (u.second == 1)
                        qu[u.first.second] = u.first.first;

                else if (u.second == 0)
                {
                        frs[u.first.second] = u.first.first;
                        add(u.first.first, 1, 1);
                }
                else if (u.second == 3)
                {
                        ends.push_back(frs[u.first.second]);
                        add(frs[u.first.second], 1, -1);
                }
                else
                {
                        an2[u.first.second] = get(qu[u.first.second], 1);
                }
        }
}

void dfz(int x, int p)
{
        st[x] = ++t;
        for (auto u : adj[x])
        {
                if (u.first == p)
                        continue;
                dfz(u.first, x);
        }
        en[x] = ++t;
        return;
}

void dfs0(int x, int p)
{

        for (auto u : adj[x])
        {
                if (u.first == p)
                        continue;
                int cnt = m;
                er[u.second] = u.first;
                eve.push_back({{st[u.first], u.second}, 0});
                eve.push_back({{en[u.first], u.second}, 3});
                eve2.push_back({{st[u.first], u.second}, 1});
                eve2.push_back({{en[u.first], u.second}, 2});
                dfs0(u.first, x);
        }
        return;
}

void dfs(int x, int p)
{

        for (auto u : adj[x])
        {
                if (u.first == p)
                        continue;
                int cnt = m;

                cnt -= an1[u.second];
                cnt -= an2[u.second];

                if (cnt >= k)
                {
                        ans.push_back(u.second + 1);
                }
                dfs(u.first, x);
        }
        return;
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);

        cin >> n >> m >> k;

        for (int i = 0; i < n - 1; i++)
        {
                int u, v;
                cin >> u >> v;
                adj[u].push_back({v, i});
                adj[v].push_back({u, i});
        }

        dfz(1, 1);

        for (int i = 0; i < m; i++)
        {
                int x;
                cin >> x;
                vector<int> vec;
                for (int j = 0; j < x; j++)
                {
                        int t;
                        cin >> t;
                        deps[i].push_back(t);
                        vec.push_back(st[t]);
                }
                sort(vec.begin(), vec.end());
                int l = 1;

                for (auto u : vec)
                {
                        if (u > l && l + 1 <= u - 1)
                        {
                                eve2.push_back({{l + 1, r2}, 0});
                                eve2.push_back({{u - 1, r2}, 3});
                                r2++;
                        }
                        l = u;
                }
                L[i] = vec[0];
                R[i] = vec.back();

                eve.push_back({{L[i], r}, 1});
                eve.push_back({{R[i], r}, 2});

                eve2.push_back({{l + 1, r2}, 0});
                eve2.push_back({{N - 1, r2}, 3});
                r2++;
                r++;
        }

        dfs0(1, 1);
        solve1();
        solve2();

        dfs(1, 1);

        cout << (int)ans.size() << "\n";
        sort(ans.begin(), ans.end());
        for (auto u : ans)
        {
                cout << u << " ";
        }

        return 0;
}
