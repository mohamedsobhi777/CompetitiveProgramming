


#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n; 

struct aho_node{
       int link = -1 , dlink = 0 ;
       int nxt[26] ; 
       int leaf_count = 0 ; 
       int Min = 1e9 ; 
       aho_node(){ memset(nxt, 0, sizeof nxt) ; }     
       int &operator[](char c){ return nxt[c-'a'] ; }
} ;

void insert_string(vector<aho_node>&aho, string x, int ix){
       int cur = 0 ; 
       for(auto u : x){
              if( !aho[cur][u] ){
                     aho[cur][u] = (int) aho.size() ; 
                     aho.push_back(aho_node()) ; 
              }
              cur = aho[cur][u] ;
       }
       aho[cur].leaf_count ++ ; 
       aho[cur].Min = min(aho[cur].Min, ix) ; 
}

void push_links(vector<aho_node> &aho){
       queue<int> qu ; 

       aho[0].link = 0 ; 
       for(int i = 'a' ;i <= 'z' ; ++ i){
              if(aho[0][i]){
                     aho[ aho[0][i] ].link = 0 ; 
                     qu.push(aho[0][i]) ; 
              }
       }

       while(qu.size()){
              int fr = qu.front() ; 
              qu.pop() ; 
              for(int i = 'a' ;i <= 'z' ; ++ i){
                     int kid = aho[fr][i] ; 
                     if(kid){
                            int par = aho[fr].link ; 
                            while(par && !aho[par][i]) par = aho[par].link ; 
                            par = aho[par][i] ; 
                            aho[kid].link = par ;
                            aho[kid].dlink = (aho[par].leaf_count?par:aho[ par ].dlink) ; 
                            aho[kid].Min = min(aho[kid].Min, aho[ aho[kid].dlink ].Min ) ;
                            qu.push(kid) ;  
                     }
              }
       }

}

int find_string(vector<aho_node> &aho, string &q){
       // returns the index of first string x, s.t. x is a substring of q
       int cur = 0 ; 
       int ret = 1e9 ; 
       for(auto u : q){
              while(cur && !aho[cur][u]){
                     cur = aho[cur].link; 
              } 
              cur = aho[cur][u] ; 
              ret = min({ret, aho[cur].Min, aho[ aho[cur].dlink ].Min }) ;
       }
       return ret ;
}

vector<aho_node> aho_add(1) ; 


int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
#ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
#endif
       
       cin >> n; 
       vector<pair<int, string> > vp ; 

       for(int i = 0 ;i < n; ++ i){
              int t; string st ; cin >> t >> st ; 
              if(t){
                     vp.push_back({i, st}) ; 
              }else{
                     insert_string(aho_add, st, i) ; 
              }
       }

       push_links(aho_add) ; 

       for(auto u : vp){
              cout << (find_string(aho_add, u.second) < u.first ? "YES" : "NO") <<"\n" ;
       }

       return 0;
}
