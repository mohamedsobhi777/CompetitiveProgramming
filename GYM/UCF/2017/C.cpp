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
const int inf = N ; 
// How interesting!

int n; 

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        //freopen("in.in" , "r" , stdin) ;
        ll t ; 
        cin >> t ;
        while(t -- ){

                ll n , m; 
                cin >> n >> m ;
                ll ans = 0 ; 
                ll ls ; 
                for(int i = 0 ;i < m;i++){
                        ll x; cin >> x; 
                        x-- ; 

                        if(i){
                                ans += max(0ll , min ( (ls - x + n) % n , (x - ls + n) % n ) ); 
                        }
                        ls = (x + 1) % n; 
                }
                cout<< ans <<"\n" ; 
        }
        return 0 ; 
}