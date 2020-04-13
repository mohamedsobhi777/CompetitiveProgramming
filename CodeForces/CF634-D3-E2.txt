
/*
    Problem : codeforces Div3 634 E2. Three Blocks Palindrome (hard version)
    link : https://codeforces.com/contest/1335/problem/E2
    
    the length of the longest palindrome with at most 2 distinct elements of the form AAABBBBBAAA , the first block size equals the last block size
    the answer can be one of the following : 
    1- all values are the same, so we check for the most frequent element
    2- a prefix and a suffix (both of the same length) are A , and the rest of the subsequence equals B

    solution : 

    for each number we store all its indices in an array adj[x] (1 based)

    then for each number A  we try each valid x, such that L = adj[A][x] , R = adj[A][ freq[A] - x ]
    now the problem reduces to finding the most frequent element between L+1 , R-1 (inclusive) 

    and because the range of numbers is small (max value is up to 200)

    we will iterate over all the numbers and use binary search to calculate the answer
    and since the length of all the combined list of indices is n (the length of the array) 
    then the answer will be overall (N log N)

*/

#include <bits/stdc++.h>
 
using namespace std ; 
 
const int N = 1e6 + 7  ; 
int n; 
int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
   // freopen("in.in" , "r" , stdin) ; 
    int t ; 
    cin>>t ; 
    while(t-- ){
        int n ;
        cin>>n ;
        int a[n+1] ; 
        vector<int> occ(222 , 0) ; 
        vector<int> adj[222] ;   
        int ans = 0 ; 
        for(int i = 1 ; i <= n ;i++){
            cin>>a[i ] ;
            occ[a[i]] ++ ; 
            adj[a[i]].push_back(i) ; 
        }
        for(int i = 0 ;i < 222 ; i++){
            int sz = adj[i].size() ; 
            ans = max(ans , sz)  ; 
            int l = 0 , r = sz-1 ; 
            int occ = 0 ; 
            while(l<r){
                occ+=2 ; 

                int li = adj[i][l] +1; 
                int ri = adj[i][r] -1; 
                for(int j = 1 ; j <=200 ; j++){
                    int R = upper_bound(adj[j] .begin() , adj[j] .end() , ri) - adj[j].begin() ; 
                    int L = lower_bound(adj[j].begin() , adj[j].end() , li ) -adj[j].begin() ; 
                    int mx = R - L ; 
                    ans = max(ans , mx + occ) ; 
                }
                l++ ; 
                r-- ; 
            }
        }
        cout<<ans<<"\n"; 
    }
 
    return 0 ; 
}
