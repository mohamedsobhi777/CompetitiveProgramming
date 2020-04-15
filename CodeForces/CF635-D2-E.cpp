/*
    Problem : E. Kaavi and Magic Spell
    Contest : CF635-Div2
    problem link : https://codeforces.com/contest/1337/problem/E
    handle : Mohamed.Sobhy

    Solution : 
        let n be the length of the first string and m be the length of the second string 
        we will try to count the number of strings with length i (m<=i<=n) with T be prefix of each
        using a simple dp, we can calculate the number of strings with a fixed length i

*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e6 + 7 ; 

int n ,m ;
int ans ; 
int mod = 998244353 ; 

string s ,t ; 

long long dp[3001][3001] ; 

long long add(long long a , long long b){
    return (a%mod + b%mod ) %mod ; 
}

long long solve(int l , int r){
    if(r < l)return 1ll  ;
    if(dp[l][r]!=-1)return dp[l][r] ;
    int ran = r-l+1 ; 
    long long ret = 0 ;
    
    if( l < m  ){
        if(s[ran-1] == t[l]){
            ret = add(ret , solve(l+1 , r)) ; 
        }
    }
    else{
            ret = add(ret , solve(l+1 , r)) ; 
    }

    if(r < m){
        if(s[ran-1] == t[r]){
            ret = add(ret , solve(l , r-1)) ; 
        }
    }
    else{
        ret = add(ret , solve(l , r-1)) ; 
    }
    return dp[l][r] = ret ; 
}   

int main(){
    memset(dp , -1 , sizeof dp) ; 
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; 
    cin>>s>>t ;
    n = s.size()  ;
    m = t.size() ; 
    for(int i = m ;i<=n;i++){
        //for fixed length i, how many string satisify the conditions
        ans = add(ans , solve(0 , i-1) )  ;
    }
    cout<<ans; 
    return 0 ;
}
