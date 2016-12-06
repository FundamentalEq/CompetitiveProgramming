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
vi Q[4*L] ;
pii S[L] ; ll ans[L] ;
int N,M ;
pii up(pii cur){return {min(cur.f + N-cur.s , M),min(cur.s+M-cur.f,N)};}
pii down(pii cur){return {max(0,cur.f-cur.s),max(0,cur.s-cur.f)}; }
pii UP(pii cur){ return {max(cur.f-(N-cur.s),0),min(N,cur.s+cur.f)}; }
pii DO(pii cur){ return {min(cur.f+cur.s,M),max(0,cur.s-(M-cur.f))};}
int p(pii cur)
{
	if(cur.s==0) return cur.f ;
	if(cur.f==M) return M+cur.s ;
	if(cur.s==N) return M+N + (M-cur.f) ;
	return N+2*M + (N-cur.s) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int K ; cin>>N>>M>>K ;
	int a,b ;
	swap(N,M) ;
	FEN(i,K)
	{
		cin>>a>>b ; S[i]={a,b};
		Q[p(up(S[i]))].pb(i) ;
		Q[p(down(S[i]))].pb(i) ;
		Q[p(UP(S[i]))].pb(i) ;
		Q[p(DO(S[i]))].pb(i) ;

	}
	ll T=0 ; pii cur={0,0} ; bool u =true ,r=true ;
	int X ;
	while(1)
	{
		if(u && r)
		{
			for(auto se:Q[p(cur)]) if(!ans[se]) ans[se] = T + S[se].f - cur.f ;
			T += up(cur).f - cur.f ;
			cur = up(cur) ;
			if(cur.f == M) r=0 ;
			else u = 0 ;
		}
		else if( u&& !r)
		{
			for(auto se:Q[p(cur)]) if(!ans[se]) ans[se] = T + cur.f-S[se].f ;
			T += cur.f -UP(cur).f ;
			cur = UP(cur) ;
			if(cur.f==0) r=1 ;
			else u=0 ;
		}
		else if (!u &&r)
		{
			for(auto se:Q[p(cur)]) if(!ans[se]) ans[se] = T+S[se].f-cur.f ;
			T += DO(cur).f - cur.f ;
			cur = DO(cur) ;
			if(cur.f == M) r=0 ;
			else u=1 ;
		}
		else if(!u && !r)
		{
			for(auto se:Q[p(cur)]) if(!ans[se]) ans[se] = T+cur.f-S[se].f ;
			T += cur.f- down(cur).f ;
			cur = down(cur) ;
			if(cur.f==0) r=1 ;
			else u=1 ;
		}
		if(cur == mp(0,0) || cur == mp(0,N) || cur==mp(M,0)||cur==mp(M,N)) break ;
	}
	FEN(i,K) cout<<((ans[i])?ans[i]:-1)<<endl ;
	return 0 ;
}
