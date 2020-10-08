#include<bits/stdc++.h>

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 1e6 + 7 , mod = 1e9 + 7 ; 
const ll inf = 2e18 ; 

// How interesting!

int n ; 
int pref[N], suff[N] ; 
int a[N] ;  
string s ;
vector<int> all[N] ; 
int c1[N], c2[N]; 
int L[N] ; 

void pre(){
        pref[0] = a[0] ; 
        suff[n-1] = a[n-1] ; 
        for(int i = 1; i < n ; ++ i){
                pref[i] = pref[i-1] + a[i] ; 
        }
        for(int i = n - 2 ; ~ i; -- i){
                suff[i] = suff[i+1] + a[i] ; 
        }
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        cin >> n >> s ; 

        for(int i = 0 ;i < n; ++ i){
                a[i] = (s[i] == 'p' ? 1  :  -1) ; 
        }

        pre() ; 
        vector<int> v1(n) , v2(n) ; 
        for(int i = 0 ;i < n; ++ i){
                v1[i] = pref[i] ; 
                v2[i] = suff[i] ; 
        }
        for(int i = 1 ; i < n; ++ i)c1[i] = pref[i - 1] ; 
        for(int i = 0 ;i < n - 1; ++ i)c2[i] = suff[i + 1] ; 

        int ans = 0 ; 

        stack<int> stk1, stk2;

        for(int i = 0 ;i < n; ++ i){
                while(stk1.size() && c1[i] < c1[stk1.top()] ){
                        all[i-1].push_back(stk1.top()) ; 
                        stk1.pop() ; 
                }
                stk1.push(i) ; 
        }
        while(stk1.size()){
                all[n-1].push_back(stk1.top()) ; 
                stk1.pop() ; 
        }

        for(int i = n - 1 ;~ i; -- i){
                while(stk2.size() && c2[i] < c2[stk2.top()] ){
                        L[stk2.top()] = i + 1;  
                        stk2.pop() ; 
                }
                stk2.push(i) ; 
        }
        set<int> st ; 
        for(int i = n - 1 ; ~ i ; -- i){
                int las = suff[i+1] ; 
                int j = i ; 
                for(auto u : all[i])
                        st.insert(u) ; 
                if(suff[i]>=las){
                        int lo = 0, hi = i ;
                        int j = L[i] ;
                        auto it = st.lower_bound(j) ; 
                        if(it!=st.end())
                                ans = max(ans , i - (*it) + 1) ; 
                }
        }

        cout<< ans ; 
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