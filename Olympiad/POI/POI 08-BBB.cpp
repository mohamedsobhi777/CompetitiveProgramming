/*
        Problem : POI 08-BBB
        Link : https://szkopul.edu.pl/problemset/problem/Fej8rGpqWzXEi_qjK2Cmfe4Y/site/?key=submissions
        Date : 26 / 7 / 2020
        handle : mohamedsobhi777

        Solution : 
                first thing we notice that the order of the changes doesn't matter, so we will do the shifting first
                -we will try to shift k positions of the array, for each 0 <= k < n, with proper preprocessing, we can 
                get the following information
                        - the minimum balance on a day in the new prefix (after shifting by k)
                        -then we change - to + if needed (if the balance was below 0 on some day)
                        -and finally we add the difference between the final balance and the current balance after the changes
        
                O(N)

        A Similar problem : 
                        Feb-cockoff-2020 : https://www.codechef.com/COOK115B/problems/CYCLCSUM

*/
#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e6 + 7 ; 

int n , p , q , x , y ; 
string s ;

int pre[N] ; 
int suf[N] ; 
int mpre[N] ;

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ;

        //freopen("in.in" , "r" ,stdin) ; 

        cin >> n >> p >> q >> x >> y ; 

        cin >> s; 

        int b = p ; 
        for(int i = 0 ; i < n; i++){
                if( s[i] == '-') b-- ; 
                else b++ ; 
                pre[i] = b ; 
        }

        for(int i = n -1 ; i >= 0 ;i --){
                if(i < n -1 ) 
                        suf[i]  = min(suf[i+1] , pre[i]) ;
                else suf[i] = pre[i] ; 
        }
        mpre[0] = pre[0] ; 
        for(int i = 1 ;i < n ;i++){
                mpre[i] = min(mpre[i-1] , pre[i]) ;
        }

        int ans = 1e9 ; 

        int diff = abs(b - q) / 2; 
        
        pre[n] = pre[n-1] ; 
        suf[n] =110111  ;
        int tmp = b ; 
        for(int i = 0 ; i < n ;i ++){
                b = tmp ; 
                int k = suf[i+1] - pre[i] + p; 
                int fixA = (max(0 , -k) + 1 ) /2 ;
                
                int cur = fixA * x ; 
                int right = pre[n-1] - pre[i] ;  right += 2 * fixA ;
                b+= fixA * 2 ;

                int left = max( -mpre[i] - right , 0) ; 
                int fixB = (left + 1) /2 ; 
                cur += x * fixB ; 
                b+= 2 * fixB ;
                cur += x * (  abs(q - b) /2  ) ;

                cur += (n - i - 1 ) * y ;

                ans = min(ans, cur) ; 

        }

        cout<< ans ; 

        return 0; 
}
