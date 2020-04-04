/*
    Date : 04/04/2020
    Author : Mohamed Sobhy
    Handle : mohamedsobhi777
    
    problem given two permutations A and B of size n,

    pair(l , r) is the pairing of A[l] to B[r]

    what is the maximum number of pairs (l , r) we can get such that abs(A[l] - B[r]) <= 4, 
    and for each two pairs (l2 , r1) and (l2 , r2) , l1 < l2 then r1 < r2

    Observation 1 : each number in A has at most 9 choices in B to be matched to.
    Observation 2 : if for each number in A, we keep an array of all its possible choices, then thee problem turns to the following:

    given n arrays, each array has maximum of 9 elements, you can choose at most 1 number of each array, calculate the LIS.
    to achieve this we will do a slight modification to the standard LIS.

    O(N log N)
    
*/

#include<bits/stdc++.h>

using namespace std ; 

const int N   = 1e5 + 7 ; 

int n  ; 
int p[N] , a[N] ; 
int tree[N*4] ; 

void update(int node , int L , int R , int idx , int val){
    if(L==R){
        tree[node] = max(val , tree[node]) ; 
        return  ; 
    }
    int mid = (L+R)/ 2 ; 

    if(idx <=mid){
        update(node *2 +1 , L , mid , idx , val) ; 
    }
    else{
        update(node*2+2 , mid+1 , R , idx , val) ; 
    }
    tree[node] = max(tree[node*2+1] , tree[node*2+2]) ; 
}

int query(int node , int L , int R , int l , int r){
    if(l>r || l > R || r < L)return 0 ; 
    if(L>=l && R<=r)return tree[node] ; 
    int mid = (L+R)/2 ; 
    int s1 = query(node*2 +1 , L , mid , l , r) ; 
    int s2 = query(node*2+2 , mid+1 , R , l , r) ; 
    return max(s1 , s2) ; 
}

int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
    freopen("nocross.in" , "r" , stdin) ; 
    freopen("nocross.out" , "w"  , stdout) ; 
    cin>>n; 
    for(int i = 0 ; i < n;i++){ 
        cin>>a[i] ; 
    }
    for(int i = 1 ; i <= n  ; i++){
        int t ; 
        cin>>t ; 
        p[t] = i ; 
    }

    for(int i = 0 ; i < n;i++){
        int l = max(1 , a[i] - 4  ) ; 
        int r = min(n , a[i] + 4) ; 
        vector<int> anss ; 

        //calculating the max Lis ending at each element of the array
        for(int j = l ; j<=r ; j++){
            int k = p[j] ; 
            int sol = query(0 , 1 , N , 1 , k-1 ) ; 
            anss.push_back(sol) ;
        }

        // updating the answers
        for(int j = l ; j<=r ; j++){
            update(0 , 1 , N , p[j], anss[j-l] +1 )  ;
        }
    }
    cout<<query(0 , 1 , N , 1 , n) ; 
    return 0 ; 
}
