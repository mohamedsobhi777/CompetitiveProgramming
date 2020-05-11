/*
        Problem : USACO 18dec-dining
        link : http://usaco.org/index.php?page=viewproblem2&cpid=861
        handle : mohamedsobhi777

        Solution : 
                
                we will calculate two types of distance, 
                        1- distance between N and all the other ndoes (using dijkstra) 
                        2- distance from the K special nodes to all the other nodes, but we set the initial distance for some special node k to be 
                                (distance from k to N) - the yumminess of k
                Proof: 
                        suppose for some node s, its distance to N is d, and its distance to N after dining is D
                                we want to check if K - k <= yumminess
                                 --> K - yumminess <= k
                         
*/


#include<bits/stdc++.h>

using namespace std ; 

const int N =1e5 + 7 ; 

long long n , m , k , trip = 1e15; 
long long d[N]  , d2[N] ; 
vector<pair<int  ,int > > adj[N] ;

void dijkstra( vector<pair<long long , long long > > sources ){
        
        priority_queue<pair<long long , long long > > q ; 
        
        for(int i = 0; i< N ; i++){
                d[i] = 1e15 ; 
        }        
        
        for(auto u : sources){
                q.push({-u.second , u.first}) ; 
                d[u.first] = u.second ; 
        }

        while(q.size()){
                pair<long long ,long long > pr = q.top() ; 
                q.pop() ; 
                long long node = pr.second ; 
                long long dst = -pr.first ;

                for(auto u : adj[node]){
                        if(dst + u.second < d[u.first]){
                                d[u.first] = dst + u.second ; 
                                q.push({-d[u.first] , u.first}) ; 

                        }

                }
        }
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 
        freopen("dining.in" ,"r" , stdin) ; 
        freopen("dining.out" ,"w" , stdout) ; 

        cin>>n>>m>>k ; 

        for(int i = 0 ; i < m; i ++){
                int a ,b , c; 
                cin>>a>>b>>c ; 
                adj[a].push_back({b , c}) ; 
                adj[b].push_back({a , c}) ; 
        }
        dijkstra( { {n , 0} }) ;
        
        vector<pair<long long ,long long > > srcs ;  
        for(int i = 0 ; i < k ;i++){    
                int a , b ; 
                cin>>a>> b; 
                srcs.push_back({a , d[a] - b }) ; 
                trip = min(trip , d[a]) ; 
        }
        for(int i = 0 ;i < N ;i++){
                d2[i] = d[i] ; 
        }
        dijkstra(srcs) ;

        for(int i =1 ;i <n ;i++){
                cout<<(d[i] <= d2[i] ) <<"\n" ; 
        }
        return 0 ;
}
