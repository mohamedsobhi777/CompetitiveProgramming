/*
  Problem : IOI 13-dreaming
  link :https://oj.uz/problem/view/IOI13_dreaming
  
  solution : 
       http://blog.brucemerry.org.za/2013/07/ioi-2013-day-1-analysis.html

*/
#include<bits/stdc++.h>
#include "dreaming.h"
 
using namespace std ; 
 
const int N = 1e5 + 7 ; 
 
int mn ; 
int vis[N] ; 
int mxx[N] ; 
int anss[N] ;  
 
vector<pair<int , int > > adj[N]; 
int node , dst ; 
int ansi , ans2;
 
int solve1(int x, int p){
    int ret = 0 ; 
    for(auto u : adj[x]){
        if(u.first==p)continue ; 
        int dfx = solve1(u.first , x) + u.second ; 
        ret = max(ret , dfx) ;
    }
    anss[x] = ret ; 
    return mxx[x] = ret ; 
}
 
int dfs1(int x, int p , int dp = 0 ){
    vis[x] ++ ; 
    anss[x] = max(anss[x] , dp ) ;
    ansi = min(ansi , anss[x]) ; 
    ans2 = max(ans2 , anss[x]) ; 
    vector<int> dps , pre , suf; 
    for(auto u : adj[x]){
        if(u.first == p)continue ; 
        dps.push_back(mxx[u.first] + u.second) ;
        int mx = pre.size() ? pre.back() : 0 ; 
        pre.push_back(max(mx , dps.back())) ; 
    }  
    suf.resize(pre.size()) ;
    if(suf.size())
    suf[suf.size()-1] = dps[suf.size()-1] ; 
    for(int i = suf.size() -2 ; i >=0 ;i --){
        suf[i] = max(dps[i] , suf[i+1]) ; 
    }
    int i = 0 ; 
    for(auto u : adj[x]){
        if(u.first==p)continue ;
        int subdp = 0 ;
        if(i) subdp = max(subdp , pre[i-1]) ; 
        if(i < suf.size() -1 ) subdp = max(subdp , suf[i+1]) ; 
        dfs1(u.first , x , max(dp , subdp) + u.second) ; 
        i++; 
    } 
}
 
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for(int i  =0 ; i< M ;i++){
        adj[A[i] +1 ].push_back({B[i]+1 , T[i]}) ;
        adj[B[i]+1].push_back({A[i]+1 , T[i]}) ;
    }
    vector<int> v; 
    multiset<int> mul ; 
    for(int i = 1; i <=N ; i++){
        if(vis[i])continue ; 
        ansi = 2e9 ; 
        solve1(i , i ) ; 
        dfs1(i , i) ;
        v.push_back(ansi) ; 
        mul.insert(ansi) ;
    }
    if(v.size() == 1)return ans2 ; 
    else if(v.size() ==2 )return max(v[0] + v[1]  + L , ans2) ; 
 
    int s = v.size() ; 
    int ans = 2e9 ; 
 
    for(auto u : v){
        mul.erase(mul.find(u)) ; 
        int mx1 = -1 , mx2 = -1 ; 
        auto e = mul.end() ;
        e-- ; mx1 = *e ; 
        e-- ; mx2 = *e ;
        int now = max(u + mx1 + L , mx1 + mx2 + L + L ) ; 
        ans = min(ans , now ) ;
        mul.insert(u) ; 
    }   
    return max(ans , ans2) ; 
}
