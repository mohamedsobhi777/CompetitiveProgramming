/*
    Problem : COCI 18-pictionary
    link : https://oj.uz/problem/view/COCI18_pictionary
    handle : mohamedsobhi777

    observarion 1 : we don't have to add all the edges
    observation 2 : we only add edges (x , k * x)  { m>=x>=1 }
    
    solution : 
        we iterate from m to 1, in each iteration we connect edges i, 2 * i , 3 *i, so we have at most (N log N)edge
        after each iteration we want to check for the cities that became reachable after that iteration, the answer for them is m - i +1
        O(N * (Q + logN ) )

    optimization: 
        a trick invloving dsu, is to get the lca, of 2 nodes in the dsu tree
        the lca of two nodes in the dsu trees equals, the first node that after adding it, the 2 nodes become reachable
        O(N log N)
*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e5 + 7 ; 

int n , m , k ; 
int A[N] , B[N] ; 
int ans[N] , vis[N]; 

vector<int> qrs[N] , tree[N] ; 
map<pair<int , int > , int> anss ; 

struct DSU{
    vector<int> fat ; 
    bool build = 0 ; 
    void init(int n , bool ok = 0){
        fat.resize(n) ; 
        build = ok ; 
        for(int i = 0 ; i < n; i++){
            fat[i] = i ;
        }
    }
    int fin(int x){
        return fat[x] = (fat[x]==x?x:fin(fat[x]));
    }    
    void unio(int a , int b){
        int aa = fin(a) ; 
        int bb = fin(b) ; 
        if(aa!=bb){
            fat[aa] = bb ; 
            if(build){
                tree[aa].push_back(bb) ; 
                tree[bb].push_back(aa) ;                 
            }
        }
    }
} d , lca;

int dfs(int x , int p){
    vis[x] =1 ; 
    for(auto u : qrs[x]){
        if(vis[u]){
            anss[{x , u}] = anss[{u , x}] = lca.fin(u) ; 
        }
    }
    for(auto u : tree[x]){
        if(u==p)continue ; 
        dfs(u , x) ;
        lca.unio(u , x) ; 
    }
}

int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
    freopen("in.in" ,"r" , stdin) ; 
    cin>>n>>m>>k ; 
    d.init(n+7 ,1 ) ; 
    lca.init(n+7) ; 
    for(int i =0 ; i < k ;i++){
        int l , r; 
        cin>>A[i] >>B[i] ; 
        qrs[A[i]].push_back(B[i]) ; 
        qrs[B[i]].push_back(A[i]) ; 
    }
    for(int i =m ; i ;i--){
        for(int j = i  + i ;j <=n ;j+=i){
            d.unio(j , i) ; 
        }
    }
    dfs(1 , 1) ; 
    for(int i = 0 ;i < k ;i++){
        cout<< m - anss[{A[i] , B[i]}] +1 <<"\n" ; 
    }
    return 0 ; 
}
