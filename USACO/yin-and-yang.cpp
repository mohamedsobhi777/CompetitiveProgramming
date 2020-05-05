/*
    Problem : Yin and Yang 
    link    : http://www.usaco.org/index.php?page=viewproblem2&cpid=286
    solution : https://www.youtube.com/watch?v=3pk02p1-weU

*/
#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e6 + 7 ; 

int n ; 
vector<pair<int , int > > adj[N] ; 

int sz[N] , dead[N]; 

int dfz(int x , int p){
    sz[x] = 1 ; 
    for(auto u: adj[x]){
        if(u.first== p || dead[u.first] )continue ; 
        sz[x] += dfz(u.first , x) ; 
    }
    return sz[x] ; 
}

int center(int x , int p , int tsz){

    for(auto u : adj[x]){
        if(u.first==p || dead[u.first] )continue ; 
        if(sz[u.first] > tsz /2){
            return center(u.first , x , tsz) ; 
        }
    }
    return x  ;
}

map<int , int > depthSeen ; 

vector<pair<int , int> > paths ; 

void findPath(int x , int p , int h){
    paths.push_back({h , (depthSeen[h] > 0)}) ; 
    depthSeen[h] ++ ; 
    for(auto u : adj[x]){
        if(u.first == p || dead[u.first ])continue ; 
        findPath(u.first , x , h+u.second) ;
    }
    depthSeen[h] -- ; 
}

map<int , long long > pathGood , pathBad  ; 

long long solveTree(int x ){
    long long ret = 0 ; 

    pathGood.clear(); 
    pathBad .clear(); 

    for(auto u : adj[x]){
        if(dead[u.first])continue;
        paths.clear() ; 
        depthSeen.clear() ; 
        findPath(u.first , x , u.second) ; 

        for(auto v : paths){
            if(v.second || v.first == 0) 
                ret+=pathBad[-v.first] ; 
            ret+=pathGood[-v.first] ; 
            if(v.second && !v.first ) ret++ ; 
        }   

        for(auto u : paths){
            if(u.second)
                pathGood[u.first] ++ ; 
            else 
                pathBad[u.first] ++ ;
        }

    }

    return ret  ;
}

long long centro_it(int root , int p ){
    if(dead[root] ) return 0; 
    dfz(root , root) ; 
    int cen = center(root , root , sz[root]) ;
    long long ret = solveTree(cen) ; 
    dead[cen] = 1 ; 
    for(auto u : adj[cen]){
        if(dead[u.first] || u.first == p)continue ; 
        ret += centro_it(u.first , cen) ; 
    }    
    return ret ; 
}

int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
    //freopen("in.in" , "r" , stdin) ; 
    freopen("yinyang.in" , "r"  , stdin) ; 
    freopen("yinyang.out" , "w" , stdout) ; 
    cin>>n; 
    for(int i = 0 ;i < n- 1; i++){
        int a , b , c; 
        cin>>a>>b>>c ; 
        c = 2 * c -1 ; 
        adj[a].push_back({b , c}) ; 
        adj[b].push_back({a , c}) ; 
    }
    
    cout<< centro_it(1 , -1) ; 
    return 0 ;  
}
