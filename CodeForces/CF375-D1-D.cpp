/*
    Problem : CF375-D1-D    
    link : https://codeforces.com/contest/375/problem/D

    Solution:
        the solution uses DSU on trees, instead of storing the frequency of the colors (freq1) , we will store the frequency of the frequency of the colors(freq2), 
        now with some data structure we can do the query count(x , y) : number of colors with freq1 in interval [l,r] 
        I used BIT to do the queries.
        O(N log^2(N)) 
*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e5 + 7 ; 

int n , m; 
int col[N]  ; 
int sz[N] ; 
int anss[N] , ans[N] ;
vector<int> adj[N] ; 
vector<pair<int , int> >  qu[N] ; 
int fr[N] , ls[N] , ver[N*2] ; 
int t = 1; 

struct bit{
    vector<int> arr ; 
    void init(int sz){
        arr.resize(sz) ; 
        fill(arr.begin() , arr.end() , 0) ; 
    }
    void add(int i , int val){
        i++ ; 
        for(;i< N ;i += i&(-i) ){
            arr[i]+=val ; 
        }
    }
    int get(int i){
        if(!i)return 0 ; 
        int ret = 0 ; 
        for(;i;i-=i&-i){
            ret+=arr[i] ;
        }
        return ret ; 
    }
    int calc(int l , int r){
        return get(r) - get(l-1) ; 
    }

    void add_color(int x , int val){
        int lcol = anss[x] ; 
        anss[x] +=val ;
        int ncol = anss[x] ; 
        add(lcol, -1) ;
        add(ncol , 1) ; 
    }
    int get_greater(int x){
        x++ ; 
        return calc(x , 100000) ;
    }
}bt; 

int dfz(int x , int p){
    int ret = 1 ;
    ver[t] = x ; 
    fr[x] = t++ ; 
    for(auto u : adj[x]){
        if(u==p)continue ; 
        ret+=dfz(u , x) ; 
    }
    ls[x] = t++ ; 
    return sz[x] = ret ; 
}

int dfs(int x , int p , bool keep){
    int big = 0 ; 
    for(auto u : adj[x]){
        if(u==p)continue ; 
        if(sz[u] > sz[big]){
            big = u ; 
        }
    }
    for(auto u: adj[x]){
        if(u== p || u==big)continue ; 
        dfs(u , x, 0) ; 
    }
    if(big){
        dfs(big , x , 1) ; 
    }
    bt.add_color(col[x] ,1 ); 
    for(auto u : adj[x]){
        if(u== big || u== p)continue ; 
        for(int j = fr[u] ; j < ls[u] ;j ++){
            if(ver[j]){
                bt.add_color(col[ver[j]] , 1) ; 
            }
        }
    }
    for(auto u : qu[x]){
        int tar  = u.first ; 
        int ix = u.second ; 
        ans[ix] = bt.get_greater(tar) ; 
    }
    if(!keep){
        for(int j = fr[x] ; j < ls[x] ;j ++){
            if(ver[j]){
                bt.add_color(col[ver[j]] , -1) ;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0); 
    cin>>n>>m ; 
    bt.init(100005) ; 
    for(int i = 1 ;i <=n;i++){
        cin>>col[i] ; 
    }
    for(int i=  0;i < n-1 ;i++){
        int a , b; 
        cin>>a>>b ; 
        adj[a].push_back(b); 
        adj[b].push_back(a) ;
    }
    for(int i =0 ;i < m;i++){
        int a ,  b; 
        cin>>a>>b ; 
        qu[a].push_back({b , i}) ; 
    }
    dfz(1 , 1) ;
    dfs(1 , 1, 0) ;     
    for(int i = 0  ; i < m;i++){
        cout<<ans[i] <<"\n" ; 
    }
    return 0 ; 
}
