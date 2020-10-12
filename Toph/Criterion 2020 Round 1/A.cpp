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

const int N = 2e6 + 7 , mod = 1e9 + 7 ; 
const ll inf = 2e18 ; 

// How interesting!

int n ; 
int f[N] ; 

void add(int x, int d){
        for(int i = x ; i < N ; i+=d)
                f[i] ++ ; 
}
int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        for(int i = 2 ; i <= 1000000 ; ++ i){
                ll st = 1 + 1ll * i * i ;
                while(st + i < N){
                        f[st] ++ ; 
                        f[st+i-1] -- ; 
                        st+= 1ll * i * i ; 
                }
        }
        for(int i = 1;i <N ; ++ i)
                f[i] += f[i-1] ; 
        int t ; cin >> t ;
        for(int i = 1 ;i <= t ; ++ i){ 
                int x; cin >> x ;
                cout<< "Query " << i <<": " <<  f[x] <<"\n" ;
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