#include <bits/stdc++.h> 
 
using namespace std ; 
 
const int N = 2e5 + 5 ;
const long long infinite = 1e17 ; 

/*
  author : Mohamed Sobhy 
  Handle : Mohamed.Sobhy
  contest : 628 Div.2
  contest link :https://codeforces.com/contest/1325
  problem : D. Ehab the Xorcist
  
  
  break the problem into smaller ones by adding u to the array
  now we want to add some elements that add up to v-u without changing the array Xor (that's why there is no answer if v<u)
  we iterate over the bits of v-u in the binary representation, if the ith bit is active, then we need to add the i-1th bit 
  twice in the array so that they add up to 2^i, without changing the overall xor, (that's why there is no answer if v-u is odd)


  submission : 
*/
 
int n ; 
long long a , b ; 
long long A[70];

long long get(){
    long long ret = 0 ; 
    for(long long i =0;i<61;i++){
        if(A[i]){
            A[i]--;
            ret+=(1LL<<i);
        }
    }
    return ret ; 
}
     
int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
   // freopen("in.in" , "r" , stdin) ; 
    cin>>a>>b ; 
    if(a>b)
        return cout<<-1,0;  
    vector<long long > ans ; 
 
    for(int i= 60;i>=0;i--)
    {
        if(a&(1LL<<i)){
           A[i]++;
        }
    }   
    b-=a ; 
    if(b&1)
        return cout<<-1,0;
    for(int i = 60;i>0;i--){
        if(b&(1LL<<i)){
            A[i-1]+=2;
        }
    }
    long long x = get() ; 
    while(x)
    {
        ans.push_back(x) ; 
        x = get() ; 
    }
    cout<<ans.size()<<"\n";
    for(auto u : ans){
        cout<<u<<" ";
    }
 
    return 0 ;
}   
 	 			   	      						 			 	
