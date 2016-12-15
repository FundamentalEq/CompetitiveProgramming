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
const int mod = 1e9+7 ;
ll pw(ll x,ll y)
{
    if(x%mod == 0) return 0 ; x%=mod ;
    ll ans = 1 ;
    while(y) { if(y&1) ans=(ans*x)%mod ; x=(x*x)%mod ; y>>=1 ; }
    return ans ;
}
ll fac[505],ifac[505] ;
map<char,int> S ;
int main()
{
	std::ios::sync_with_stdio(false);
	fac[0] = ifac[1] = 1 ;
    FEN(i,500) {fac[i] = ((ll)fac[i-1] * (ll)i)%mod ; ifac[i] = pw(fac[i],mod-2);}
    int T ; string abc ;
    cin>>T ;
    while(T--)
    {
        S.clear() ;
        cin>>abc ;
        for(auto c:abc) S[c]++ ;
        int ans = fac[sz(abc)] ;
        for(auto &it:S) ans = ((ll)ans*(ll)ifac[it.s])%mod ;
        cout<<ans<<endl ;
    }
    return 0 ;
}
