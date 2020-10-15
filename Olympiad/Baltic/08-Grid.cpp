/*
	Problem : Baltic 08-Grid
	link : https://cses.fi/114/list/

	Solution : 
		use bruteforce over all the choices of the r splits, now we can calculate the answer easily using dp
*/


#include<bits/stdc++.h>

using namespace std ; 

const int N = 40 + 7 ; 

int n , m , a, b ; 
int A[N][N] ; 

int msk  ; 
int dp[N][N] ; 

int solve(int i , int r ){
	if(dp[i][r]!=-1)
		return dp[i][r] ;
	if( i == m){
		if(r) return 1e8 ; 
		return 0 ;  
	}
	int ret = 1e9 ; 
	int cnt = __builtin_popcount(msk) ; 
	vector<int> vs (cnt +1 , 0) ;
	for(int j = i ;j < m;j++){
		int cur = 0 ; 
		int ix = 0 ; 
		int x = 0; 
		for(int ii = 0 ;ii < n ;ii++){
			cur+=A[ii][j] ; 
			if( (msk&(1<<ii)) || ii == n-1 ){
				vs[ix++] +=cur ; 
				x = max(x , vs[ix-1]) ; 
				cur = 0 ;
			}
 
		}
		int k = solve(j+1 , r-1) ; 
		if(k < 1e8) ret = min(ret , max(k , x)) ;  

	}	
	return dp[i][r] = ret ; 
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 

	cin>>n>>m>>a>>b ; 

	for(int i= 0 ;i < n; i++){
		for(int j = 0 ;j < m ;j++){
			cin>>A[i][j] ; 
		}
	}
	int ans = 1e9 ; 
	for(int mask = 0 ; mask < (1<< (n-1) ) ; mask++){
		int cnt = __builtin_popcount(mask) ; 
		if(cnt != a) continue ;
		msk = mask ; 
		memset(dp , -1 , sizeof dp)  ;
		ans = min(ans , solve(0  , b +1 )) ; 
	}
	cout<<ans ; 
	return 0 ; 
}
