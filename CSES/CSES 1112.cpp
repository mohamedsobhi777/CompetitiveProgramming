/*
        Problem : 
        Problem Link : 

        Solution : same as editorial

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7 , mod = 1e9 + 7 ;

int n , m; 
string s ;
int dp[N][101][2] ; 
int F[N] ; 


int f(int pre , int c){
        while(pre && s[pre]-'A' != c)pre = F[pre -1 ] ; 
        if(s[pre]-'A' == c)pre++;
        return pre ;
}

void pre(){
        for( int i =1 ;i < m ;i++){
                F[i] = F[i-1] ; 
                while(F[i] && s[ F[i] ] != s[i] )
                        F[i]= F[ F[i] - 1 ] ;
                if(s[ F[i] ] == s[i])
                        F[i] ++ ;
        }       
}

int solve(int i , int fail, bool k){
        
        if(fail == m)k =1 ;
        if(i == n)return k  ; 

        if(dp[i][fail][k]!= -1)
                return dp[i][fail][k] ; 
        
        int ret = 0 ; 
        for(int j = 0 ;j < 26 ;j ++){
                if(k){
                        ret+=solve(i+1 , fail , k) ; 
                }
                else 
                        ret+=solve(i+1 , f(fail , j ) , k ) ;
                ret%=mod ; 
        }
        return dp[i][fail][k] =  ret ; 
}       

int main()
{
        memset(dp , -1 , sizeof dp) ; 
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>s ;     
        m = s.size() ; 
        if(n < (int) s.size()){
                cout<<"0" ;
                return 0; 
        }
        pre() ; 
        cout<< solve(0 , 0 , 0 ) ; 
        return 0;
}
