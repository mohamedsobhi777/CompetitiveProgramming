#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;

int n, m, k ;
string s1, s2, vir ; 

int fail[N] ; 
int dp[N][N][N] ; 

void kmp(string x){
       int j = 0 ; 
       for(int i = 1 ;i < (int) x.size() ; ++ i){
              while(j && x[i] != x[j] ) j = fail[j-1] ; 
              j += (x[i] == x[j]) ; 
              fail[i] = j ; 
       }
}

int nxt(int ofail, char c){
       while(ofail && vir[ofail] != c){
              ofail = fail[ofail-1] ; 
       }
       return ofail + (c == vir[ofail]) ; 
}

int solve(int i, int j, int v){
       if(i == n || j == m)return 0 ; 
       if(~dp[i][j][v])return dp[i][j][v] ; 
       int ret = 0 ; 
       if(s1[i] == s2[j]){
              int nv = nxt(v, s1[i]) ; 
              if(nv != k){
                     ret = max(ret, solve(i+1, j+1, nv) + 1) ; 
              }
       }
       ret = max(ret, solve(i+1, j, v) ) ;
       ret = max(ret, solve(i, j+1, v)) ; 
       return dp[i][j][v] = ret ; 
}


void build(int i, int j, int v){
       if(i == n || j == m)return ; 
       int ret = 0 ; 
       if(s1[i] == s2[j]){
              int nv = nxt(v, s1[i]) ; 
              if(nv != k && solve(i,j,v) == solve(i+1,j+1,nv) + 1 ){
                     cout << s1[i] ; 
                     build(i+1,j+1,nv) ; 
                     return ;
              }
       }
       if(solve(i,j,v) == solve(i+1,j,v)){
              build(i+1,j,v) ; 
       }else if(solve(i,j,v) == solve(i,j+1, v)){
              build(i,j+1, v) ; 
       }
}

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
#ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
#endif
       memset(dp, -1, sizeof dp) ; 
       cin >> s1 >> s2 >> vir ; 
       n = (int) s1.size() ; 
       m = (int) s2.size() ; 
       k = (int) vir.size() ; 

       kmp(vir) ; 

       if(solve(0, 0, 0)){
              build (0, 0, 0) ; 
       }else{
              cout << 0 ; 
       }
       return 0;
}
