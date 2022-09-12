


#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n; 

struct aho_node{
       int link = -1 , dlink = 0 ;
       int nxt[62] ; 
       int leaf_count = 0 ; 
       int Min = 1e9 ; 
       vector<int> indices ;
       aho_node(){ memset(nxt, 0, sizeof nxt) ; }     
       int &operator[](char c){
              if(c>='a' && c <= 'z')return nxt[c - 'a'] ; 
              else if(c >= 'A' && c <= 'Z')return nxt[26 + c - 'A'] ; 
              else return nxt[52 + c - '0'] ;
       }
       bool dp = 0 ; 
} ;

int nxt(vector<aho_node> &aho, int x, char c){
       while(x && !aho[x][c]) x = aho[x].link ;
       return aho[x][c] ; 
}

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
       aho[cur].indices.push_back(ix) ; 
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

vector<int> find_all_strings_in_x(vector<aho_node> &aho, string &q){
       for(auto &u : aho)u.dp = 0 ; 
       int cur = 0 ;        
       for(auto u : q){
              cur = nxt(aho, cur, u) ; 
              aho[cur].dp = 1; 
       }      
       for(int i = (int) aho.size() - 1 ; ~i ; -- i){
              aho[ aho[cur].dlink ].dp |= aho[i].dp ; 
       }
       vector<int> ret ; 
       for(auto &u : aho){
              if(u.dp){
                     ret.insert(ret.end(), u.indices.begin(), u.indices.end() ) ;
              }
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
       string st ; cin >> st ; 
       cin >> n; 

       for(int i = 0 ;i < n; ++ i){
              string x; cin >> x ;
              insert_string(aho_add, x, i) ; 
       }

       push_links(aho_add) ; 

       vector<int> found_indices = find_all_strings_in_x(aho_add, st) ; 

       sort(found_indices.begin(), found_indices.end()) ; 

       for(int i = 0 ;i < n; ++ i){
              if(find(found_indices.begin(), found_indices.end(), i) != found_indices.end()){
                     cout <<"Y\n" ; 
              }else{
                     cout <<"N\n" ;
              }
       }

       
       return 0;
}
