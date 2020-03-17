/*

idea : xor the indices that have a face coin and xor them with c

the value can be retrived if we xor all the elements all the numbers again.

submission : https://dunjudge.me/analysis/submissions/714234/

*/
#include "coins.h"


using namespace std; 

vector<int> coin_flips(vector<int> b, int c){
    int ret = c ; 
    for(int i = 0 ; i < 64 ; i++){
        if(b[i])
            ret^=i; 
    }
    return {ret} ; 
}

int find_coin(vector<int> b){
    int ret = 0 ; 
    for(int i = 0 ; i < 64 ; i++){
        if(b[i])
            ret^=i ; 
    }
    return ret ; 
}
