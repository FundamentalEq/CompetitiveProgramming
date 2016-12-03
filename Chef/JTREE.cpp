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
#define inf LLONG_MAX
const int L = 1e5+5 ;
vi ad[L] ; vector< pair<int,ll> > choice[L] ; ll dp[L] ;
ll seg[5*L] ;
int N ;
// ll build(int s,int e,int i)
// {
// 	if(s==e) return seg[i]=inf ;
// 	int m = (s+e)>>1 ;
// 	return seg[i]=min(build(s,m,i<<1),build(m+1,e,i<<1|1)) ;
// }
ll upd(int s,int e,int i,int x,ll val)
{
	if(x<s||x>e) return seg[i] ;
	if(s==e) return seg[i]=val ;
	int m = (s+e)>>1 ;
	return seg[i]=min(upd(s,m,i<<1,x,val),upd(m+1,e,i<<1|1,x,val)) ;
}
ll query(int s,int e,int i,int l,int r)
{
	if(e<l || s>r) return inf ;
	if(l<=s && e<=r) return seg[i] ;
	int m = (s+e)>>1 ;
	return min(query(s,m,i<<1,l,r),query(m+1,e,i<<1|1,l,r)) ;
}
ll add(ll x,ll y)
{
	if(x==inf||y==inf) return inf ;
	assert(inf-x > y) ;
	// assert(inf -y > x) ;
	return x+y ;
}
void fans(int x,int I)
{
	FN(i,sz(choice[x]))
	{
		int l = I-choice[x][i].f; l = max(l,1) ;
		int r = I-1 ;
		dp[x] = min(dp[x], add(query(1,N,1,l,r),choice[x][i].s) ) ;
		// assert(dp[x]>=0) ;
	}
	upd(1,N,1,I,dp[x]) ;
	FN(i,sz(ad[x])) fans(ad[x][i],I+1) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int M,a,b,k,v,w ; cin>>N>>M ;
	FN(i,N-1) cin>>a>>b , ad[b].pb(a) ;
	while(M--)
	{
		cin>>v>>k>>w ;
		choice[v].pb(mp(k,w)) ;
	}
	// build(1,N,1) ;
	FEN(i,N) dp[i]=inf ; dp[1]=0 ;
	upd(1,N,1,1,0) ;
	for(auto i : ad[1]) fans(i,2) ;
	int Q,h ; cin>>Q ;
	while(Q--) cin>>h , cout<<dp[h]<<endl ;
	return 0 ;
}
