/*
        Problem : CEOI 09-Logs
        
        Solution : 
                for each row i, we do the following 
                        for each j in the ith row, let a[j] be the maximum number of contigous ones in the jth column ending at the cell (i,j)
                        we sort a in increasing order,now we need to find the maximum area of a histogram in the array a

                        using quick sort : O(N * M * log M) 
                        using count sort : (N * N) 
                        
                        My solution uses count sort

*/
#include<bits/stdc++.h>

using namespace std ; 

const int N = 15000  + 28 ; 
const int M = 1500 + 7 ; 
bool mat[N][M] ; 
int n , m ; 

int solve(){
        int ret = 0 ; 
        vector<int> acc(m+1 , 0) ; 
        for(int i = 0 ;i < n ;i++){
                vector<int> csr(n+1 , 0) ; 
                for(int j = 0 ;j  < m ;j ++){
                        acc[j] +=(mat[i][j]?1:-acc[j]) ;
                        csr[acc[j]] ++ ; 
                }
                int ind = 0 ; 
                for(int j = n ;j ; j--){
                        ind+=csr[j] ; 
                        ret = max(ret , ind * j ) ; 
                } 
        }
        return ret ; 
}

int main(){

        cin>>n>>m ; 

        for(int i = 0 ;i < n;i++){
                string s ; 
                cin>>s ; 
                for(int j = 0 ;j < m; j++){
                        mat[i][j] = s[j] - '0' ; 
                }
        }
        cout<< solve() ; 
        return 0; 
}
