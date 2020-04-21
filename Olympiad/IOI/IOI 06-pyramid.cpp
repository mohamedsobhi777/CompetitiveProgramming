/*
    Problem : IOI 06-pyramid
    link : https://contest.yandex.ru/ioi/contest/562/problems/B/
    Solution : https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/IOI/official/2006/ioi06_pyramid_sol.pdf
    O(N^2) 
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;

int ans;
int n, m;
int a, b;
int A, B;

int arr[N][N];
int par[N][N];

int sum1[N][N];
int sum2[N][N];

int get(int x0, int y0, int x1, int y1)
{
    return par[x1][y1] - par[x0 - 1][y1] - par[x1][y0 - 1] + par[x0 - 1][y0 - 1];
}

struct slidingwindow
{

    int l, r;
    deque<pair<int, pair<int, int> > > dick;

    slidingwindow()
    {
        l = r = 0;
    }

    void push_back(int x, int ix)
    {
        while (dick.size() && dick.back().first >= x)
            dick.pop_back();
        dick.push_back({x, {ix, r} });
        r++;
    }

    void pop_front()
    {
        if (dick.front().second.second == l)
        {
            dick.pop_front();
        }
        l++;
    }

    pair<int, pair<int, int> > get_min()
    {
        if (dick.empty())
            return {1e9, {0, 0} };
        return dick.front();
    }
};

pair<int, int> anss[N][N];

bool bad(int x, int y)
{
    return x + A - 1 > n || y + B - 1 > m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    cin >> B >> A;
    cin >> b >> a;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            par[i][j] = arr[i][j] + par[i - 1][j] + par[i][j - 1] - par[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i + A - 1 <= n && j + B - 1 <= m)
                sum1[i][j] = get(i, j, i + A - 1, j + B - 1);
            else
                sum1[i][j] = -1e7;
            if (i + a - 1 <= n && j + b - 1 <= m)
                sum2[i][j] = get(i, j, i + a - 1, j + b - 1);
            else
                sum2[i][j] = 1e7;
        }
    }

    int window = B - b - 1;

    for (int i = 1; i <= n; i++)
    {
        slidingwindow s;
        for (int j = 1; j < window; j++)
        {
            s.push_back(sum2[i][j], 0);
        }

        for (int j = window; j <= m; j++)
        {
            s.push_back(sum2[i][j], 0);
            if (j > window)
                s.pop_front();
            pair<int, pair<int, int> > gt = s.get_min();
            anss[i][j - window + 1] = {gt.first, gt.second.second};
        }
    }

    int x0, y0;
    int x1, y1;
    int door = A - a - 1;

    for (int j = 1; j < m; j++)
    {
        slidingwindow s;
        for (int i = 2; i <= door; i++)
        {
            s.push_back(anss[i][j + 1].first, anss[i][j + 1].second);
        }
        for (int i = door + 1; i <= n; i++)
        {
            s.push_back(anss[i][j + 1].first, anss[i][j + 1].second);
            if (i > door + 1)s.pop_front();
            pair<int, pair<int, int> > gt = s.get_min();
            if (sum1[i - door ][j] - gt.first > ans)
            {
                ans = sum1[i - door ][j] - gt.first;
                x0 = i -door;
                y0 = j;
                x1 = gt.second.second + 2;
                y1 = gt.second.first + 1;
            }
        }
    }
    cout << y0 << " " << x0 << "\n";
    cout << y1 << " " << x1 ;
    return 0;
}
