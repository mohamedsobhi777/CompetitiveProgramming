/*
Problem : Art Exhibition
Contest : JOI18_ART
link : https://oj.uz/problem/view/JOI18_art
Handle : mohamedsobhi777
submission link : https://oj.uz/submission/213090

solution : 

We want to maximize S_taken - (max S - min S) = S_taken + min S - max S

if the max size of a chosen element = m , and the max size = M
then all the elements with sizes between m and M (incluive) won't decrease the answer (the absolute value between max S and min S),
so it cause no harm to our answer, it only add V[i] to the answer.

here is my greedy approach
sort the elements by increasing S(size), then iterate over all elements,
let suf[i] = cumelative sum of Values from i to n (1-indexed), and let suf[n+1] = 0

the answer if we fix the ith element and consider only elements with larger S is (suf[i] + S[i]) +  max of (i<=j<=n) {- suf[j+1] - S[j]}
this can be implemented using a priority queue, iterating from n to 1

O(N log N)

*/

#include <bits/stdc++.h>

using namespace std ; 
const int N = 5e5 + 7 ; 

int n ;
vector<pair<long long  , long long > >  v ; 
long long ans = -1e17 ; 
long long suf[N]; 

int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;     
    cin>>n ;
    for(int i = 0 ; i < n;i++){
        long long a ,b ; 
        cin>>a>>b ; 
        v.push_back({a , b}) ; 
    }
    // sort by S[i]
    sort(v.begin() , v.end()) ;

    //keep suffix sum
    suf[n-1] = v[n-1].second ; 
    for(int i = n-2 ; i>=0 ; i--){
        suf[i] = suf[i+1] + v[i].second ; 
    }
    //greedily update the answer for each i
    priority_queue<long long > q ; 
    for(int i =n-1 ; i>=0 ;i--){
        q.push( -suf[i+1] - v[i].first  ) ; 
        ans = max(ans , q.top() + v[i].first + suf[i]) ; 
    }
    cout<<ans; 
    return 0 ; 
}
