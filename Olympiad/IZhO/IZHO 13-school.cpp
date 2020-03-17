/*
    online judge : oj.uz
    Handle: mohamedsobhi777
    problem : IZHO 2013 C.Schools
    problem link : https://oj.uz/problem/view/IZhO13_school

    idea : sort by S[i] - M[i]
    and for every i the answer is max(take M music schools in the prefix up to i and take S sports schools from the suffix n-1 to i+1)

    submission : https://oj.uz/submission/210609
*/
#include <bits/stdc++.h> 

using namespace std ;
const int N = 3e5 +5 ; 

int n , M , S; 
vector<pair<int , int > > v; 
long long m[N] , s[N] ; 
long long pre[N] , suf[N] ;
long long sum  , sol;

int main(){
    cin>>n>>M>>S; 
    for(int i = 0 ; i < n ; i++){
        cin>>m[i]>>s[i] ; 
        v.push_back({s[i]-m[i] , i}) ;
    }    
    sort(v.begin() , v.end());
    priority_queue<int , vector<int> , greater<int>  > q ; 
    for(int i = 0 ; i <n ; i++){
        if(q.size()< M){
            sum+=m[v[i].second] ;
            q.push(m[v[i].second]);
        }else if( q.top() < m[v[i].second] ){
            sum+= m[v[i].second] - q.top(); 
            q.pop();
            q.push(m[v[i].second]);            
        }
        pre[i] = sum ; 
    }
    while(q.size() )q.pop() ; sum = 0;
    for(int i = n-1 ; i>= 0 ; i--){
        if(q.size() < S ) {
            sum+=s[v[i].second] ; 
            q.push(s[v[i].second]) ; 
        }
        else if(q.top() < s[v[i].second]) {
            sum+=s[v[i].second] - q.top() ; 
            q.pop() ; 
            q.push(s[v[i].second]) ; 
        }
        suf[i] = sum; 
    }
    sol = suf[0] ; 
    for(int i = 0 ; i <n ; i++){
        sol = max(sol , pre[i] + suf[i+1]) ; 
    }
    cout<<sol;
    return 0 ; 
}
