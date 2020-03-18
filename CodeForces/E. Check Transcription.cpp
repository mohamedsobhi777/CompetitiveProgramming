/*
  problem : Check Trascription
  problem link : https://codeforces.com/contest/1056/problem/E
  Handle : Mohamed.Sobhy
*/
#include <bits/stdc++.h> 

using namespace std ; 
const int N = 1e6 + 5; 
long long mod = 1e9+7 ; 

string s , t; 
long long  n , m; 
long long  ans ; 

struct hashing {
    long long base ; 
    long long mod1;
    vector<long long> pref; 
    vector<long long> base_power; 

    long long normalize(long long x ){
        return ((x%mod1) + mod1) %mod1 ; 
    }

    void init(string &str_,long long mod1_ = 1e9 +7, long long base_ = 313){

        int sz = str_.size() ; 
        pref.resize(sz) ; 
        base_power.resize(sz) ;
        base = base_ ; 
        mod1 = mod1_ ; 
        
        base_power[0] = 1 ; 
        for(int i = 1 ;i <m ; i++){
            base_power[i] = (1ll*base*base_power[i-1]) %mod1 ; 
        }

        long long cur = 0 ; 
        for(int i = 0 ; i <m ; i++){
            cur = (cur*base + str_[i])%mod;
            pref[i] = cur ; 
        } 
    }

    long long get(int l , int r){
        long long ret = pref[r] ; 
        if(l){
            long long power_difference = base_power[r-l+1]; 
            long long prefix_hash =pref[l-1];
            prefix_hash = (prefix_hash*power_difference)%mod ; 
            ret = normalize(ret - prefix_hash) ; 
        }   
        return ret ; 
    }
};

hashing h ; 

bool make(long long &u , long long v){
    if(u!=-mod){
        return (u==v);
    }
    else {
        u = v ; 
        return 1 ; 
    }
}

bool check(long long  u , long long  v){
    long long s1 = -mod, s2 = -mod; 
    long long  j = 0 ; 
    for(auto it : s){
        if(it==s[0]){
            if(!make(s1 , h.get(j , j+u-1)))
                return 0 ; 
            j+=u ;
        }
        else { 
            if(!make(s2 , h.get(j , j+v-1 ) )) 
                return 0 ; 
            j+=v ;
        }    
        if(s1!=-mod && s1==s2)return 0 ; 
    }
    return 1; 
}


int main(){
    cin>>s>>t;
    n = s.size() ; 
    m = t.size() ;  
    h.init(t); 
    long long u = count(s.begin() , s.end() , '0') ; 
    long long v = n - u ;
    if(s[0]!='0')swap(u, v);  
    for(int i = 0 ; i < m ; i++){
        long long  j =  1LL*(m-1ll*u*(i+1))/v;
        if( 1ll*(m - (1ll*u*(i+1)) )%v ==0 ){
            if(j<=0)continue ; 
            ans+=check(i+1 , j );
        }
    }
    cout<<ans ;
    return 0 ; 
}
