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

int n, all; 
int l , r ; 
vector<int> ans; 

bool check(int i){
        if(i-1>=0){
                return ans[i]!=ans[i-1] ; 
        }
        return 1 ; 
}

bool good(int i){
        return check(i) && check(i+1) && check(all-1) && check(all - 2) ; 
}

int occ[N] ; 
int occ2[N] ; 


int cur1 = N, cur2 = N ; 
vector<int> vec[N] ;

void move(int &x){
        if(x) x-- ; 
        while(x && vec[x].size() == 0)x -- ; 
}

int getk(){
        int ret = 0 ;   
        int las = ans.back() ; 

        if(!vec[cur2].size())move(cur2) ; 
        if(cur2){
                if(!vec[cur2].size())move(cur2) ; 
                while(cur1>=cur2){
                        move(cur1) ; 
                        if(cur1 == 0 && cur2 == 0)
                                return 0 ; 
                }
                if(!cur2 && !cur1)return 0 ; 
                assert(cur2>=0 && vec[cur2].size()) ; 

                if(cur2 && vec[cur2].size() && vec[cur2].back() != las){
                        int x = vec[cur2].back() ; 
                        vec[cur2-1].push_back(vec[cur2].back()) ; 
                        vec[cur2].pop_back() ; 
                        return x ; 
                }else if(vec[cur2].size() > 1){
                        if(vec[cur2][vec[cur2].size() - 2] != las){
                                int x = vec[cur2].back() ; vec[cur2].pop_back() ; 
                                int y = vec[cur2].back() ; vec[cur2].pop_back() ; 
                                vec[cur2].push_back(x) ; 
                                vec[cur2-1].push_back(y) ; 
                                return y ; 
                        }
                }
                if(!vec[cur1].size())
                        move(cur1) ; 
                if(cur1){
                        assert(cur1>=0 && vec[cur1].size()) ; 
                        int x = vec[cur1].back() ; 
                        if(x == las)return 0 ; 
                        vec[cur1].pop_back() ; 
                        vec[cur1-1].push_back(x) ; 
                        return x ;  
                }
        }

        return 0 ; 
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        //freopen("out.out" , "w" , stdout) ; 
        cin >> n >> l >> r ; 
        for(int i = 1; i<= n; ++ i){
                cin >> occ[i] ; 
                all+=occ[i] ; 
                occ2[i] = occ[i] ; 
                cur1 = cur2 = max(cur1 , occ[i]) ; 
        }

        if(all == 1)return cout<< l , 0 ; 

        ans = {l} ; 
        occ[l] -- ; 
        occ[r] -- ; 
        if(*max_element(occ , occ + N) >= all / 2 + 3)return cout<< 0 , 0; 
        if(occ[l]<0 || occ[r]<0)return cout<< 0 , 0 ; 

        for(int i = 1; i < N; ++ i){
                vec[occ[i]].push_back(i) ; 
        }
        move(cur1) ; 
        move(cur2) ; 
        for(int i = 2; i < all ; ++ i){
                int k = getk(); 
                if(!k)
                        return cout<< 0 , 0 ; 
                ans.push_back(k) ; 
        }
        ans.push_back(r) ;

        int bads = 0 ; 

        for(int i = 1; i < all ; ++ i)
                bads+=(ans[i] == ans[i-1]) ; 

        assert(bads<2) ; 

        if(bads){
                for(int i = 1; i < all - 1; ++ i){
                        swap(ans[i] , ans[all-2]) ; 
                        if(good(i))
                                break ; 
                        swap(ans[i],ans[all-2]) ;
                }
        }

        if(ans.back() == ans[ans.size() - 2])
                swap(ans[1],ans[ans.size()-2]) ; 
        
        for(int i = 1; i < (int) ans.size() ; ++ i){
                if(ans[i] == ans[i-1]){
                        return cout<< 0 , 0 ; 
                }
        }
        for(auto u : ans)occ2[u] -- ; 
                for(int i = 0 ;i < N; ++ i)
                        if(occ2[i])
                                return cout<< 0 , 0 ; 

                        for(auto u : ans){
                                cout<< u <<" " ; 
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