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

const int N = 1e5 + 7 , mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
// How interesting!

int n , m , p , k ;

vector<pair<ll,ll>>adj[2][N] ; 

ll d[2][N]; 

I dijkstra(int x , int source){

	d[x][source] = 0 ; 
	priority_queue<pair<ll,int>> q ; 
	q.push({0 , source}) ; 

	while(q.size()){
		ll dst = -q.top().first;
		int node = q.top().second ; 
		q.pop() ; 
		
		for(auto u : adj[x][node]){
			if(dst + u.second < d[x][u.first]){
				d[x][u.first] = dst + u.second ; 
				q.push({-d[x][u.first] , u.first}) ;
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ;
	int t ;
	cin >> t; 
	for(int tc = 1; tc <= t ; tc ++){
		cin >> n >> m >> p >> k ; 

		for(int i = 0 ;i < m; i++){
			ll u , v,c ; 
			cin >> u >> v >> c; 
			adj[0][u].push_back({v , c}); 
			adj[1][v].push_back({u , c}) ; 
		}

		for(int i = 0 ; i < N ;i ++){
			d[0][i] = d[1][i] = inf ; 
		}

		dijkstra(0 , p ) ; 
		dijkstra(1 , p ) ; 
		cout<< "Case " << tc <<":\n" ; 
		for(int i = 0 ;i < k ; i ++){
			int u , v ;
			cin >> u >> v ; 
			ll ans = d[0][v] + d[1][u] ; 
			if(ans >= inf){
				cout<<"Be seeing ya, John\n" ; 
			}
			else{
				cout<< ans <<"\n" ; 
			}
		}
		for(int i = 1; i <= n;i++){
			adj[0][i].clear() ; 
			adj[1][i].clear() ; 
		}
	}
	return 0 ; 
}


