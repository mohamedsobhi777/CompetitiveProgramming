/*
    Problem : RACE (IOI11_RACE)
    link : https://oj.uz/problem/view/IOI11_race

    Solution : 

        root the tree at 1
        for each node x we keep hei[x] = sum of weights on all edges between x and 1
                                ldr[x] = the number of edges between x and 1
        
        now for each node x we consider the paths with endpoints at A , B, such that LCA (A , B) = x
        
        the solution uses dsu on tree to store for each node, the number of nodes having hei[i] = h , storing these information in a hash map

        there is 2 cases: 

        first if A = x, and B is somewhere in the subtree rooted at x
        second if A and B are in different subtrees

        both types can be handled using the information stored in each node

*/

#include "race.h"
#include<bits/stdc++.h>

using namespace std ; 
const int NN = 1e6 + 7 ; 

long long n , k ; 
long long ans = 10000000000000 ; 
vector<pair<long long , long long > > adj[NN] ; 
long long hei[NN] , ldr[NN] , sz[NN]; 
long long fr[NN] , ls[NN] , ver[NN]; 
map<long long , map<long long , long long >  > anss ; 
int t = 1; 

int dfz(int x , int p , long long h, int l = 1 ){
    ver[t] = x ; 
    fr[x] = t++ ; 
    int ret = 1; 
    hei[x] = h ; 
    ldr[x] = l ; 
    for(auto u : adj[x]){
        if(u.first==p)continue ; 
        ret+=dfz(u .first, x , h + u.second , l+1 ) ; 
    }
    ls[x] = t++ ; 
    return sz[x] = ret ; 
}

int dfs(int x , int p , bool keep){
    int big = 0 ; 
    for(auto u : adj[x]){
        if(u.first==p)continue ;
        if(sz[u.first] > sz[big]){
            big = u.first ; 
        }
    }
    for(auto u : adj[x]){
        if(u.first ==p || u.first ==big)continue ;     
        dfs(u.first, x , 0) ; 
    }
    if(big){
        dfs(big , x , 1 ) ; 
    }
    anss[hei[x]][ldr[x]]++;         
    for(auto u : adj[x]){
        if(u.first==p || u.first == big)continue ;
        vector<int> v ;
        for(int j = fr[u.first] ; j < ls[u.first] ;j ++ ){
            if( ver[j] ){
                long long he = hei[ver[j]] ; 
                long long dl = ldr[ver[j]] ; 
                long long drem = k - (hei[ver[j]] - hei[x] ) ;
                v.push_back(j) ; 
                if( drem <=0)continue ; 
                for(auto u : anss[ hei[x] + drem ]){
                    if(u.second){
                        ans = min(ans , u.first - ldr[x] + dl - ldr[x]) ; 
                    }
                }
            }
        }
        for(auto e : v){
            anss[hei[ver[e]]][ ldr[ver[e]] ]++ ; 
        }
    }    
    for(auto u: anss[hei[x] + k] ){
        if(u.second){
            ans = min(ans , u.first - ldr[x] ) ; 
        }
    }
    if(!keep){
        for(int i = fr[x] ; i < ls[x] ; i++){
            anss[hei[ver[i]]][ldr[ver[i]]] -- ; 
        }
    }
}

int best_path(int N, int K, int H[][2], int L[])
{
    n = N ;
    k = K ;
    bool zez = 0 ; 
    for(int i = 0 ;i < n-1 ;i++){
        adj[H[i][0]+1].push_back({H[i][1]+1 , L[i]}) ; 
        adj[H[i][1]+1].push_back({H[i][0]+1, L[i]}) ; 
        zez|=!L[i] ; 
    }
    dfz(1 , 1 , 0) ; 
    dfs(1 , 1 , 0) ; 
    if(ans==10000000000000) ans = -1 ; 
    if(!k&&zez)ans = 1 ; 
    return ans ; 
}
