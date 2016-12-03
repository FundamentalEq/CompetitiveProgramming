#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).End(); i++)
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
const int L = 2e3+5 ;
const int mod = 1e9+7 ;
vi ad[L] , start[2*L] ,End[2*L] ;
int ct[2*L] ; bool done[L] ;
void dfs(int x)
{
	done[x]=1 ;
	for(auto v:ad[x]) if(!done[v]) dfs(v) ;
}
ll pw(ll x,ll y)
{
	if(x%mod==0) return 0 ; x%=mod ;
	ll ans=1 ;
	while(y){if(y&1)ans=(ans*x)%mod ; x=(x*x)%mod ; y>>=1 ;}
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,T,M,l,indipEndent,r;
	cin>>T ;
	while(T--)
	{
		cin>>N>>M ;
		indipEndent = 0 ;
		FEN(i,N) ad[i].clear(),done[i]=false ;
		FEN(i,2*N) start[i].clear(),End[i].clear() ;
		while(M--) cin>>l>>r , start[l].pb(l+r) ,End[r].pb(l+r) ;
		FEN(i,N)
		{
			for(auto x:start[i]) ++ct[x] ;
			FEN(j,2*N) if(ct[j]) if(j-i != i) ad[i].pb(j-i) ;
			for(auto x:End[i]) --ct[x] ;
		}
		FEN(i,N) if(!done[i]) dfs(i) , ++indipEndent ;
		cout<<pw(26,indipEndent)<<endl ;
	}
	return 0 ;
}
