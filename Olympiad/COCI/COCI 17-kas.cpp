/*
    Problem : KAS (COCI17_KAS)
    link : https://oj.uz/problem/view/COCI17_kas
    solution : 
        	https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2017/contest4_solutions
*/
#include<bits/stdc++.h>
 
using namespace std ; 
 
const int N = 1e5 + 7 ; 
int offset  = 1e5 + 7 ; 

int n , sum;
int a[N] ; 
int dp[552][2*N] ;
 
int solve(int i , int k){
    if(~dp[i][k])return dp[i][k] ; 
    if(i==n)return (k==offset ? 0 : 1e9) ; 
    return dp[i][k] = min( min( solve(i+1 , k + a[i]) , solve(i+1 , k - a[i])  ) , solve(i+1 , k) + a[i] )  ; 
}
 
int main(){
    memset(dp , -1 , sizeof dp) ; 
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0); 
    cin>>n ;
    for(int i = 0 ;i < n;i++){
        cin>>a[i]; 
        sum+=a[i] ; 
    }
    int mn = solve(0 , offset) ; 
    cout<<(sum - mn) /2 + mn ;
    return 0 ; 
}
