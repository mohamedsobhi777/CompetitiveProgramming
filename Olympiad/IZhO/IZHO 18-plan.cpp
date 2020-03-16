#include<bits/stdc++.h> 

using namespace std ; 

const int N = 5e5 + 7 ; 

/*
    idea: break the problem into smaller subproblems 
    we need a path from A to B, avoiding bad nodes as much as we can
    first we need to know for each node the closest bad node to it(let's call it C[node]) which can be done if we run a dijkstra from each bad node simultaneously
    now the problem turns to the following
    find a path from A to B such that the the min of C[x] for each node x on the path is maximum
    one possible way to do that is to process each node after sorting them decresingly by C[i]
    when processing a node, we mark it as good, and look for its good neighbours to link them to it using DSU
    after processing each node, the answer to query {u , v} such that u and v is in the same component is min of all C[i] of nodes processed so far,
    if they are not in the same component we continue processing other nodes, so it make sense that we look for the first time nodes {u , v} were in the same
    component, which is the same as their lca if we root the tree at the last node we conunter, so the answer to query {u , v} = C[lca(u , v)] of the DSU tree


    submission : https://oj.uz/submission/210230


*/

int n , m , k , q ; 
vector<pair<int , int > > adj[N] ;
vector<pair<int , int > > queries ; 


bool good[N] , viz[N];
int root ;
vector<int> qrs[N] , tree[N]; 

// this is DSU
struct DSU{
    vector<int> fat ; 
    void init(int n){
        fat.resize(n + 1 ) ; 
        for(int i = 0 ; i < n ; i++){
            fat[i] = i ; 
        }
    }
    int fin(int x){
        return fat[x] = (fat[x]==x?x:fin(fat[x])) ; 
    }
    void unio(int a, int b){
        int aa = fin(a) ;
        int bb = fin(b) ; 
        if(aa!=bb){
            fat[aa] = bb  ;
        }
    }
} d1 , d2;

//using dijkstra to calculate the closest bad node 
priority_queue<pair<int , int > > Q; 
int C[N]; 

void dijkstra(){
    while(Q.size()){
        int dst = -Q.top().first ; 
        int node = Q.top().second ;
        Q.pop()  ;
        for(auto u : adj[node]){
            if(C[u.first]==-1 || dst + u.second < C[u.first]){
                C[u.first] = dst + u.second ; 
                Q.push({-C[u.first] , u.first}) ; 
            }
        }
    }
}
// 

vector<pair<int , int > > node ; 
    
map<pair<int , int > , bool > mp ; 
map<pair<int , int > , int > sol ; 


void dfs_lca(int x , int p ){
    viz[x] = 1 ; 
    for(auto u : qrs[x]){
        if(viz[u] && mp[{x ,u}]==0){
            int lca = d2.fin(u) ; 
            mp[{x , u}] = mp[{u , x}] = 1 ; 
            sol[{x , u}] = sol[{u , x}] = C[lca] ;
        }
    }
    for(auto u : tree[x]){
        if(u==p)
            continue ; 
        dfs_lca(u ,x ) ; 
        d2.unio(u , x) ; 
    }
}

int main(){
    memset(C , -1 , sizeof C) ; 
    freopen("in.in" , "r" , stdin) ; 
    cin>>n >>m; 
    for(int i = 0 ; i < m ; i++){
        int a , b, c; 
        cin>>a>>b>>c ; 
        adj[a].push_back({b , c}) ; 
        adj[b].push_back({a , c}) ; 
    }
    
    //calculating the distance between each node to the nearest bad node
    cin>>k ; 
    for(int i = 0 ; i <k ; i++){
        int a ; cin>>a ; 
        C[a] =0 ;
        Q.push({0 , a}) ; 
    }
    dijkstra() ; 
    //
    
    cin>>q ; 
    for(int i = 0 ; i < q ; i++){
        int a, b ; 
        cin>>a>>b ; 
        queries.push_back({a ,b });
        qrs[a].push_back(b) ; 
        qrs[b].push_back(a) ; 
    }

    //sorting the nodes decresingly by C[i]
    for(int i = 1 ; i <=n ; i++){   
        node.push_back({-C[i] , i}) ; 
    }
    sort(node.begin() , node.end()) ;
    
    //process each node, mark it as good, and link it to its good neighbours
    d1.init(N) ; 
    for(auto u : node){
        int nod = u.second ; 
        int home = d1.fin(nod) ;
        good[nod] = 1 ;  

        for(auto it : adj[nod]){
            if(good[it.first]){
                int fn = d1.fin(it.first) ; 
                if(fn!=home){
                    if(C[fn] < C[home])d1.unio(home , fn) ; 
                    else  d1.unio(fn , home) ;
                    //make a tree of the dsu components 
                    tree[fn].push_back(home) ; 
                    tree[home].push_back(fn) ;
                }

            }
        }
        root = nod ; 
    }

    //calculate the LCA for each query using DSU offline
    d2.init(N) ; 
    dfs_lca(root , root) ; 

    //printing the answer
    for(int i = 0 ; i < q ; i++){
        cout<<sol[queries[i]]<<"\n";
    }
    return 0 ; 
}
