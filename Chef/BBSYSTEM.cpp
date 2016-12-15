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
const int L = 2229283 ;
const int mod = 5e5+9 ;
int divisors[L+5],M[L+5] ;
int A[400],ans[L+5] ;
int deg(int x,int p)
{
    int a = 0 ;
    while(x%p == 0) ++a,x/=p ;
    return a ;
}
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; 
    FEN(i,L) M[i] = i ;
    divisors[1] = 1 ;
    for(int i=2;i*i <= L ; ++i) if(M[i] == i) for(int j = i<<1;j<=L;j+=i) M[j] = min(M[j],i) ;
    for(int i=2;i<=L;++i) 
    {
        if(M[i] == i ) divisors[i] = 2 ;
        else divisors[i] = ( divisors[i/M[i]] * (deg(i,M[i]) + 1) ) / ( deg(i/M[i],M[i]) + 1) ;
    }
    ans[0] = 1 ;
    FEN(i,L) ans[i] = ((ll)ans[i-1] * (ll)(++A[divisors[i]]) )%mod ;
    //cout<<ans[L-10]<<endl ; 
    int T,N ; cin>>T ;
    while(T--) cin>>N , cout<<(int)(N>=L ? (int)(mod-1) : (int)((ans[N] -1 + mod)%mod))<<'\n' ;
    return 0 ;
}
