#include<bits/stdc++.h>

/*
#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")*/

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 5e5 + 7 , mod = 1e9 + 7 ; 
const ll inf = 1e8 ; 
// How interesting!

int n; 
map<string , int > cmp ; 

int nodes ; 
int cst[N];

int com(string x){
        if( !cmp[x]){
                cmp[x] = ++ nodes ; 
        }
        return cmp[x]; 
}

vector<pair<int,int>> adj[N] ;

I edge(int u , int v , int w){
        adj[u].push_back({v , w}) ;
        adj[v].push_back({u , w}) ; 
}

int delta(string x){
        if(x[0] == 'S')
                return 1 ; 
        else if(x[0] == 'R')
                return 2 ; 
        else if(x[0] == 'A')
                return 3 ;
        return 4; 
}

int d[N] ; 

int dijkstra(int st , int en){
        priority_queue<pair<int,int>>q ; 
        q.push({0 ,st}) ; 
        for(int i = 0 ;i <= n * 10 ;i++)
                d[i] = inf ;
        d[st] = 0 ; 
        while(q.size()){
                int dst = -q.top().first ; 
                int node = q.top().second ; 
                q.pop() ; 
                for(auto u :adj[node]){
                        if(dst + u.second < d[u.first]){
                                d[u.first] = dst + u.second ; 
                                q.push({-d[u.first], u.first});
                        }
                }
        }
        return d[en] ;
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        //freopen("in.in" , "r" , stdin) ;

        int t ;
        cin >> t ; 
        while( t-- ){
                nodes = 0; 
                cmp.clear() ;
                cin >> n; 
                for(int i = + 1 ;i <= n;i++){
                        string s ; 
                        int x ;
                        cin >> s >> x; 
                        for(int j = 1;j < 5 ;j ++){
                                edge(i * 5, i * 5 + j, x) ; 
                        }
                        com(s); 
                        for(int j = 1 ; j< 5 ;j ++){
                                for(int k = j + 1;k < 5; k ++){
                                        edge(i * 5 + j , i * 5 + k , x) ; 
                                }
                        }
                        cst[i] = x ; 
                }

                int k ; cin >> k ; 
                while(k -- ){
                        string s , t , m ; 
                        int x;
                        cin >> s >> t >> m >> x;
                        int u = com(s) ; 
                        int v = com(t) ; 
                        int r = delta(m); 
                        edge(u * 5 + r, v * 5 + r, x);
                }
                string s , t; 
                cin >> s >> t; 
                int st = com(s) ; 
                int en = com(t) ; 
                cout << dijkstra(st * 5, en * 5) - cst[st] - cst[en] <<"\n" ;
                for(int i =1 ;i <= n * 10; i ++){
                        adj[i].clear() ; 
                }
        }

        return 0 ; 
}