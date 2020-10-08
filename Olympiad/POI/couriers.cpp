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

const int N = 5e5 + 7 , mod = 1e9 + 7 ; 
const ll inf = 2e18 ; 
// How interesting!

int n,m;
int a[N] ;  
vector<int> vec[N] ; 

int get(int l , int r , int x){
        return upper_bound(vec[x].begin() , vec[x].end() , r) - 
        lower_bound(vec[x].begin() , vec[x].end() , l) ; 
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        cin >> n >> m; 
        for(int i = 0 ;i < n; ++ i){
                cin >> a[i] ; 
                vec[a[i]].push_back(i) ; 
        }
        srand(time(0)) ; 
        for(int i = 0 ;i < m; ++ i){
                int l , r; 
                cin >> l >> r ; 
                l-- ; r -- ; 
                int len = r - l + 1; 
                int ans = 0 ; 
                for(int j = 0 ; j < 20 ; ++ j){
                        int x = rand() % len + l ; 
                        if(get(l , r , a[x])*2>len){
                                ans = a[x] ; 
                        }
                }
                cout<< ans <<"\n" ;
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