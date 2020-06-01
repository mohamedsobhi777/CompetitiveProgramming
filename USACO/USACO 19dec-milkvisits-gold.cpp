/*

        Problem : USACO 19dec-milkvisits-gold
        Problem Link : http://usaco.org/index.php?page=viewproblem2&cpid=970
        handle : mohamedsobhi777

        Solution : 
                we use a presistent segment tree, each node keeps the occurances of all nodes on the path [1 , x]
                        ,beacause each node differs from its parent in only one occurence of a value our updates work

                        now for queries there is 2 cases for a query (u , v , k)  (depth of u is lower than depth of v)
                        let L be lca(u , v) 
                        
                        case 1: 
                                L = u, then the number of occurences of k between u and v equals 
                                        vals[1 , v] - vals[1 ,  parent[u] ]

                        case 2 :
                                L != u , L != v
                                        the answer is 
                                                vals[1 , v] + vals[1 , u] - vals[1 , L] - vals[1 , parent[L] ]
                we print 1 if the answer is positive
        O(M log N)
*/


#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e5 + 7 ; 

int n , k ; 
vector<int> adj[N] ; 
int up[N][28] ; 
int a[N] ; 

struct node
{
    node *l , *r;
    int sum;
    node(int val) : l(nullptr) , r(nullptr) ,sum(val) {}
    node(node *l , node *r) : l(l) , r(r) , sum(0)
    {
        if(l)sum+=l->sum;
        if(r)sum+=r->sum;
    }
};

node* build(int l , int r)
{
    if(l==r)return new node (0);
    int mid = (l+r)/2;
    return new node( build(l , mid) , build(mid+1,r) );
}

int sum(node* nod , int L , int R , int l , int r)
{
    if(l>R||r<L)return 0;
    if(l<=L&&r>=R)return nod->sum;
    int mid = (L+R)/2;
    return sum(nod->l , L , mid, l , r)
          +sum(nod->r , mid+1 , R , l , r);
}
node* update(node* nod , int L , int R , int ind , int val)
{
    if(L==R)return new node(val + nod -> sum );
    int mid = (L+R)/2;
    if(ind<=mid)
        return new node(update(nod->l , L , mid, ind , val) , nod->r );
    else return new node(nod->l,update(nod->r , mid+1 , R, ind , val));
}
node* pres[N];
int st[N] , en[N] ;
int t = 1 ; 

void dfs(int x , int p){

        up[x][0] = p ; 

        for(int i =1 ;i < 26 ;i++){
                up[x][i] = up[ up[x][i-1] ][i-1] ; 
        }

        st[x] = t++ ; 
        for(auto u : adj[x]){
                if(u == p) 
                        continue ; 
                pres[u] = update(pres[x] , 1 , n , a[u] , 1 ) ; 
                dfs(u , x) ; 
        }
        en[x] = t++ ; 
}


bool iss(int u , int v){
        return st[v] >= st[u] && en[v] <= en[u] ; 
}

int lca(int u , int v){
        if(iss(u , v)) return u ; 
        if(iss(v , u)) return v ; 

        for(int i = 25 ; i>=0 ;i--){
                if( !iss(up[u][i] , v)){
                        u = up[u][i] ; 
                }
        }
        return up[u][0] ; 
}

int main(){

        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 
        freopen("milkvisits.in" , "r" ,stdin) ; 
        freopen("milkvisits.out" , "w" , stdout) ; 

        cin>> n >> k ; 
        for(int i = 1 ;i<=n ;i++){
                cin>>a[i] ; 
        }
        for(int i = 0 ;i < n-1 ;i++){
                int u , v; 
                cin>>u>>v ; 
                adj[u].push_back(v) ; 
                adj[v].push_back(u) ; 
        }

        pres[0] = build(1 , n) ; 
        pres[1] = update(pres[0] , 1 , n , a[1] , 1) ; 
        dfs(1 , 1) ;
        
        while(k-- ){
                int u , v , x ; 
                cin>> u >> v >> x ; 
                int c = lca(u , v) ; 
                int ans = 0 ; 
                if(c == u){
                        ans = sum(pres[v] , 1 , n , x , x) ; 
                        if(c > 1) ans-=sum(pres[up[c][0]] , 1 , n , x , x) ; 
                }
                else if(c == v){
                        ans = sum(pres[u] , 1 , n , x , x) ; 
                        if(c > 1) ans-= sum(pres[up[c][0]] , 1, n , x , x) ; 
                }
                else{
                        ans = sum(pres[u] , 1 , n, x  , x) + sum(pres[v] , 1 , n  , x, x) ; 
                        if(c > 1){
                                ans-= sum(pres[up[c][0]] , 1, n , x  , x)  + sum(pres[c] , 1 , n , x,x); 
                        }
                }
                cout<< !!ans; 
        }
        return 0 ;
}
