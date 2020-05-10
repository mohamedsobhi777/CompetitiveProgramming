/*
        Problem : Double-row (dwu)
        link : https://szkopul.edu.pl/problemset/problem/cB5m-M5ddsFOWLds2CwcYKge/site/

        Solution : https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/POI-05-Double_Row.txt

*/

#include<bits/stdc++.h>

using namespace std; 

const int N = 1e5 + 7 ; 

int n; 

int nxt[N] , in[N] ; 
int a[N] , b[N] ; 
int vis[N] ; 
int loc[N] ; 

int val[N] ; 

vector<int> adj[N] ; 

int t = 1 ; 

int dfs(int x , int p , int col ){
        int ret = 0 ; 
        
        if(vis[x] == t) return 0 ; 
        vis[x] = t ;  
        
        if(x <=n){
                ret += col ;

        }else{
                ret += !col; 
        }
        for(auto u : adj[x]){
                if( u == p ) continue ; 
                ret += dfs(u , x , 1 - col ) ; 
        }
        return ret ; 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        
        cin>>n ;

        for(int i = 1 ;i <= n * 2  ;i ++){
                cin>>a[i] ; 
                if(loc[a[i]]){
                        adj[ loc[a[i]] ] .push_back(i) ; 
                        adj[i].push_back(loc[a[i]]) ; 
                }

                loc[a[i]] = i ; 

                if(i <= n){
                        adj[i].push_back(i + n) ; 
                        adj[i+n].push_back(i) ; 
                }
        }

        int ans = 0 ; 

        for(int i = 1 ; i <= n; i++){
                if(vis[i]) continue ; 
                t++ ; 
                int x = dfs(i , i , 0) ; 
                t++ ; 
                int y = dfs(i , i , 1) ; 
                ans += min(x , y) /2 ; 
        }
    
        cout<< ans ; 
        return 0 ; 
}
