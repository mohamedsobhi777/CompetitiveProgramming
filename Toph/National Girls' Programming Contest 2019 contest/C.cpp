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

const int N = 5000 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n ;
int cl[N] ; 

int get(string s){
	return (s[0] - '0') * 10 + s[1] - '0' ; 
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;

	int t; 
	cin >> t ; 
	for(int tc = 1 ; tc <= t ; tc ++){
		int n ; 
		cin >> n ; 
		memset(cl , 0 , sizeof cl) ;

		for(int k = 1; k <= n ;k ++){
			string s , t; 
			cin >> s >> t ; 
			int hr1 = get(s.substr(0 , 2)) ; 
			int mn1 = get(s.substr(3 ,2)) ; 
			int hr2 = get(t.substr(0 , 2)) ; 
			int mn2 = get(t.substr(3 , 2)) ; 

			hr1 = hr1 * 60 + mn1 ; 
			hr2 = hr2 * 60 + mn2 ; 

			if(hr2 > hr1){
				for(int j = hr1 ; j < hr2 ;j++){
					cl[j] ++ ; 
				}	
			} else{
				for(int j = hr1 ; j <=1440 ;j++){
					cl[j] ++ ; 
				}

				for(int j = 0 ; j < hr2 ;j++){
					cl[j] ++ ; 
				}
			}
		}
		int ans = 0 ; 

		for(int i = 0 ;i <= 1440 ;i ++){
			ans = max(ans , cl[i]) ; 
		}
		cout<<"Case #" << tc <<": Mr.Xifu needs " << ans <<" classroom(s)\n" ;
	}

	return 0 ; 
}


