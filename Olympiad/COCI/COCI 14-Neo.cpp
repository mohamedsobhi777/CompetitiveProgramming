  /*
        Problem : COCI 14-Neo
        link : https://dmoj.ca/problem/coci14c6p5
        handle: mohamedsobhi777

        solution : 

        consider the following (3 * 3) matrix
        a b c
        d e f 
        g h i 

        Let A = a - b 
            B = d - e
            C = g - h

        |a b|  this matrix is super cool if A<=B
        |d e| 
        
        |d e| this matrix is super cool if B<=C
        |g h|   

        |a b|  this matrix is super cool if A<=B and B<=C and A<=C (but the third condition is not necessary) 
        |d e|   because if A<=B and B<=C then A must be <=C
        |g h|
        
        let's define a new matrix mat[][]
                mat[i][j] = 1 if the (2 * 2) submatrix having cell(i, j) is its top left cell is super cool

        now the answer is area of adding one row and one column to the maximum rectangular submatrix with all ones 
        
        O(n*m)
*/
#include<bits/stdc++.h>

using namespace std ; 

const int N =1e3  + 7 ; 

int a[N][N] , mat[N][N] ; 
int n , m ; 
int aux[N]; 

stack<pair<int , int> > st ; 
int ix ; 

int poop(int pos){
        ix = st.top().first ; 
        int val = st.top().second ; 
        st.pop() ;
        return (pos - ix + 1 ) * (val + 1) ; 
        
}

int histo(){
        int ret = 0 ;
        for(int i = 0 ; i < m ; i++){
                bool mx = 0 ; 
                while(st.size() && aux[i] < st.top().second ){
                        ret = max(ret , poop(i) ) ;                       
                        mx = 1 ; 
                }
                if(!mx)
                        st.push({i , aux[i]});
                else 
                        st.push({ix, aux[i]});
        }       
        while(st.size())
                ret = max(ret , poop(m)) ;
        return ret ; 
}


int solve(){
        int ret = 0 ; 
        for(int i = 0 ;i +1 < n ;i++){
                for(int j = 0 ;j +1 < m ;j ++){
                        aux[j] +=(mat[i][j]?1:-aux[j]) ; 
                }
                ret = max(ret , histo()) ; 
        }
        return ret ; 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 

        cin>>n>>m ; 
        for(int i = 0 ; i < n; i++){
                for(int j = 0 ; j< m ;j++){
                        cin>>a[i][j] ; 
                        if(i && j ){
                                bool c1 = (a[i-1][j-1] - a[i-1][j] <= a[i][j-1] - a[i][j]) ; 
                                bool c2 = (a[i-1][j-1] - a[i][j-1] <=a[i-1][j] - a[i][j]) ; 
                                mat[i-1][j-1] = ( c1 && c2 ) ; 
                        }
                }
        }
        cout<<solve(); 
        return 0; 
}
