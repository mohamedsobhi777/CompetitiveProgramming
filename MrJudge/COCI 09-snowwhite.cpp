/*
        Problem : COCI 09-snowwhite
        Link : https://dunjudge.me/analysis/problems/153/
        Handle : mohamedsobhi777

        Solution : Use mo's algorithm to get the count of each colors, then loop over all the colors and get the most frequent one
*/

#include<bits/stdc++.h>
#define rot 500

using namespace std  ; 

const int N = 3e5 + 7; 

int n , m ;
int a[N] ;
int ans[N] ; 

struct query{
        int l , r , ix ; 

        bool operator<(query &rhs)const {
                int s1 = l / rot ; 
                int s2 = rhs.l / rot ; 
                if(s1== s2){
                        return r < rhs.r ; 
                }
                return s1 < s2 ; 
        } 
} ;

vector<query> qs ; 


int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 

        cin>>n >>m; 
        for(int i = 0 ;i < n; i++){
                cin>>a[i] ; 
        }
        int k ; 
        cin>>k  ;
        for(int j = 0 ; j < k ; j++){
                int x , y ; 
                cin>>x>>y ; 
                x-- ; y-- ; 
                query q ; 
                q.ix = j ; 
                q.l = x ; 
                q.r = y ; 
                qs.push_back(q) ;
        }

        sort(qs.begin() , qs.end() ) ; 

        int l = -1, r = 0 ; 
        vector<int> cols(N , 0) ; 
        for(int i = 0 ; i < k ; i++){
                int L = qs[i].l ; 
                int R = qs[i].r ; 
                int ix = qs[i].ix ;
                while(r  <= R ){
                        cols[a[r++]]++ ;
                }
                while(l > L){
                        cols[a[--l]]++  ;
                }
                while(l < L){
                        cols[a[l++]]-- ; 
                }
                while(r > R +1 ){
                        cols[a[--r]]-- ; 
                }
                for(int j = 1 ;j <=m;j++){
                        if(cols[j] > (R-L+1) /2){
                                ans[ix] = j ; 
                        }
                }
        }

        for(int i = 0 ; i  < k ;i++){
                if(ans[i] == 0){
                        cout<<"no\n" ; 
                        continue  ; 
                }
                cout<<"yes "<< ans[i] <<"\n" ; 
        }
        return 0; 
}
