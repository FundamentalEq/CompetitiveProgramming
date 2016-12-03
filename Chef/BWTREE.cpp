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
const int L = 1e5+5 ;
const int M = 1e9+7 ;
vi ad[L] ; char C[L] ; ll dp[L] ;
ll ans=0 ;
void dfs(int x,int p=-1)
{
	dp[x]=1 ;
	for(auto v:ad[x]) if(v!=p)
	{
		dfs(v,x) ;
		if(C[x]!=C[v]) dp[x] = (dp[x]+dp[v])%M ;
	}
	ans = (ans + dp[x] )%M ;
	ll cur = 0 ;
	for(auto v:ad[x])if(v!=p)if(C[x]!=C[v])
	{
		ans = (ans + (cur*dp[v])%M )%M ;
		cur = (cur + dp[v])%M ;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,x,y ; cin>>N ;
	FEN(i,N-1) cin>>x>>y , ad[x].pb(y),ad[y].pb(x) ;
	string X ;
	FEN(i,N) cin>>X , C[i]=X[0] ;
	dfs(1) ;
	cout<<ans<<endl ;
	return 0 ;
}
