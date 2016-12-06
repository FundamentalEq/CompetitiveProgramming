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
const int L = 4e5+5 ;
vi ad[L] ; int SZ[L],treeno[L],treeHead[L] ; bool ans[L] ;
multiset< pii > store ;
int dfs_sz(int x,int p=-1,int subtree=0)
{
	SZ[x]=1 ; treeno[x]=subtree ;
	FN(i,sz(ad[x])) if(ad[x][i]!=p)SZ[x] += dfs_sz(ad[x][i],x,subtree) ;
	return SZ[x] ;
}
int dfs_ct(int x,int v,int p=-1)
{
	int mxv = 0  ;
	FN(i,sz(ad[x])) if(ad[x][i]!=p) if(SZ[ad[x][i]]>SZ[mxv]) mxv = ad[x][i] ;
	if(SZ[mxv]>SZ[v]/2) return dfs_ct(mxv,v,x) ;
	return x ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,u,v ; cin>>N ;
	FN(i,N-1) cin>>u>>v,ad[u].pb(v),ad[v].pb(u) ;
	if(N==2)
	{
		cout<<"1 1"<<endl ;
		return 0 ;
	}
	dfs_sz(1) ;
	int center = dfs_ct(1,1) ;
	// cout<<"center is "<<center<<endl ;
	int subtree=1;	SZ[center]=1 ; ans[center]=true ;
	FN(i,sz(ad[center]))
	{
		SZ[center] += dfs_sz(ad[center][i],center,subtree) ;
		treeHead[subtree]=ad[center][i] ;
		store.insert(mp(SZ[ad[center][i]],subtree++)) ;
		// cout<<ad[center][i]<<" "<<SZ[ad[center][i]]<<" "<<subtree-1 <<endl ;
	}
	FEN(i,N) if(i!=center)
	{
		multiset<pii>::reverse_iterator it = store.rbegin() ;
		while(it->s == treeno[i]) ++it ;
		int mx_sz = it->f ;
		// cout<<i<<" "<<SZ[i]<<" "<<mx_sz<<" "<<treeno[i]<<endl ;
		if(N-SZ[i]-mx_sz <= N/2 || SZ[treeHead[treeno[i]]]==(N+1)/2) ans[i]=true ;
	}
	FEN(i,N) cout<<ans[i]<<" "; cout<<endl ;
	return 0 ;
}
