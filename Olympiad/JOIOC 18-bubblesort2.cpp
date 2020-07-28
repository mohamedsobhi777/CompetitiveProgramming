/*

  Problem : JOIOC 18-bubblesort2
  Link : https://oj.uz/problem/view/JOI18_bubblesort2
  handle: mohamedsobhi777
  
  Solution : Same as editorial's 
  
*/

#include<bits/stdc++.h>
#include "bubblesort2.h"
 
using namespace std ; 
 
const int N = 1e6 + 7 ;  
int n; 
 
int tree[N * 4] , lazy[N * 4] ; 
set<int> ixs[N]; 
 
void update(int node , int L , int R , int l , int r , int val){
        if(l > R || r < L || l > r)
                return ; 
 
        if(L>=l && R<=r){
                lazy[node] += val ; 
                return ; 
        }
        int mid = (L + R) >>1  ; 
 
        update(node*2+1 , L , mid , l , r , val) ; 
        update(node*2+2 , mid+1 , R , l , r, val) ; 
        tree[node] = max(tree[node *2 +1] + lazy[node*2+1] , tree[node*2+2] + lazy[node *2+2] ); 
}
 
int query(int node , int L , int R , int l , int r ){
        if(l > R || r < L || l > r)
                return -N ; 
        if(L>=l && R<=r)
                return tree[node] + lazy[node]; 
        int mid = (L+R) >> 1 ; 
        int s1 = query(node*2+1 , L , mid , l , r) ; 
        int s2 = query(node*2+2 , mid+1 , R , l , r ) ; 
        return max(s1 , s2) + lazy[node] ; 
}
int js[N] ; 
 
void add(int ix , int val){
        ixs[ix].insert(val) ; 
        auto u = ixs[ix].end() ; u -- ; 
        int mx = *u ; 
        update(0 , 1, N , ix , ix , mx - js[ix]) ;
        js[ix] = mx ; 
}
 
void del(int ix , int val){
        ixs[ix].erase(ixs[ix].find(val)) ; 
        auto u = ixs[ix].end() ; u -- ;
        int mx = *u ; 
        update(0 , 1 , N , ix , ix , mx - js[ix]) ; 
        js[ix] = mx ;         
}
 
unordered_map<int , int > com ; 
vector<int> aux ; 
 
std::vector<int> countScans(std::vector<int> A,std::vector<int> X,std::vector<int> V){
 
	int Q=X.size();
        n = (int) A.size() ; 
	std::vector<int> answer(Q);
 
        for(auto u : A)
                aux.push_back(u) ; 
        for(auto u : V)
                aux.push_back(u) ; 
        sort(aux.begin() , aux.end()) ; 
        int l = 0 , now = 0 ;
        for(int i = 0 ;i < (int) aux.size() ;i++){
                if(aux[i] > l)
                        now ++ ; 
                com[aux[i]] = now ; 
                l = aux[i] ;
        }
        for(int i = 0 ; i < n; i++){
                A[i] = com[A[i]] ; 
        }
        for(int i = 0 ;i < Q ;i++){
                V[i] = com[V[i]] ; 
        }
 
        for(int i = 1 ;i<=now ; i++){
                add(i , -N  ) ; 
        }
 
        for(int i = 0 ; i < n; i++){
                add(A[i] , i) ; 
                update( 0 , 1 , N , A[i] , now  , -1) ; 
        }
 
	for (int j=0;j<Q;j++) {
                del(A[X[j]] , X[j]) ; 
                add(V[j] , X[j]) ; 
                if(V[j] >=A[X[j]]){
                        update( 0 , 1 , N , A[X[j]]  , V[j] -1 , +1) ;                 
                }
                else{
                        update( 0 , 1 ,N , V[j]  , A[X[j]] -1  , -1) ; 
                }
		A[ X[j] ] = V[ j ] ; 
 
                answer[j] =  query(0 , 1 , N , 1 , now  ) +1; 
                answer[j] = max(answer[j] , -100) ; 
 
	}
	return answer;
}
