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
const int L =1e4+5 ;
vi ad[1005] ; int prev[1005] ;
ll W[L] ; int U[L],V[L]; bool C[L] ;
ll D[1005] ; bool done[L] ;
multiset< pair<ll,int> > rec ;
int other(int x,int i)
{
	if(U[i]==x) return V[i] ;
	return U[i] ;
}
ll diajsktra(int N,int M,int S,int T)
{
	rec.clear() ;
	FN(i,N) D[i]=LLONG_MAX , done[i]=false ;
	D[S]=0 ; rec.insert(mp(0,S)) ; prev[S]=-1 ;
	while(!rec.empty())
	{
		int u = rec.begin()->s  ; rec.erase(rec.begin()) ;
		// cout<<"current ver is "<<u<<" with w= "<<D[u]<<endl ;
		if(done[u]) continue ; done[u]=true ;
		if(u==T) break ;
		FN(i,sz(ad[u]))
		{
			// cout<<"edge number is "<<ad[u][i]<<"with othre as "<<other(u,ad[u][i])<<endl ;
			int v = other(u,ad[u][i]) ;
			if(done[v]) continue ;
			if(D[v] > D[u] + W[ad[u][i]])
			{
				D[v]=D[u]+W[ad[u][i]] ;
				prev[v]=ad[u][i] ;
				rec.insert(mp(D[v],v)) ;
			}
		}
	}
	return D[T] ;
}
bool fix(int N,int M,int S,int T,ll inc)
{
	int v = T ;
	while(v!=S)
	{
		int e = prev[v] ;
		if(C[e])
		{
			W[e] += inc ;
			return true ;
		}
		v=other(v,e)  ;
	}
	return false ;
}
int main()
{
	// std::ios::sync_with_stdio(false);
	int N,M,S,T; ll tot ;
	scanf("%d %d %lld %d %d",&N,&M,&tot,&S,&T) ;
	//cin>>N>>M>>tot>>S>>T ;
	FN(i,M)
	{
		//cin>>U[i]>>V[i]>>W[i] ;
		scanf("%d %d %lld",U+i,V+i,W+i) ;
		ad[U[i]].pb(i),ad[V[i]].pb(i) ;
		if(W[i]==0) W[i]=1,C[i]=true ;
	}
	ll cur ;
	while(true)
	{
		cur = diajsktra(N,M,S,T) ;
		// cout<<"cur = "<<cur<<endl ;
		if(cur>tot)
		{
			//cout<<"NO"<<endl ;
			printf("NO\n") ;
			return 0 ;
		}
		if(cur == tot) break ;
		if(!fix(N,M,S,T,tot-cur))
		{
			// cout<<"NO"<<endl ;
			printf("NO\n") ;
			return 0 ;
		}
	}
	// cout<<"YES"<<endl ;
	printf("YES\n") ;
	FN(i,M) printf("%d %d %lld\n",U[i],V[i],W[i]);//cout<<U[i]<<" "<<V[i]<<" "<<W[i]<<endl ;
	return 0 ;
}
