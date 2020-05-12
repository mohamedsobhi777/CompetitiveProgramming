/*
        Problem : USACO 20jan-threesum-gold
        link : http://www.usaco.org/index.php?page=viewproblem2&cpid=994
        
        
        solution : 

                Note : the solution is more complicated than the editorial 

                a triplet (a , b , c) is good if A[a] + A[b] + A[c] = 0 s

                we need to calc the num of A[i] + A[j] + A[k] = 0
                let's define f[idx][suf] = number of pairs (c  , d) such that l and r are in the suffix (suf suf+1....N) and A[c] + A[d] + A[idx] = 0 


                for some query [L , R] , we now that ans[L,R] = ans[L, R-1] + (number of triplets such that R is the third number in the triplet) 

                        so we need to efficiently calculate for some index i, the number of triplets having R as their last element and their
                        first element is in range[st , R] let's call them add[st][R]

                        then add[st][R] = f[R][st] - f[R][R] - (the number of pairs (c ,d ) such that c < R and d > R and A[c] + A[d] + A[R] = 0 )
                        we can calculate that sum online using a prefix array

                idea with clearer words : 
                        add[st][R] = the number of good triplets (a , b , R)   
                        suf_pairs[x] = number of pairs (p1 , p2) such that p1 and p2 in [x , N] and A[p1] + A[p2] = -A[R]

                        add[st][R] = suf_pairs[st] - suf_pairs[R] 
                        but now add[st][R] equals the number of triplets (a , b , R) such that a in [st , R] , so we need to subtract the number of triplets 
                                where b > R which euqals the number of pairs (a , b) such that a < R and b > R and A[a] + A[b] = -A[R]


*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 5000 + 7 ;

int n , m ; 
int A[N] ; 
vector<long long> ans[N] ; 
int fft[N][N] ; 
const int offset = 2e6 +100 ; 
const int sz = 6e6 +100 ; 
int cnt[sz] , cnt2[sz] ; 

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 

        freopen("threesum.in" , "r" ,stdin) ; 
        freopen("threesum.out" , "w" , stdout) ; 
        for(int i = 0 ;i < N ;i++){
                ans[i].resize(i+100) ; 
        }
        cin>>n>>m ; 

        for(int i = 1 ;i <= n ;i++){
                cin>>A[i] ; 
        }

        for(int i = n ;i>=1 ;i--){
                for(int j = i +1 ; j<=n ;j++){
                        cnt[A[i] + A[j] + offset] ++ ; 
                }
                for(int j = 1 ;j <=n ;j++){
                        fft[j][i] = cnt[offset-A[j]] ; 
                }
        }

        for(int i = 1 ;i<=n;i++){
                cnt2[A[i]+ offset]++  ; 
        }

        for(int i = 1; i<= n;i++){
                long long coun = 0 ;
                for(int j = i ; j ;j--){
                        int ret = fft[i][j] - fft[i][i] ; 
                        if(j < i )
                                coun += cnt2[ offset -A[i] - A[j] ] ; 
                        ret -= coun ;
                        ans[i][j] = ret + ans[i-1][j]  ; 

                }
                cnt2[A[i] + offset] -- ; 

        }

        for(int i =  0 ; i< m ;i++){
                int a , b ; 
                cin>>a>>b ; 
                cout<< ans[b][a]<<"\n" ; 
        }

        return 0 ; 
}
