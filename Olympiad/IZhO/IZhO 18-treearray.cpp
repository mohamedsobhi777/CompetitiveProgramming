#include<bits/stdc++.h> 
 
using namespace std ;

/*

the observation needed to solve the problem is that we take at most 2 elements of the given list A
if we keep array S such that S[i] = lca(A[i] , A[i-1]), then we can reduce the problem so find a number in a subarray

second case if A[i] = C for some l<=i<=r, then (i, i) is the answer 
so we keep two arrays search for our answer

if C is not in the two subarrays of our two lists the answer is (-1 , -1)

my code uses ordered_set for each value that keeps all the positions such that A[i] = v

*/

const int N = 2e5 + 7 ; 

int n , t , m, q; 
vector<int> adj[N] ; 

int st[N] , en[N] ; 
int a[N] , lcaA[N]; 
int col[N] , up[N][24]; 
set<int> lcas[N] , vls[N];


int isp(int x , int y )
{
    return (st[y]>=st[x] &&  en[y] <=en[x]);
}

void dfs(int x , int p)
{   
    st[x] = t++ ; 
    up[x][0] = p ; 
    for(int i = 1 ; i < 24 ; i++)
        up[x][i] = up[ up[x][i-1] ][i-1];
    for(auto u : adj[x])
    {       
        if(u==p)
        continue;
        dfs(u , x) ; 
    }
    en[x] = t++; 
}

bool inside(int L, int R , int l , int r)
{
    return (l>=L && l<=R && r>=L && r<=R);
}

int lca(int x , int y)
{
    if(isp(x , y))
        return x ; 
    if(isp(y , x))
        return y ; 
    for(int i = 23 ; i>=0 ; i--)
    {
        if(!isp(up[x][i] , y))
            x = up[x][i] ; 
    }
    return up[x][0] ; 
}

int main() 
{
    //freopen("in.in" , "r" , stdin) ; 
    cin>>n>>m>>q; 
    for(int i = 0 ; i < n-1 ; i++)
    {
        int a, b ; 
        cin>>a>>b ; 
        adj[a].push_back(b) ; 
        adj[b].push_back(a) ; 
    }
    dfs(1 , 1) ; 
    for(int i = 0 ; i<m ; i++)
    {
        cin>>a[i] ; 
        vls[a[i]] .insert(i) ; 
        if(i) 
        {
            int lc = lca(a[i] , a[i-1] ) ;
            lcaA[i] = lc; 
            lcas[lc].insert(i); 
        }
    }
    while(q--)
    {
        int idx , A , B; 
        cin>>idx>>A>>B ; 

        if(idx==1)
        {   
             vls[a[A-1]].erase( A-1 );
            a[A-1] = B; 
            vls[B].insert(A-1);
            if(A>1)
            {
                lcas[ lcaA[ A-1 ] ] .erase(A-1) ; 
                int lc = lca(a[A-1] , a[A-2]) ; 
                lcaA[A-1] = lca(a[A-1] , a[A-2]) ; 
                lcas[lc].insert(A-1) ; 
            }
            if(A<m)
            {
                lcas[lcaA[A]].erase(A);
                int lc = lca(a[A] , a[A-1]) ; 
                lcas[lc].insert(A) ; 
                lcaA[A] = lca(a[A] , a[A-1]) ;
            }
        }
        else
        {
            int C; 
            cin>>C ; 
            int l = st[C] , r = en[C] ;  
            int nodeA = -2 , nodeB = -2;
            set<int>::iterator u = lcas[C].lower_bound(A) ;
            set<int>::iterator u1 = vls[C].lower_bound(A-1) ;
            if(u!=lcas[C].end())
            {
                if(*u<=B-1)
                {
                    nodeA = (*u) -1 ;
                    nodeB = *u;
                }
            }
            if(u1!=vls[C].end())
            {
                if(*u1<=B-1)
                {
                    nodeA = nodeB = (*u1) ;
                }
            }   
            cout<<nodeA+1<<" " <<nodeB+1<<"\n" ; 
        }
        
    }
    return 0 ;  
}

