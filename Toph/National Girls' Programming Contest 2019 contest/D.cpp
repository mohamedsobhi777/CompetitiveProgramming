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

int n ,m ;
int eul[N] ; 
bool p[N] ; 
ll a[N] ; 

I init(){
	for(int i = 0 ;i < N ;i++)
		eul[i] = i ; 
	eul[1] = 1; 
	for(int i =2 ; i < N ;i++){
		if(p[i])
			continue ;
		eul[i] -- ; 
		for(int j = i + i ;j < N; j+= i){
			eul[j] -= eul[j] / i ; 
			p[j] =1 ; 
		}
	}

}

ll bit[N]; 

I add(int i , ll x){
	for(;i<N;i+=i&-i)
		bit[i]+=x ; 
}

ll upto(ll x){
	ll ret = 0 ; 
	for(;x;x-=x&-x)
		ret+=bit[x] ;
	return ret ; 
}

ll get(int l , int r){
	return upto(r) - upto(l -1) ; 
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;

	init() ; 

	cin >> n >> m ;
	for(int i = 1 ;i <= n;i++){
		int x ;
		cin >> x ; 
		add(i , eul[x]) ;
		a[i] = eul[x] ;
	}

	while(m -- ){
		int x , y , z ; 
		cin >> x >> y >> z ; 
		if(x == 1){
			add(y , eul[z] - a[y]) ;
			a[y] = eul[z] ;
		}else{
			cout<< get(y , z) <<"\n" ;
		}
	}

	return 0 ; 
}


