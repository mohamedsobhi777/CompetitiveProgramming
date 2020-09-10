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

ll n , k ;
ll delta ; 
vector<ll> mst[N] ;
ll a[N];

I add(ll ix , ll v){
	for(;ix<N;ix+=ix&-ix)
		mst[ix].push_back(v) ; 
}

ll upto(ll x, ll l , ll r){
	ll ret = 0 ; 
	for(;x;x-=x&-x)
		ret += upper_bound(mst[x].begin() , mst[x].end() , r) - lower_bound(mst[x].begin() , mst[x].end() , l) ;
	return ret ;  
}

ll get(ll l , ll r , ll A , ll B){
	if(l > r)
		return 0 ; 
	return upto(r , A , B) - upto(l - 1 , A ,B) ;
}

I init(){
	for(int i = 0 ;i < N ;i++)
		sort(mst[i].begin() , mst[i].end()) ; 
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;

	cin >> n >> k ; 
	for(int i = 1 ;i <= n ;i ++){
		ll x ; 
		cin >> x ; 
		add(i , x) ; 
		a[i] = x ;
	}
	init() ;
	sort(a + 1 , a + n + 1) ; 

	while(k -- ){
		ll id ; 
		cin >> id ;
		if(id == 1){
			ll x ;
			cin >> x ; 
			delta -= x ;
		}
		else{
			ll A , B , k ;
			cin >> A >> B >> k ;
			ll nums = get(1 , n , A - delta , B - delta) ; 
			if(nums < k){
				cout<< "-1\n";
				continue ;
			}
			ll pref = get(1 , n , -inf , A - 1 - delta) ; 
			cout<<a[pref + k] + delta <<"\n" ; 
		}
	}

	return 0 ; 
}


