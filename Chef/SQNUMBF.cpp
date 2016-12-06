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
#define endl '\n'
using namespace std ;
ll A[105] ;
ll find(ll x,int c)
{
    ll lo = 0 , hi,m,ans ;
    if(c == 2 ) hi = min(x,(ll)1e9+5) ;
    else hi = min(x,(ll)1e6+5) ;
    while(hi-lo>1)
    {
        m = (lo+hi)/2 ;
        ans = 1 ; FEN(i,c) ans *= m ;
        if(ans >=x) hi = m ;
        else lo = m ;
    }
    return hi ;
}
bool perfect(ll x)
{
    if(x == 1) return false ;
    ll sq = find(x,2) ;
    return (x - sq*sq) == (ll)0 ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N ; cin>>T ;
    ll P,till ;
    while(T--)
    {
        P = 0 ;
        cin>>N ; 
        FEN(i,N) cin>>A[i] ;
        FEN(i,N) for(int j=i+1;j<=N && P == 0 ;++j) if(__gcd(A[i],A[j]) != 1 ) P = __gcd(A[i],A[j]) ;
        if(P==0)
        {
            FEN(i,N)
            {
                till = find(A[i],3) + 10  ;
                for(ll y = 1 ; y<=till && P == 0 ; ++y) 
                {
                    if(A[i]%y == 0) { if(perfect(A[i]/y)) P = find(A[i]/y,2) ; }
                    if(y>1 && (A[i]%(y*y)) == 0 ) P = y*y ;
                }
                if(P) break ;
            }
        }
        assert(P!=0 && P!=1) ;
        cout<<P<<endl ;
    }
    return 0 ;
}
