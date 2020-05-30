/*
        Problem : COCI 09-Ograda
        Problem Link : https://wcipeg.com/problem/coci094p4
        handle : mohamedsobhi777

        Solution : 

                maintain a slinding window, that keeps the sum of each consective x (the size of the roller ) and the min element,
                        now we use the roller if the last time we used it was at least x indices (if we used it at position i then the next time we will used 
                        is at most i + x), this is because we don't want to miss any coulmns.

                        the second case when we make a roll, if the next element is strictly less than all the elements in the window
                                consider the example x = 2 , a = {3 , 3 , 3 , 2}, we will make a roll at position 0 (leftmost index = 0) and at index 1

        O(N log N) 

        note : we can remove the log factor if we use stacks instead of set, but it is not necessary

*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

long long n, x;
long long a[N];
long long pre[N];

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
                pre[i] += a[i];
                pre[i + 1] += pre[i];
        }
        multiset<int> mul;
        long long l = -1, v = 0;
        long long ans1 = pre[n - 1];
        long long ans2 = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
                mul.insert(a[i]);
                sum += a[i];
                if (i < x - 1)
                        continue;
                if (i >= x)
                {
                        mul.erase(mul.find(a[i - x]));
                        sum -= a[i - x];
                }
                auto mn = mul.begin();
                long long m = (*mn);
                if (i - x == l || a[i + 1] < m || m > v)
                {
                        ans2++;
                        long long add = 0;
                        if (m > v)
                        {
                                add = 1LL * m * x - 1LL * v * (l - (i - x));
                        }
                        else
                        {
                                add = 1LL * m * (i - l);
                        }
                        ans1 -= add;
                        l = i;
                        v = m;
                }
        }
        cout << ans1 << "\n";
        cout << ans2 << "\n";
        return 0;
}
