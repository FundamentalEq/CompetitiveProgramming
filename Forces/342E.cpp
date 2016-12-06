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
const int L =2e5 +5 ;
const int LOGMAX = (int)ceil(log2((db)L)) + 2 ;
vi ad[L],ET;
int PC[L],SZ[L],ans[L] ;
int level[L],first_occurance[L],lca_sparse[LOGMAX][2*L] ;
bool Cfixed[L] ;
int dfs_sz(int x,int p=-1) // calculate the size of each vertex in subtree rooted at v
{
	SZ[x]=1 ;
	FN(i,sz(ad[x])) if(ad[x][i]!=p && !Cfixed[ad[x][i]]) SZ[x] += dfs_sz(ad[x][i],x) ;
	return SZ[x] ;
}
int dfs_fc(int x,int v,int p=-1) //find centeroid of tree rooted at v
{
	int mxv=0 ;
	FN(i,sz(ad[x])) if(ad[x][i]!=p&&!Cfixed[ad[x][i]]) if(SZ[ad[x][i]]>SZ[mxv]) mxv=ad[x][i] ;
	if(SZ[mxv]<=SZ[v]/2) return x ;
	return dfs_fc(mxv,v,x) ;
}
int dfs_mct(int x,int p=-1)//to make the centeroid tree
{
	// cout<<"current node whos center is is being found is "<<x<<endl ;
	dfs_sz(x,p) ;
	int center = dfs_fc(x,x,p) ; Cfixed[center]=true ;
	// cout<<"center found is "<<center<<endl ;
	PC[center] = p ;
	FN(i,sz(ad[center])) if(ad[center][i]!=p&&!Cfixed[ad[center][i]]) dfs_mct(ad[center][i],center) ;
}
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
int dis(int u,int v)
{
	int lc = lca(u,v) ;
	return level[u]+level[v]-2*level[lc] ;
}
void upd(int x)
{
	int c = x ;
	while(c!=-1)
	{
		ans[c]=min(ans[c],dis(c,x)) ;
		c=PC[c] ;
	}
}
int qur(int x)
{
	int c = x ;
	int Ans = INT_MAX ;
	while(c!=-1)
	{
		if(ans[c]!=INT_MAX) Ans = min(ans[c]+dis(x,c),Ans) ;
		c=PC[c] ;
	}
	return Ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ,M ; cin>>N>>M ;
	int a,b ; FN(i,N-1)cin>>a>>b, ad[a].pb(b),ad[b].pb(a) ;
	dfs_mct(1) ;
	// cout<<"debugging centeroid tree"<<endl ;
	// FEN(i,N) cout<<"parent of "<<i<<" in centeroid tree is "<<PC[i]<<endl  ;
	initialize_lca(N) ;
	FEN(i,N) ans[i]=INT_MAX ;
	upd(1) ;
	int t,v ;
	while(M--)
	{
		cin>>t>>v ;
		if(t==1) upd(v) ;
		else cout<<qur(v)<<endl ;
		// cout<<"debugging values stored at each node"<<endl ;
		// FEN(i,N)cout<<"current ans of "<<i<<" is "<<ans[i]<<endl ;
	}
	return 0 ;
}
