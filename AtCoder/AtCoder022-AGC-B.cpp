/*

        Problem : AtCoder022-AGC-B
        Link : https://atcoder.jp/contests/agc022/tasks/agc022_b
        handle : mohamedsobhi777
        Date : 26 / 07 /2020

        Problem :
                construct a list A of n distinct numbets such that 
                        -gcd( A[1] , A[2] , ... , A[n] ) = 1
                        -gcd( A[i] , S - A[i] ) != 1,  for 1<= i <= n , 
                        - A[i] <= 30000
                                S = sum of all numbers in A


                Solution:
                        let's try to break the problem into 2 sub problems

                        first: if we pick two primes, then no matter what other numbers we choose, the gcd of all the
                                numbers in the list will be 1
                        
                        second: 
                                notice that gcd(A[i] , S - A[i] ) = gcd( S , A[i])

                        so, if we pick 2 and 3, and put them in the list, we then pick only the multiples of 2 and 3 in a 
                        way that the sum S is a multiple of 6

*/

#include<bits/stdc++.h>

using namespace std ; 

const int N = 3e4 + 7 ;

bool vis[N] ;
int rem ; 

int roof = N - 7 ; 

void add(int x){
        if(vis[x])
                return ; 
        vis[x] = 1; 
        cout<< x<<" "; 
        rem -- ; 
}

int main(){
       // freopen("in.in" , "r" ,stdin) ; 
        int n ; 
        cin >> n; 
        rem = n ; 

        if(n == 3){
                cout<< "2 5 63" ;
        }
        else{
                add(2) ; add(3) ; add(4) ; add(9) ;
                int cur6 = 15  ;
                while(rem > 1 && cur6 + 6 < roof ){
                        add(cur6) ; 
                        add(cur6+6) ; 
                        cur6+=12 ;
                }
                int cur24 = 8 ; 
                while(rem > 1 && cur24 + 2 < roof){
                        add(cur24) ; 
                        add(cur24 +2) ; 
                        cur24+=6 ; 
                }

                int cur60 = 6 ; 

                while(rem && cur60 <= roof){
                        add(cur60) ; 
                        cur60+= 6 ; 
                }

               
        }

        return 0 ;
}
