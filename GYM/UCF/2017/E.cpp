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

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;
        //freopen("in.in" , "r" , stdin) ;

        int t; 
        cin >> t ; 
        while( t-- ){
                double w , a ,b ,c ; 
                cin >> w >> a >> b >> c; 

                double ans = 0 ; 
                int x ;
                cin >> x ; 
                while(x -- ){
                        double A , B ; 
                        cin >> A >> B; 
                        double dist = hypot(A , B) ; 
                        int wed = 0 ; 
                        double angle = atan2(B , A) * 180.0 / acos(-1) ; 
                        if(angle < 0)
                                angle += 360 ; 
                        double plac = 360 / w ; 
                        double rank = ceil(angle / plac) ; 
                        if(dist < a){
                                ans += 50 ; 
                        }else if(dist > a && dist < b){
                                ans += rank * 2 ; 

                        }else if(dist < c)
                                ans += rank ;
                }
                cout<< ans <<"\n" ;
        }

        return 0 ; 
}