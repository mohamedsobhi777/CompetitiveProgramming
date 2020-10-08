#include<bits/stdc++.h>

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 5000 + 7 , mod = 1e9 + 7 ; 
const ll inf = 2e18 ; 

// How interesting!

int n ; 
int d[N] ; 
vector<int> adj[N] ;
ll ans ; 

ll pai[N], sai[N]; 
vector<int> hs ; 
vector<pii> hs2 ; 

void dfs(int x, int p, int h){
        ans+=pai[h] ; 
        hs.push_back(h) ;
        hs2.push_back({h,sai[h]}) ;  
        for(auto u : adj[x]){
                if(u == p)continue ; 
                dfs(u , x , h + 1) ; 
        }
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        cin >> n; 
        for(int i = 0 ;i < n - 1; ++ i){
                int u , v; 
                cin >> u >> v ; 
                adj[u].push_back(v) ; 
                adj[v].push_back(u) ; 
        }

        for(int i = 1;i <= n; ++ i){
                memset(pai, 0 , sizeof pai) ; 
                memset(sai , 0 , sizeof sai) ; 
                for(auto u : adj[i]){
                        dfs(u , i , 1) ; 
                        while(hs.size()){
                                sai[hs.back()]++;
                                hs.pop_back() ; 
                        }
                        while(hs2.size()){
                                pai[hs2.back().first]+=hs2.back().second ; 
                                hs2.pop_back() ; 
                        }
                }
        }
        cout<< ans ; 
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