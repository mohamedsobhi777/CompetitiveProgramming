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

const int N = 2e5 + 7 , mod = 1e9 + 7 ; 
const ll inf = 2e18 ; 

// How interesting!

int n, m; 
int fat[N] ;
int sz[N] ; 
vector< vii > hist ;
vii last, even ; 

int find(int x){
        if(fat[x] == x)
                return x ; 
        return find(fat[x]) ; 
}

vector<int> touched ; 

void touch(int x){
        touched.push_back(x) ; 
        if(x == fat[x])
                return ; 
        touch(fat[x]) ;
}

void link(int u , int v){
        last = {} ; 
        touched = {} ; 
        touch(u) ; 
        touch(v) ; 
        for(auto u : touched){
                last.push_back({u , fat[u]}) ; 
                last.push_back({-u,sz[u]}); 
        }
        u = find(u) ; 
        v = find(v) ; 
        if(u != v){
                fat[u] = v ;
                sz[v] += sz[u] ; 
                sz[u] = 0 ; 
        }
        hist.push_back(last) ; 
}

void rollback(int x , int y){
        pii lo = { 0 , 0 } ; 
        vii ls ; 
        while(sz[find(x)] >= y){
                ls = hist[hist.size() - 1]; 
                while(hist.back().size()){
                        pii ev = hist.back().back() ; 
                        if(ev.first > 0){
                                fat[ev.first] = ev.second ; 
                        }else{
                                sz[-ev.first] = ev.second ;
                        }
                        hist.back().pop_back() ; 
                }
                lo = even.back() ;
                even.pop_back() ; 
                hist.pop_back() ;
        }
        if(lo.first){
                link(lo.first , lo.second) ; 
                even.push_back(lo) ; 
        }
}

void init(int _n){
        n = _n ; 
        for(int i = 1;i<=_n; ++ i){
                sz[i] = 1; 
                fat[i] = i ; 
        }
        hist.clear() ;
        even.clear() ; 
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
      
        //freopen("in.in" , "r" , stdin) ; 
        int t; cin >> t ; 
        for(int k = 1 ; k<= t ; ++ k){
                cout<<"Case " << k <<":\n" ; 
                cin >> n >> m; 
                init(n) ; 
                for(int i = 0 ; i < m; ++ i){
                        int x ; cin >> x ;
                        if(x == 1){
                                int y , z;
                                cin >> y >> z ;
                                if(sz[find(y)]>sz[find(z)])
                                        swap(y , z) ; 
                                link(y , z) ;
                                even.push_back({y , z}) ;  
                        }else if(x == 2){
                                int y ; cin >> y ; 
                                cout<< sz[find(y)] <<"\n" ; 
                        }else{
                                int y , z ; 
                                cin >> y >> z ; 
                                rollback(y , z) ; 
                                cout<< sz[find(y)] <<"\n" ; 
                        }
                }
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
