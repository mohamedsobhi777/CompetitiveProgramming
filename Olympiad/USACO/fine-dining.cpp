#include<bits/stdc++.h> 
 
using namespace std ;

const int N = 1e6 + 7 , mod = 998244353; 

int n , m  , k ; 
vector<pair<int , int > > adj[N] ;
long long d[N] , d2[N] ;  
int ans[N] ; 

void dijkstra1()
{
    memset(d , -1 , sizeof d) ; 
    priority_queue<pair<long long , int > > q ; 
    d[n] = 0;
    q.push({0 , n});
    while(q.size())
    {
        long long dist = -q.top().first ; 
        int node = q.top() . second ; 
        q.pop() ; 
        for(int u= 0 ; u < adj[node].size() ; u++)
        {
            if(d[adj[node][u].first]==-1 || dist + adj[node][u].second < d[adj[node][u].first])
            {
                d[adj[node][u].first] = dist + adj[node][u].second ; 
                q.push({-d[adj[node][u].first] , adj[node][u].first });
            }
        }
    }
}

void dijkstra2()
{
    for(int i = 0 ; i<N; i++)
        d2[i] = 1e9 ; 
    priority_queue<pair<long long , int > > q ; 
    for(int i= 0 ; i< k ; i++)
    {
        int a , b  ; 
        cin>>a>>b ; 
        d2[a] = d[a] - b ; 
        q.push({-d2[a],a});
    }
    while(q.size())
    {
        long long dist = -q.top().first ; 
        int node = q.top() . second ; 
        q.pop() ; 
        for(int  u = 0 ; u< adj[node].size() ; u++)
        {
            if(d2[adj[node][u].first]==-1e9 || dist + adj[node][u].second < d2[adj[node][u].first])
            {
                d2[adj[node][u].first] = dist + adj[node][u].second; 
                q.push({-d2[adj[node][u].first] , adj[node][u].first}) ; 
            }
        }
    }
}

int main() 
{
    freopen("dining.in" , "r",  stdin) ;
    freopen("dining.out" , "w" , stdout) ;
    cin>>n>>m>>k ; 
    for(int i = 0 ; i < m ;i++)
    {
        int a , b, c ; 
        cin>>a>>b>>c ; 
        adj[a].push_back({ b , c}) ; 
        adj[b].push_back({a , c }) ; 
    }
    dijkstra1() ;
    dijkstra2() ; 
    for(int i = 1 ; i<n ; i++)
        cout<<(d2[i]-d[i]<=0)<<"\n" ; 
    return 0 ;  
}
