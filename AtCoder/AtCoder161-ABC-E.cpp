
/*
    Problem : E.Yutori
    Problem Link : https://atcoder.jp/contests/abc161/tasks/abc161_e
    contest : atcoder beginner contest 161 
    Handle : mohamedsobhi777

    solution :
    for each day work 'o' we will calculate the max num of days he can work without taking it, we will divide it into two subproblems 
    1: days in the prefix up to index i-1, and we can calculate greedily, and store them in array pre[]

    2: days in the suffix i+1 to n-1, we can calculate them using dp and save their answers in array suf[] 

    now we iterate from n-1 to 0, and for each work day, we keep track of r (the last index with its suf[r] maximum) we can do so by updating r to be i 
    only if suf[i] > suf[r] and the i is a work day

    now the number of work days we can do without the ith day equals suf[i] + pre[min(i-1 , r - c -1)]

*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 2e5 + 7 ; 

int pre[N] ; 
int n , m , k ; 
string s ; 
vector<int> ans ; 

int suf[N] ; 

int solve(int i){
    if(i>=n)return 0 ; 
    if(suf[i]!=-1)return suf[i] ; 
    if(s[i]=='o'){
        return suf[i] = 1 + solve(i + k + 1) ; 
    }
    return suf[i]  = solve(i+1) ; 
}


int main(){ 
    memset(suf , -1 , sizeof suf ) ; 
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 

    cin>>n>>m>>k ;
    cin>>s ; 

    //calculating suf array using dp
    for(int i =0 ; i < n;i++){
        solve(i)  ;
    }

    //calculating pre array greedily
    int l =-1 , sum = 0 ; 
    for(int i = 0 ; i < n;i++){
        pre[i] = sum ; 
        if(i<=l)continue ; 
        if(s[i]=='o'){
            sum++ ; 
            l = i + k ; 
        }
        pre[i] = sum ; 
    }
    
    int r= n+ N ; 
    for(int i = n-1 ; i >=0;i--){
        if(s[i]=='o'){
            int leftix = min(i-1 , r - k -1  );
            int right = solve(i+1) ; 
            int left = (leftix<0 ?0 : pre[leftix]) ; 
            if(right + left < m){
                ans.push_back(i+1) ; 
            }
            if(solve(i) > solve(r))
               r = i ; 
        }
    }

    reverse(ans.begin() , ans.end()) ; 
    for(auto u : ans){
        cout<<u<<"\n" ; 
    }
    return 0 ; 
}
