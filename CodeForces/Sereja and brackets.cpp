#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e6 + 7  ;

int n , k , sz ; 
string s ; 
int val[N] ; 

struct vert {
        int a , b , c ; 
        vert(int _a , int _b , int _c){
                a =_a ; b  = _b ; c = _c; 
        }
        vert combine(vert &rhs){
                int match = min(c , rhs.b) ; 
                vert ret = vert(a + rhs.a  + match , b + rhs.b - match , c + rhs.c - match) ; 
                return ret ; 
        }
};
vector<vert> tree(N * 4 , vert(0 , 0 , 0 ) ) ;  

void update(int node , int L , int R , int idx , vert x ){
        if(L == R){
                tree[node] = x ; 
                return ; 
        }
        int mid = (L + R) /2 ; 
        if(idx<=mid)
                update(node * 2 +1 , L , mid , idx , x) ; 
        else 
                update(node*2 +2 , mid+1 , R , idx , x) ; 
        tree[node] = tree[node*2+1]. combine(tree[node*2+2]) ; 
}

vert query(int node , int  L , int R , int l , int r){
        if(l > r || L > r || R < l ) return vert(0 , 0 , 0) ; 
        if(L>=l && R<=r)
                return tree[node] ; 
        int mid = (L+R) /2 ; 
        vert s1 = query(node *2 +1 , L , mid , l , r ) ; 
        vert s2 = query(node*2 +2 , mid+1 , R , l , r) ; 
        return s1.combine(s2); 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 

        cin>>s ; 
        cin>>k ; 
        n = s.size() ; 

        for(int i = 0 ; i< n ;i++){
                int is = (s[i] == '(') ; 
                vert x  = vert(0 , !is ,  is) ; 
                update(0 , 1 , N , i+1 , x ) ; 
        }

        for(int i = 0 ;i < k ;i++){
                int a , b ; 
                cin>>a>>b ; 
                vert ans = query(0 , 1, N , a , b) ; 
                cout<< ans.a * 2 <<"\n" ; 
        }

        return 0 ; 
}
