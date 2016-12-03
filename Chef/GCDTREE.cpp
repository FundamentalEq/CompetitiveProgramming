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
const int L =1e5+5 ;
vector<pii> E[L] ; vi online ;
vi ad[L] ; bool visited[L] ;
int SZ[L] ;
pii dfs(int x,int p,int l=0)
{
	pii ans = {x,l} ,ret ;
	visited[x]=true ;
	for(auto v:ad[x]) if(v!=p)
	{
		ret = dfs(v,x,l+1) ;
		if(ret.s > ans.s) ans=ret ;
	}
	return ans ;
}
ll diameter(int gcd,int cmax)
{
	for(int j=gcd;j<=cmax;j+=gcd) for(auto i:E[j]) ad[i.f].pb(i.s) ,ad[i.s].pb(i.f) ,online.pb(i.f),online.pb(i.s) ;
	int ans = 0 ; pii ret ;
	for(auto v:online) if(!visited[v])
	{
		ret = dfs(v,-1) ;
		ret = dfs(ret.f,-1) ;
		ans = max(ans,ret.s) ;
	}
	for(auto v:online) visited[v]=false ,ad[v].clear() ;
	online.clear() ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N,a,b,c,cmax=0,mx ; cin>>T ;
	ll Ans=0 ;
	while(T--)
	{
		cin>>N ; cmax=0,Ans=0 ;
		FN(i,N-1) cin>>a>>b>>c, E[c].pb({a,b}),cmax=max(c,cmax);
		FEN(i,cmax)
			for(int j=i;j<=cmax;j+=i) SZ[i] += sz(E[j]) ;
		FEN(i,cmax)
		{
			mx=0 ;
			for(int j=i<<1;j<=cmax;j+=i) mx=max(mx,SZ[j]) ;
			if(SZ[i]>mx) Ans=max(Ans,i*diameter(i,cmax)) ;
		}
		cout<<Ans<<endl ;
		FEN(i,cmax) E[i].clear(),SZ[i]=0 ;
	}
	return 0 ;
}
