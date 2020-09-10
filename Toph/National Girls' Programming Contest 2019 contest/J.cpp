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

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 3e5 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n ;

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;
	int t ; 
	cin >> t; 
	while( t-- ){
		ll a , b ;
		ll ans = 0;
		cin >> a >> b ; 
		for(int i = 0 ;i < 60 ;i ++){
			ll x = (1LL<<i) ; 
			if(x >= a && x <= b)
				ans += x ; 
		}
		cout << ans <<"\n" ;
	}
	return 0 ; 
}


