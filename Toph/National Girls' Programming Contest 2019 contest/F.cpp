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

double tr = acos(-1) / 180.0 ; 

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;

	//freopen("in.in" , "r" , stdin) ;

	int t ;
	cin >> t ; 
	while( t-- ){
		long double a , b , c; 
		cin >> a >> b >> c; 
		long double ans = a  * a; 
		long double bd = sqrt ( a * a + b * b - 2 * a * b * cos( tr * c  ) ) ;
		long double adb = asin( 1.0 * a * sin(tr * c) / bd ) / tr ; 
		long double adc = 180 - adb ;
		long double ac = sqrt(b * b + bd * bd - 2 * b * bd * cos(tr * adc)) ; 
		ans += ac * ac ; 
		cout<< fixed << setprecision(10) << ans <<"\n" ; 
	}

	return 0 ; 
}


