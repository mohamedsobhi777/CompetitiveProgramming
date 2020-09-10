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

ll dp[N] ; 

I add(int v){
	dp[v] += dp[v-1]; 
	dp[v] %= mod ; 
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;

	dp[0] = 1ll ; 

	cin >> n; 
	for(int i = 1;i <= n ;i++){
		int x ; 
		cin >> x ;
		vector<int> div ; 

		for(int j = 1 ;j * j <= x ;j++){
			if(x%j == 0){	
				if(j * j != x){
					div.push_back(x / j) ; 
				}
				div.push_back(j) ; 
			}
			
		}
		sort(div.begin() , div.end()) ; 
		while(div.size()){
			add(div.back()) ; 
			div.pop_back() ; 
		}
	}
	cout<< accumulate(dp + 1 , dp + n + 1 , 0LL) %mod ; 
	return 0 ; 
}


