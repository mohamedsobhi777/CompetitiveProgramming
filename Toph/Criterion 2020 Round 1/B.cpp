#include<bits/stdc++.h>


#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 6e6 + 7 , mod = 1e9 + 7 ; 
const ll inf = 2e18 ; 

// How interesting!

int n ; 
int d[N] ; 

void bfs(){
        for(int i = 0 ;i < N; ++ i)
                d[i] = 1e9 ;
        d[1] = 0 ; 
        queue<int> q ;
        q.push(1) ; 
        while(q.size()){
                int tp = q.front() ; 
                q.pop() ; 
                int cnt = 0 ;
                for(auto u : {tp + 1,tp * 2 , tp - 1, tp / 2}){
                        if(u >= N || u <= 0 || (tp%2 == 0 && cnt++ == 3))continue ;
                        if(d[tp] + 1 < d[u]){
                                d[u] = d[tp] + 1; 
                                q.push(u) ; 
                        }
                }
        }
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        bfs() ; 
        int t; 
        cin >> t ; 
        while(t -- ){
                int x ; cin >> x;
                cout<< d[x] <<"\n" ;
        }       
        return 0 ; 
}

/*
        - bounds sir (segtree = 4N, eulerTour = 2N, ...)
        - a variable defined twice?
        - will overflow?
        - is it a good complexity?
        - don't mess up indices (0-indexed vs 1-indexed)
        - reset everything between testcases. 
*/