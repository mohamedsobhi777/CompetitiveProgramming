#include<bits/stdc++.h>

using namespace std ; 

const int N = 3e5 + 7 ; 

int n , m , k ;  
int a[N] , b[N] ;
int L[N] , R[N] ;
int l[N] , r[N] , v[N] ; 
int ans[N] ; 
vector<int> prop[N]; 

struct bit{
    vector<unsigned long long> arr ; 
    void init(int sz){
        arr.resize(sz) ; 
        fill(arr.begin() , arr.end() , 0) ; 
    }
    void add(int i , long long val){
        for(;i< N ;i += i&(-i) ){
            arr[i]+=val ; 
        }
    }
    unsigned long long get(int i){
        if(i<=0)return 0 ; 
        long long ret = 0 ; 
        for(;i;i-=i&-i){
            ret+=arr[i] ;
        }
        return ret ; 
    }
    unsigned long long calc(int l , int r){
        return get(r) - get(l-1) ; 
    }

}bt; 

void clear(){
    bt.init(N+10) ; 
}

void just (int A , int B , int F){
    A++ ; B++ ; 
    bt.add(A , F) ; 
    bt.add(B+1 , -F) ; 
}

void apply(int j){
    int x = l[j] , y = r[j] , f = v[j] ; 
    if(x <=y)just (x , y , f) ; 
    else {
        just(x , m-1 , f) ; 
        just(0 , y , f) ; 
    }
}

int main(){ 
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
    //freopen("in.in" , "r" , stdin) ; 

    cin>>n >>m; 
    for(int i = 0 ;i < m ; i++){
        cin>>a[i] ;
        a[i] -- ; 
        prop[a[i]].push_back(i) ; 
    }
    for(int i = 0 ;i < n;i++){
        cin>>b[i] ; 
    }
    cin>>k ;
    for(int i = 0 ;i < k;i++){
        cin>>l[i] >> r[i] >> v[i] ;
        l[i] -- ; r[i] -- ; 
    }

    for(int i = 0 ;i < n;i++){
        R[i] = k-1 ; 
        ans[i] = -1 ; 
    }
    int cpyK = 32 ; 
    while(cpyK--){
        clear() ; 
        vector<int> qrs[N] ;
        for(int i = 0 ;i < n ; i++){
            if(L[i] <= R[i] ){
                int mid = (L[i] + R[i]) / 2;
                qrs[mid].push_back(i) ; 
            }
        }  
        for(int i = 0 ;i < k ;i++){
            apply(i) ;
            for(auto u : qrs[i]){
                unsigned long long V = 0 ;
                for(auto &e : prop[u]){
                    V+=bt.calc(1 , e+1); 
                }
                if(V >= b[u] ){
                    R[u] = i -1; 
                    ans[u] = i ; 
                }
                else {
                    L[u] = i +1 ; 
                }
            }
        }
    }

    for(int i = 0 ;i < n; i++){
        if(ans[i] == -1){
            cout<<"NIE\n" ; 
        }
        else {
            cout<<ans[i] + 1 <<"\n" ; 
        }
    }
    return 0 ; 
}
