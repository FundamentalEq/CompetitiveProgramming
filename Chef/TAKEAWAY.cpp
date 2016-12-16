#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define db long double
using namespace std ;
const int L = 2012 ;
int G[L+5][L+5] ; 
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL) ;
	set<int> S ;
    FEN(i,L)
    {
        S.clear() ;
        FEN(j,i)
        {
            S.insert(G[i-j][min(i-j,j)]) ;
            G[i][j] = G[i][j-1] ;
            while(S.find(G[i][j])!=S.end()) ++G[i][j] ;
        }
    }
   // cout<<"pre dpome"<<endl ;
    int T,N,K,temp ,xo ;
    cin>>T ;
    while(T--)
    {
        xo = 0 ;
        cin>>N>>K ;
        while(N--) cin>>temp , xo ^= G[temp][min(K,temp)] ;
        if(xo) cout<<"Nancy"<<endl ;
        else cout<<"Zeta"<<endl ;
    }
    return 0 ;
}
