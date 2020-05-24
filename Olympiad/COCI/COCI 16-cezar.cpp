/*
        Problem : COCI 16-cezar
        link : https://dmoj.ca/problem/coci16c1p3
        handle : mohamedsobhi777

        Editorial's Solution 
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7 ; 

int n;
int o[N] , rep[N]; 
bool vis[N], act[N];
vector<pair<string , int > > vc ; 
vector<int> adj[N] , ord ; 

void no(){
        cout<<"NE\n" ;
        exit(0) ;         
}

void cmp(string a , string b){

        for(int i = 0 ; i< (int) a.size() ; i++){
                if(i == (int) b.size())no() ; 
                int A = a[i] - 'a' ; 
                int B = b[i] - 'a' ; 
                if(A == B)continue ;
                adj[B].push_back(A) ;      

                break ; 
        }
}

void dfs(int x){
        vis[x] = 1 ; 
        for(auto u : adj[x]){
                if(vis[u])continue;
                dfs(u) ;
        }
        ord.push_back(x) ; 
}
bool viz[N] ; 

void go(int x){
        act[x] =1 ; 

        for(auto u: adj[x]){
                if(act[u])no();
                if(viz[u])continue ;  
                go(u) ; 
        }

        act[x] = 0 ;
}

void dag(){
        for(int i = 0 ;i < 26 ; i++){
                go(i);
        }
}

int main()
{
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 

        cin>>n ; 
        vc.resize(n) ; 
        string aux[N] ; 
        for(int i = 0;i < n;i++){
                cin>>aux[i] ; 
        }
        for(int i =0 ; i < n;i++){
                int t ; cin>>t ; 
                vc[i].first = aux[t-1] ; 
        }
        for(int i = 1 ;i < n ;i++){
                for(int j = 0 ;  j< i ;j ++){
                        int sj = vc[j].first.size() ; 
                        int si = vc[i].first.size() ; 
                        if(sj > si){
                                if(vc[j].first.substr(0 , si) == vc[i].first)
                                        no() ; 
                        }
                }
        }
        for(int i = 0 ;i < n-1 ;i++){
                for(int j = i +1 ;j < i+2 ;j++){
                        cmp(vc[i].first , vc[j].first) ; 
                }
        }
        dag() ;
        for(int i = 0 ;i < 26 ;i++){
                if(vis[i])continue ;
                dfs(i) ; 
        }   
        for(int i = 0 ; i < 26 ;i++){
                rep[ord[i]] = i ; 
        }
        cout<<"DA\n" ; 
        for(int i = 0 ;i < 26 ;i++)
                cout<< char('a' + rep[i]) ;
        cout<< endl ; 
        return 0;
}
