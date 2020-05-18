#include<bits/stdc++.h>

using namespace std ; 

const int N = 250 + 7 ; 

int n , m , all , r ;
int ans = 1e8 ; 

int a[N][N] , sm[N][N] ; 

int get(int x0 , int y0 , int x1 , int y1){
	return sm[x1][y1] - sm[x0-1][y1] - sm[x1][y0-1] + sm[x0-1][y0-1] ; 
}

int colst[N] ; 
int colen[N] ; 
int rowst[N] ; 
int rowen[N] ; 

int setmn(int &pos , int val){
	if(pos == 0){
		pos = val ; 
	}
	else {
		pos = min(pos , val) ; 
	}
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 

  cin>>m>>n ; 
	cin>>all>>r ; 
	for(int i = 0 ;i < all; i++){
		int x , y ; 
		cin>>x>>y ; 
		sm[x][y]++ ; 
	}
	for(int i = 1 ;i <N ;i++ ){
		for(int j = 1 ; j <N;j++){
			sm[i][j] +=sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1] ; 
		}
	}
	
	for(int i = 1 ;i <= m ;i++){
		for(int j =i ;j <= m ;j++){
			int l = 1;
			int sum = 0 ; 
			for(int k = 1 ; k <= n ;k++){
				sum+=get(i , k , j , k) ; 

				while(sum > r || (get(i , l , j , l) == 0) ){
					sum-=get(i , l , j , l) ; 
					l++ ; 
				}
				int peri = 2 * (j - i +1) + 2 * (k - l +1) ; 
				if(sum == r){
					setmn(rowst[i] , peri) ; 
					setmn(rowen[j] , peri) ; 
					setmn(colst[l] , peri) ; 
					setmn(colen[k] , peri) ; 
				}				
			} 
		}
	}
	for(int i  =1  ;i <N ;i++){
		for(int j = 1 ; j<i ;j++){
			if(rowst[i] && rowen[j])
				ans = min(ans , rowst[i] + rowen[j]) ; 
			if(colst[i] && colen[j])
				ans = min(ans , colst[i] + colen[j]) ; 
		}

	}
	if(ans < 1e8)
		cout<< ans ; 
	else cout<<"NO" ;
	return 0 ; 
}
