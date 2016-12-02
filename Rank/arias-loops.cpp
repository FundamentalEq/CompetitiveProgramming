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
	ll ans=1 ;
	while(y){if(y&1)ans=(ans*x)%mod ; x=(x*x)%mod; y>>=1 ;}
	return ans ;
}
ll mul(int i,int j)
{
	cout<<i<<" "<<j<<endl ;
	ll ans=1 ;
	for(int k=i;k<=j;++k) ans=(ans*k)%mod ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll N,K ; cin>>N>>K ;
	ll n = N - (((K-1)*(K-2))/2) ;
	cout<<mul(n-max(K,n-K)+1,n)<<endl ;
	cout<<pw(mul(1,min(K,n-K)),mod-2)<<endl ;
	ll ans = ( mul(max(K,n-K)+1,n)*pw(mul(1,min(K,n-K)),mod-2) )%mod ;
	cout<<ans<<endl ;
	return 0 ;
}
