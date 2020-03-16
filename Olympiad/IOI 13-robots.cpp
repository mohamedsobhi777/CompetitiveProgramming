/*
  
  solution :http://blog.brucemerry.org.za/2013/07/

*/

#include "robots.h"
    #include <bits/stdc++.h>
    const int N = 1e6 + 6 ;
    using namespace std ; 
     
    int AA , BB  , TT  ;
    vector<int> XX , YY , WW , SS ; 
    vector<int> appear[N] ; 
     
     
    bool check(int x){
     
        priority_queue<int> q ; 
        //start by the weak robots and take the toys in such a way that make the task for the small robots easiter
        for(int i = 0 ; i < AA ; i++){
            for(int j = 0 ; j < appear[i].size() ; j++){
                q.push(appear[i][j]) ; 
            }
            int sz = min((int)q.size() , x) ; 
            for(int j = 0 ; j < sz ; j++){
                q.pop() ; 
            }
        }
        for(int i = 0 ; i < appear[AA].size() ; i++){
            q.push(appear[AA][i]) ; 
        }
        for(int i = 0 ; i < BB ; i++){
            int sz = min((int)q.size() , x ) ; 
            for(int j = 0 ; j < sz ; j++){
                if(q.top() < YY[i])
                {
                    q.pop() ; 
                }
                else break; 
            }
        }
        return !q.size(); 
    }
            
    int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
        AA = A ; BB = B ; TT = T ; 
        for(int i = 0 ; i < A ; i++){
            XX.push_back(X[i]) ; 
        }
        for(int i = 0 ; i < B ; i++){
            YY.push_back(Y[i]) ; 
        }
        sort(XX.begin() , XX.end()) ; 
        sort(YY.begin() , YY.end()) ;
     
        //check if all the toys can be removed by at least one robot each
        for(int i = 0 ; i < T ; i++){
            int i1 = upper_bound(XX.begin() , XX.end() , W[i] ) - XX.begin() ; 
            int i2 = upper_bound(YY.begin() , YY.end(), S[i]) - YY.begin() ; 
            if(i1==A && i2==B)
                return -1 ; 
            appear[i1].push_back(S[i]) ; 
        }    
     
        for(int i = 0 ; i < A ; i++){
            sort(appear[i].begin() , appear[i].end() , greater<int>()) ;
        }
        sort(YY.begin() , YY.end(), greater<int>()) ; 
        
        // binary search the min time the robots can clean the floor
        int l = 1 , r = T ;
        int ans = -1; 
        while(l<=r){
            int mid = (l+r) /2;
            if(check(mid)){
                ans = mid ; 
                r = mid - 1 ; 
            }
            else{
                l = mid + 1 ; 
            }
        }
        return ans ;
    }
     
