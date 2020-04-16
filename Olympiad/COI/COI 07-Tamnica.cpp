/*

    Problem : COI TAMNICA
    Solution : 
        https://github.com/quangloc99/CompetitiveProgramming/blob/master/olympiad/COI/2007-2008/tamnica/main.cpp

*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
long long n, t;
set<long long > nods ; 
vector<pair<long long , long long > > adj[N] ;

//calculate the number of the smallest neighbour
long long num(long long x)
{
    long long X = x;
    long long ret = 0;
    long long wall = sqrt(x - 1) / 2 + 1;
    long long before = (wall - 1) * 2;
    before *= before;
    x -= before;
    long long raqm = wall * 2 - 1;
    long long odd1 = raqm * 2 - 1;
    long long odd2 = raqm * 2 + 1;
    long long par = 1;
    long long mil1 = odd1 / 2;
    long long mil2 = odd1;
    long long mil3 = odd1 + odd2 / 2;
    par += (x > mil1) + (x > mil2) + (x > mil3);
    par += (wall - 2) * 4 + 1;
    long long tax = 2 * par + 1;
    return X - tax;
}
map<long long , bool > mp ; 
map<long long , long long > dis ; 

map<long long , int > com ;
int T = 1 ; 

long long dij(){
    mp[com[1]] = 1 ; 
    priority_queue<pair<long long  , long long > > q ; 
    q.push({0 , com[1]}) ; 
    while(q.size()){
        long long dist = -q.top().first ; 
        long long node = q.top().second ; 
        q.pop() ;
        for(auto u :adj[node] ){
            if(!mp[u.first] || dist + u.second < dis[u.first]){
                dis[u.first] = dist + u.second ; 
                mp[u.first] = 1 ; 
                q.push({-dis[u.first] , u.first}) ; 
            }
        } 
    }
    return dis[com[t]] ;
}

int main()
{    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("test.in" , "r"  ,stdin) ; 
   // freopen("in.in" , "r" , stdin) ;
    cin >> t;
    cin >> n;
    vector<long long > v ; 
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> b;
        v.push_back(b) ;
        nods.insert(b) ; 
        nods.insert(num(b)) ; 
    }
    com[1] = T++ ; 
    nods.insert(t) ; 
    long long l = 1 ;
    for(auto u: nods){
        com[u] = T++ ; 
        adj[T-1].push_back({ T-2 , abs(u - l) }) ; 
        adj[T-2].push_back({T-1 , abs(u - l)}) ; 
        l = u ; 
    }
    for(auto u : v){
        long long U = u ; 
        long long  V = num(U) ; 
        int xu = com[U] ; 
        int xv = com[V] ; 
        adj[xu].push_back({xv , 1}) ; 
        adj[xv].push_back({xu,1}) ; 
    }
    cout<<dij() ; 
    return 0;
}
