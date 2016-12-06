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
const int L =2e5+5 ;
const ll mod = 1e9 +7 ;
vi ad[L] ; pii edge[L] ; int level[L] ; bool done[L] ;
int other(int x,int i)
{
	if(edge[i].f==x) return edge[i].s ;
	return edge[i].f ;
}
ll pw(ll x,ll y)
{
	if(x%mod==0) return 0 ; x%=mod ;
	ll ans=1 ;
	while(y){ if(y&1)ans=(ans*x)%mod ; x=(x*x)%mod ; y>>=1 ;}
	return ans ;
}
void solve(int x,int &size,int &len,int l=0)
{
	++size ;
	level[x]=l ;
	// cout<<"in with x = "<<x<<"and level as "<<level[x]<<endl ;
	FN(i,sz(ad[x])) if(!done[ad[x][i]])
	{
		done[ad[x][i]]=true ;
		int v=other(x,ad[x][i]) ;
		if(level[v]!=-1) len=max(abs(level[v]-level[x])+1 ,len ) ;
		else solve(v,size,len,l+1) ;
	}
}
ll fans(int x)
{
	int size=0,len=0 ;
	solve(x,size,len) ;
	// cout<<"len is "<<len<<"with size as "<<size<<endl ;
	if(len)
		return (pw(2,size) - pw(2,size-len+1)+mod)%mod ;
	return 1 ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>edge[i].f,edge[i].s=i, ad[edge[i].f].pb(i),ad[edge[i].s].pb(i) ;
	FEN(i,N) level[i]=-1 ;
	ll ans=1 ;
	FEN(i,N) if(level[i]==-1) ans=(ans*fans(i))%mod ;
	cout<<ans<<endl ;
	return 0 ;
}
