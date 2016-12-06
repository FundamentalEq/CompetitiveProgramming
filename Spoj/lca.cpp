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
const int LOGMAX = (int)ceil(log2((db)L)) + 2 ;
vi ad[L] ,ET ; int level[L],first_occurance[L],lca_sparse[LOGMAX][2*L] ;
void dfs_lca(int x,int p=-1,int l=0)
{
	level[x]= l ;
	ET.pb(x);
	FN(i,sz(ad[x])) if(ad[x][i]!=p)
	{
		dfs_lca(ad[x][i],x,l+1) ;
		ET.pb(x);
	}
}
void initialize_lca(int N,int root=1)
{
	ET.clear() ;
	dfs_lca(root) ;
	FEN(i,N) first_occurance[i]=sz(ET) ;
	FN(i,sz(ET)) first_occurance[ET[i]] = min(first_occurance[ET[i]],i) ;
	FN(i,sz(ET)) lca_sparse[0][i] = ET[i] ;
	for(int j=1 ; (1<<j)<=sz(ET) ; ++j)
		for(int i=0; (i+(1<<j)-1)<sz(ET);++i)
		{
			if(level[lca_sparse[j-1][i]] < level[lca_sparse[j-1][i+(1<<(j-1))]] )
				lca_sparse[j][i] = lca_sparse[j-1][i] ;
			else lca_sparse[j][i] = lca_sparse[j-1][i+(1<<(j-1))] ;
		}
}
int lca(int u,int v)
{
	int i =first_occurance[u] , j=first_occurance[v] ;
	if(j<i) swap(i,j) ;
	int k = (int)log2(j-i+1) ;
	return level[lca_sparse[k][i]]<level[lca_sparse[k][j-(1<<k)+1]] ? lca_sparse[k][i] : lca_sparse[k][j-(1<<k)+1] ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ; cin>>T ;
	FEN(t,T)
	{
		int N ; cin>>N ;
		FEN(i,N) ad[i].clear() ;
		FEN(i,N)
		{
			int M,u ; cin>>M ;
			while(M--) cin>>u , ad[i].pb(u) ,ad[u].pb(i) ;
		}
		initialize_lca(N) ;
		int Q; cin>>Q ;
		cout<<"Case "<<t<<":"<<endl ;
		while(Q--)
		{
			int u,v ;cin>>u>>v ;
			cout<<lca(u,v)<<endl ;
		}
	}
	return 0 ;
}
