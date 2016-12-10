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
const int L = 2e5+5 ;
const int mod = 1e9+7 ;
int totient[L],A[10],B[10] ;
void EulerTotientSieve(int limit)
{
   totient[1] = 1, totient[0] = 0 ; for(int i=2;i<=limit;++i) totient[i] = i ;
   totient[2] = 1 ; for(int j=4;j<=limit;j+=2) totient[j] >>=1;
   for(int i=3;i<=limit;i+=2) if(totient[i] == i)
   {
       totient[i] =i-1 ;
       for(int j=i<<1;j<=limit;j+=i) totient[j] = totient[j] - totient[j]/i ;
   }
}
ll pw(ll x,ll y)
{
    if(x%mod == 0) return 0 ; x%=mod ;
    ll ans = 1 ;
    while(y){ if(y&1) ans = (ans*x)%mod ; x = (x*x)%mod ; y>>=1 ; }
    return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
    EulerTotientSieve(L-1) ;
    int T,K,mx ; ll nu,deno,ans,temp ;
    cin>>T ;
    while(T--)
    {
        nu = mx = 0 ; deno = 1 ; 
        cin>>K ;
        FEN(i,K) cin>>A[i]>>B[i] ,mx=max(mx,B[i]) ,deno = (deno * (ll)(B[i] -A[i] + 1))%mod;
        FEN(i,mx+2) 
        {
            temp = 1 ;
            FEN(k,K) temp = (temp *  (ll)( (B[k]/i) - ((A[k]-1)/i) ) )%mod ;
            nu = ( nu + temp*(ll)totient[i] )%mod ;
        }
        ans = (nu*pw(mod - deno,mod-2))%mod ;
      //  ans = mod - ans ;
        cout<<ans<<endl ;
    }
    return 0 ;
}
