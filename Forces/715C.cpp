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
const int L = 1e5 +5 ;
struct tuple {int u,v,w;};
vi ad[L] ;
int SZ[L],P[L] ; bool done[L] ;
tuple edge[L] ;
int level[L],treeno[L]; ll ans,M,MT,up[L],down[L],pw10[L] ;
map<pair<ll,int>,int>Usub  ; map<ll,int>U ;
vi cur ;
ll pw(ll y,ll x,ll mod)
{
	if(x%mod==0) return 0 ; x%=mod; assert(y>=0) ;
	ll ans=1 ;
	while(y){if(y&1)ans=(ans*x)%mod ; x=(x*x)%mod ; y>>=1 ;}
	return ans ;
}
int other(int x,int i)
{
	if(x==edge[i].u) return edge[i].v ;
	return edge[i].u ;
}
int dfs_sz(int x,int p=-1)
{
	// cout<<"finding size for node "<<x<<endl ;
	SZ[x]=1 ;
	FN(i,sz(ad[x]))
	{
		int v = other(x,ad[x][i]) ;
		if(v==p || done[v]) continue ;
		SZ[x] += dfs_sz(v,x) ;
	}
	// cout<<"size of node "<<x<<" is cal to be "<<SZ[x]<<endl ;
	return SZ[x] ;
}
int dfs_ct(int c,int x,int p=-1)
{
	int mxv=L-1 ;
	FN(i,sz(ad[c]))
	{
		int v = other(c,ad[c][i]) ;
		if(v==p || done[v]) continue ;
		if(SZ[v]>SZ[mxv]) mxv=v ;
	}
	if(SZ[mxv] > SZ[x]/2) return dfs_ct(mxv,x,c) ;
	return c ;
}
void dfs_cal(int x,ll u,ll d,int subtree,int l=1,int p=-1)
{
	// cout<<"dfs_cal is at "<<x<<" and parent is "<<p<<endl ;
	cur.pb(x) ;	up[x]=u,down[x]=d ; U[u]++ ,Usub[mp(u,subtree)]++ ;
	treeno[x]=subtree ; level[x]=l;
	FN(i,sz(ad[x]))
	{
		int v = other(x,ad[x][i]) ;
		if(v==p || done[v]) continue ;
		int di = edge[ad[x][i]].w ;
		dfs_cal(v,((pw10[l]*di)%M + u )%M,((d*10)%M + di)%M,subtree,l+1,x) ;
	}
}
void dfs_mct(int x)
{
	// cout<<"finding centeroid for "<<x<<endl ;
	dfs_sz(x) ;
	// cout<<"Size marking done successfully"<<endl ;
	int center = dfs_ct(x,x) ;
	// cout<<"center found as "<<center<<endl  ;
	U.clear() ; cur.clear() ; Usub.clear() ;
	done[center]=true ; x=center ;
	int subtree=1 ;
	FN(i,sz(ad[x]))if(!done[(other(x,ad[x][i]))])
		dfs_cal(other(x,ad[x][i]),(edge[ad[x][i]].w)%M,(edge[ad[x][i]].w)%M,subtree++,1,x) ;
	// cout<<"marking up and down successful"<<endl ;
	// cout<<"node inside cur are "<<endl ;
	// FA(it,cur) cout<<*it<<" "<<down[*it]<<" "<<up[*it]<<endl ;
	FN(i,sz(cur))
	{
		int v = cur[i] ;
		ans += up[v]==0 , ans+= down[v]==0 ;
		ll req = (down[v]*pw((level[v]/MT + 2)*MT -level[v],10,M))%M ;
		req = (-req + M)%M ;
		// cout<<"for "<<v<<" requirement is "<<req<<endl ;
		ans += U[req] - Usub[mp(req,treeno[v])] ;
		// cout<<"after processing "<<v<<" ans is "<<ans<<endl ;
	}
	// cout<<"after the above ans = "<<ans<<endl ;
	FN(i,sz(ad[x])) if(!done[other(x,ad[x][i])]) dfs_mct(other(x,ad[x][i])) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N>>M ;
	FN(i,N-1) cin>>edge[i].u>>edge[i].v>>edge[i].w , ad[edge[i].u].pb(i),ad[edge[i].v].pb(i) ;
	//calculate totient value of M

	ll temp=M ; MT=M ;
	for(ll p=2;p*p<=M;++p) if(M%p==0)
	{
		while(M%p==0) M/=p ;
		MT -= MT/p ;
	}
	if(M>1) MT -= MT/M ;
	//MT is the euler totient of M
	M=temp ;
	// cout<<"totient value of  M is "<<MT<<endl ;
	pw10[0]=1 ; FEN(i,L-1) pw10[i] = (pw10[i-1]*10)%M ;
	// cout<<"powers of 10 caluclated successfully"<<endl ;
	dfs_mct(0) ;
	cout<<ans<<endl ;
	return 0 ;
}
