#include<bits/stdc++.h>


#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")

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
const ll inf = 2e18 ; 

// How interesting!

int n ; 
string s ; 
int a[N] ; 
int prf[N] ; 
int R[N] ; 
int zero = N ; 
vector<int> occs[N* 2] ; 
int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        cin >> n; 
        cin >> s; 
        for(int i = 0 ;i < n; ++ i){
                a[i] = (s[i] == '(' ? 1: -1) ; 
                if(i)a[i] += a[i-1] ;
                prf[i+1] = a[i] ; 
                occs[a[i] + zero].push_back(i) ; 
        }

        stack<int> st ; 
        for(int i = 0 ;i < n; ++ i){
                while(st.size() && prf[st.top()] > prf[i]){
                        R[st.top()] = i ; 
                        st.pop() ; 
                }
                st.push(i) ; 
        }       
        while(st.size()){
                R[st.top()] = n ; 
                st.pop() ; 
        }

        int t ; cin >> t; 
        while(t -- ){
                int l , r;  cin >> l >> r ; 
                -- l ; -- r; 
                if(s[l] == ')'){
                        cout<<"0\n" ; 
                        continue ; 
                }
                int pref = (l ? a[l-1] : 0) ;
                int las = l - 1 ; 
                int it = lower_bound(occs[pref + zero].begin() , occs[pref + zero].end() , min(r + 1 , R[l] ) ) - occs[pref+zero].begin() ;  
                -- it ; 
                if(it >= 0 ){
                        las = occs[pref + zero][it] ;  
                }

                cout<< las - l + 1 <<"\n" ; 
        }



        return 0 ; 
}

/*
        - bounds sir (segtree = 4N, eulerTour = 2N, ...)
        - a variable defined twice?
        - will overflow?
        - is it a good complexity?
        - don't mess up indices (0-indexed vs 1-indexed)
        - reset everything between testcases. 
*/