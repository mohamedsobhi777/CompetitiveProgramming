#include<bits/stdc++.h>
#include<ext/rope>

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

const int N = 1e5 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n; 

ll bit[N] ; 

I add(int ix, int x){
        ix ++ ; 
        for(;ix<N;ix+=ix&-ix)
                bit[ix]+=x ;
}

ll upto(int x){
        x++ ;
        ll ret = 0; 
        for(;x;x-=x&-x)
                ret+= bit[x] ; 
        return ret;  
}

ll get(int l , int r){
        if(l == r)
                return 0 ; 
        if(l > r)
                swap(l , r) ; 
        return upto(r-1) - upto(l - 1) ; 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        //freopen("in.in" , "r" , stdin) ;
        int t ;
        cin >> t ; 
        while( t-- ){
                int n ;  
                cin >> n ; 
                int a[n+1] ; 
                int loc[n+1];
                ll tot = 0; 
                for(int i = 0 ;i < n; i ++ ){
                        cin >> a[i]   ; 
                        a[i] -- ; 
                        loc[a[i]] = i ; 
                        tot += i + 1;
                        add(i , a[i] + 1) ; 
                }
                ll ans = 0 ; 
                int pos = 0 ; 

                for(int i =0 ;i < n;i++){ 
                        int new_pos = loc[i] ;
                        ll now = get(pos , new_pos) ;  
                        now = min(now , tot - now) ; 
                        ans += now ; 
                        tot -= i + 1 ; 
                        add(new_pos , -(i + 1)) ; 
                        pos = (new_pos + 1) % n; 
                }
                cout<< ans<<"\n";
        }

        return 0 ; 
}