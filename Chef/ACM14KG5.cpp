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
typedef long long ll;
#define db long double
using namespace std ;
const int L = 2e5+5 ;
const ll M = 1e9+7 ;
int T,N,K ;
ll fac[L] ,ifac[L];
ll pw(ll x,ll y)
{
	if(x%M==0) return 0LL ; x%=M ;
	ll ans=1 ;
	while(y){ if(y&1) ans=(ans*x)%M ; x=(x*x)%M ; y>>=1 ;}
	return ans ;
}
// ll fans(ll r, int N)
// {
// 	ll ans = fac[r+N-2] ;
// 	ans = (ans * ifac[N-1])%M ;
// 	ans = (ans * ifac[r-1])%M ;
// 	return ans ;
// }
ll f2(ll r,int N)
{
	ll ans = fac[N+r-1] ;
	ans = (ans * ifac[r-1])%M ;
	ans = (ans * ifac[N])%M ;
	return ans ;
}
ll ft(int K,int x,int mn)
{
	// cout<<"incoming "<<K<<" and "<<x<<endl ;
	ll l = ll(K) / ll(x+1) + 1; l = max(l, ll(mn));
	//int l = K/(x+1) + 1 ; l = max(l,mn) ;
	ll r = ll(K)/ll(x);
	//int r = K/x ;
	// cout<<" ans is "<<r-l+1<<endl ;
	return max(r-l+1,0LL) ;
}
int main()
{
	fac[0]=1 ; ifac[0] = pw(1,M-2) ;
	FEN(i,L -1) fac[i] = (fac[i-1]*i)%M , ifac[i] = pw(fac[i],M-2) ;
	scanf("%d",&T);
	ll ans ;
	while(T--)
	{
		ans = 0LL ;
		scanf("%d %d",&N,&K);
		if(N==1)
		{
			cout<<-1<<endl ;
			continue ;
		}
		int i=1 ;
		while(K/i >= i) ans = (ans + f2(i,N-1))%M,++i ;
		// cout << "answer after first part "<< ans << endl;
		for(int j=1; (ll)j*(ll)j<(ll)K ; ++j)
		ans = (ans + ((f2(j,N-1) * ft(K,j,i))%M) )%M ;
		printf("%lld\n",ans);
	}
	return 0 ;
}
