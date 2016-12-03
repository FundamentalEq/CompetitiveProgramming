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
const int L = 5e4+5 ;
bool is[L] ;
vector<pii> ad[L] ;
ll ans ;
int dfs(int x,int& M,int p=-1)
{
	int ret ,valid=0;
	for(auto &v:ad[x])if(v.f!=p)
	{
		ret = dfs(v.f,M,x) ;
		ans += (ll)ret*(ll)(M-ret)*(ll)v.s ;
		valid += ret ;
	}
	if(is[x]) ++valid ;
	return valid ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N,M,u,v,l ; cin>>T ;
	while(T--)
	{
		cin>>N>>M ;
		FEN(i,N) is[i]=0,ad[i].clear() ;
		FN(i,N-1) cin>>u>>v>>l , ad[u].pb({v,l}) ,ad[v].pb({u,l}) ;
		FEN(i,M) cin>>u , is[u] = true ;
		ans = 0 ;
		dfs(1,M) ;
		if(ans == 0)
		{
			cout<<"0 1"<<endl ;
			continue ;
		}
		ll num = 2*ans ;
		ll deno = (ll)M*(ll)(M-1) + (ll)M ;
		// cout<<"num = "<<num<<" deno = "<<deno<<endl ;
		ll gc = __gcd(num,deno) ;
		num /=gc , deno /=gc ;
		cout<<num<<" "<<deno<<endl ;
	}
	return 0 ;
}
