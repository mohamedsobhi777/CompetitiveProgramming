#include<bits/stdc++.h>

/*
#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")*/

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 5e5 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n; 

int ix(char c){
        return (c - 'a') ; 
}

pair<int,int> pos(int x){
        return {x / 9 , x % 9} ;
}

bool iden(string s , string t){
        int sz = s.size() ; 
        for(int i = 0 ; i <sz ;i++){
                pair<int,int> p1 = pos(ix(s[i])) ; 
                pair<int,int> p2 = pos(ix(t[i])) ; 
                if(abs(p1.first - p2.first) > 1 || abs(p1.second - p2.second) > 1)
                        return 0; 
        }
        return 1 ; 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        //freopen("in.in" , "r" , stdin) ;

        int k ; 
        cin >> k ; 
        while (k -- ){
                string a , b; 
                cin >> a >> b; 
                bool ok = (int) a.size() == b.size() ; 
                if(a == b && ok){
                        cout<<"1" ;
                }else if(iden(a , b) && ok){
                        cout<<"2" ; 
                }else{
                        cout<< "3" ; 
                }
                cout<<"\n" ; 
        }

        return 0 ; 
}