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
const ll mod = 1e9+7 ;
const int L = 1e6+5 ;
const int L2 = 1e5+5 ;
const int p = 113 ;
const int p2 = 107 ;
int  val[L],val2[L] , pw[L2],pw2[L2] ,fac[L] ;
int G[L2] ;
inline int mult(ll x,ll y)
{
    return (x*y)%mod ;
}
inline int add(ll x,ll y) { return (x+y)%mod ; }
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL) ;
	pw[0] = 1 ; FEN(i,L2-1) pw[i] = mult(pw[i-1],p) ;
	pw2[0] = 1 ; FEN(i,L2-1) pw2[i] = mult(pw2[i-1],p2) ;
    fac[0] = 1 ; FEN(i,L-1) fac[i] = mult(fac[i-1],i) ;
    int N,M,g,ct ; cin>>N>>M ;
    FEN(n,N)
    {
        cin>>g ;
        FN(i,g) cin>>G[i] ; sort(G,G+g) ;
        FN(i,g) 
        {
            if(i == 0) ct = 1 ;
            else if(G[i] == G[i-1]) ++ct ;
            else
            {
                val[G[i-1]] = add( val[G[i-1]] , mult(ct,pw[n]) ) ;
                val2[G[i-1]] = add( val2[G[i-1]] , mult(ct,pw2[n]) ) ;
                ct = 1 ;
            }
        }
        val[G[g-1]] = add(val[G[g-1]] ,mult(ct,pw[n])) ;
        val2[G[g-1]] = add(val2[G[g-1]] ,mult(ct,pw2[n])) ;
    }
    vector<pii> online ; int ans = 1 ;
    FEN(i,M) online.pb({val[i],val2[i]}) ;
    sort(online.begin(),online.end()) ;
    FN(i,sz(online))
    {
        if(i == 0) ct = 1 ;
        else if(online[i] == online[i-1]) ++ct ;
        else 
        {
            ans = mult(ans,fac[ct]) ;
            ct = 1 ;
        }
    }
    ans = mult(ans,fac[ct]) ;
    cout<<ans<<endl ;
    return 0 ;
}
