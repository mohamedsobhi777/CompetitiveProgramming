#include<bits/stdc++.h>
#include<friend.h>

/*
solution : http://blog.brucemerry.org.za/2014/07/

*/

using namespace std ; 

const int N = 1e5 + 5 ; 

int findSample(int n , int confidence[] , int host[] , int protocol[]){
    int sol[n+1];
    for(int i = 0 ; i < n; i++)
        sol[i] = confidence[i] ;
    int ret = 0 ; 
    for(int i  = i-1 ; i>=0 ; i--){
        int p = protocol[i] ; 
        if(!p){
            ret+=sol[i] ; 
            sol[host[i]] = max(0 , sol[host[i]] - sol[i]) ; 
        }
        else if(p==1){
            sol[host[i]] +=sol[i] ; 
        }
        else{
            sol[host[i]] = max(sol[host[i]]  ,sol[i]) ; 
        }
    }
    return sol[0] + ret ; 
}

