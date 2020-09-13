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

const int N = 100 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n, k ;

int dp[N][N] ; 
int lis[N][N] ; 
int a[N] ; 

int solve(int i, int l){
        if(~dp[i][l])
                return dp[i][l] ;
        if(i == n)
                return 0 ; 
        int ret = 0 ; 
        ret = max(ret , solve(i + 1, l) ) ;

        if(lis[l][i] >= k){
                ret = max(ret , solve(i + 1 , i + 1) + lis[l][i] ) ; 
        }
        return dp[i][l] = ret ; 
}


int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        //freopen("in.in" , "r" , stdin) ;

        int t ;
        cin >> t;
        while(t -- ){
                memset(lis , 0 , sizeof lis) ;
                cin >> n;
                for(int i = 0 ;i < n;i++){
                        cin >> a[i] ; 
                }

                for(int i = 0 ;i < n;i++){
                        vector<int> dp(n + 1, 0) ; 
                        dp[i] = 1; 
                        for(int j = i ;j < n ;j++){
                                dp[j] = 1; 
                                for(int k = i ; k < j ;  k ++){
                                        if(a[k] < a[j]){
                                                dp[j] = max(dp[j] , dp[k] + 1) ; 
                                        }
                                }
                                lis[i][j] = dp[j] ; 
                        }
                }

                for(int i = 0 ;i < n;i++){
                        int ret = 0 ; 
                        for(int j = i ;~ j ; j-- ){
                                ret = max(ret , lis[j][i]) ; 
                                lis[j][i] = ret ; 
                        }
                }
 
                for(int i =1 ;i <= n;i++){
                        k = i ; 
                        memset(dp , -1 , sizeof dp) ;
                        cout<< solve(0 , 0) <<" " ; 
                }
                cout<<"\n" ;
        }

        return 0 ; 
}