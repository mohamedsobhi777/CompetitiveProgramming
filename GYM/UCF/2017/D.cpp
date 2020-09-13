#include<bits/stdc++.h>

/*
#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")*/

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 5e5 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n, m; 

int a[N] ;

int d[200 * 200 + 4] ;

int num(int x , int y){
        return x * 200 + y ;

}

vector<int> adj[N] ; 

I edge(int u , int v , int x ,int y){
        int A = num(u , v) ; 
        int B = num(x , y) ; 
        adj[A].push_back(B) ; 
}

int bfs(int x , int y){
        queue<int> qu ; 
        for(int i = 0 ;i < 200 * 200 ; i++ ){
                d[i] = inf ; 
        }
        qu.push(x) ; 
        d[x] = 0 ; 
        while(qu.size()){
                int fr = qu.front() ; 
                qu.pop() ; 
                for(auto u : adj[fr]){
                        if(d[fr] + 1 < d[u]){
                                d[u] = d[fr] + 1 ; 
                                qu.push(u) ; 
                        }
                }
        }
        return d[y] ; 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
       // freopen("in.in" , "r" , stdin) ;

        int t; 
        cin >> t; 
        while( t-- ){
                int n; 
                cin >> n;
                for(int i = 0 ;i < 200 * 200 ;i ++){
                        adj[i].clear() ; 
                }
                for(int i = 0 ;i< n; i ++){
                        cin >> a[i] ; 
                }
                
                for(int i = 0 ;i < n; i++){
                        for(int j = 0 ;j < a[i] ;j ++){
                                int u = num(i , j) ; 
                                int v = num(i , j+1) ; 
                                edge(i , j , i , j + 1) ;
                                edge(i , j + 1, i , j);  
                        }
                        if(i){
                                for(int j = 0 ;j <= max(a[i] , a[i-1]) ; j++){
                                        int u = num(i , j) ; 
                                        int v = num(i -1 , j) ; 
                                        if(a[i] >= j){
                                                edge(i , j , i - 1, (a[i-1]<j?a[i-1]:j) ) ; 
                                        }
                                        if(a[i-1] >= j)
                                                edge(i -1 , (a[i]<j?a[i]:j) , i , j) ; 
                                }

                                edge(i , 0 , i - 1 , a[i - 1]) ;
                                edge(i -1 , a[i-1] , i , 0) ; 


                                if(a[i] >= a[i-1])      
                                        edge(i , a[i] , i - 1 , a[i-1]) ;
                                if(a[i] <= a[i-1])      
                                        edge(i - 1 , a[i-1], i , a[i]) ;

                        }
                }

                int a , b ; 
                int c , d; 
                cin >> a >> b >> c >> d;
                a-- ; c-- ; 
                cout<< bfs(num(a , b) , num(c ,d )) <<"\n" ;
        }

        return 0 ; 
}