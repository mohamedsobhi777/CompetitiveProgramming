/*

    Problem : 
    link    : 

    Solution :

        if a , and b are two nodes on a path of length k (from u to v)
            then a , b make an inversion in either the path (u , v) or the path (v , u) 
            so each pair of nodes on a path of length k contributes the answer by +1
            so a path of length k adds (k * (k-1)) /2 to the answer

            so the final answer is (k *(k-1)) /2 * the number of paths of length k (paths that has k edges) 

            the # of paths of length k can be calculated with centroid decomposition or DSU on tree, I did it with centroid decomposition
            

*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e6 + 7 , mod = 1e9 + 7 ; 

int n , one ; 
vector<int  > adj[N] , tree[N]; 
string s; 
long long ans ;
int prv[N] , sum[N] ; 

int sz[N] , dead[N]; 
int dfz(int x , int p){
    sz[x] = 1 ; 
    for(auto u: adj[x]){
        if(u== p || dead[u] )continue ; 
        sz[x] += dfz(u , x) ; 
    }
    return sz[x] ; 
}
int center(int x , int p , int tsz){
    for(auto u : adj[x]){
        if(u==p || dead[u] )continue ; 
        if(sz[u] > tsz /2){
            return center(u , x , tsz) ; 
        }
    }
    return x  ;
}
int hihi[N] ; 
vector< int > fresh ; 

void add(int x , int p , int d ){
    fresh.push_back(d) ; 
    for(auto u : adj[x]){
        if(u == p || dead[u])continue ; 
        add(u , x , d+1 ) ; 
    }
}

long long k ; 

void calc(int x ){
    vector<int> aux ; 
    for(auto u: adj[x]){
        if(dead[u] ) continue ;
        fresh.clear() ;  
        add(u , x , 1) ; 
        for(auto v : fresh){
            if(v== k)ans++ ; 
            aux.push_back(v) ; 
            if( v >= k) continue ; 
            ans+=hihi[k -v ] ;
        }
        for(auto v  : fresh){
            hihi[v]++ ; 
        }

    }
    for(auto u : aux){
        hihi[u] = 0 ; 
    }
    return ; 
}

vector<int> v ; 

void centro_it(int root , int p ){
    if(dead[root] ) return ; 
    dfz(root , root) ; 
    int cen = center(root , root , sz[root]) ;
    calc(cen) ; 
    dead[cen] = 1 ;     
    
    v.push_back(cen) ; 
    
    for(auto u : adj[cen]){
        if(dead[u] || u == p)continue ; 
        centro_it(u , cen) ; 
    }    
    v.pop_back() ; 
    return; 
}


int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 

    cin>>n>>k; 
    for(int i = 0 ;i < n- 1; i++){
        int a , b; 
        cin>>a>>b ; 
        adj[a].push_back(b) ; 
        adj[b].push_back(a) ; 
    }

    centro_it(1 , -1) ;

    k = ( k * (k+1)) /2 ; 
    cout<<(ans * k) %mod ; 
    return 0 ;  
}
