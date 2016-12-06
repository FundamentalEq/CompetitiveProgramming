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
const int L = 1e5 + 5 ;
int CH[L],CN[L],ID[L],P[L],level[L],seg[4*L],SZ[L] ;
vi BA,ad[L] ;
void dfs(int x,int p=0)
{
	SZ[x]=1 ; level[x] = level[p]+1 ; P[x]=p ;
	for(auto v:ad[x]) if(v!=p) dfs(v,x) , SZ[x] += SZ[v] ;
}
void hld(int x,int &cno)
{
	if(CH[cno]==0) CH[cno]=x ;
	CN[x] = cno , ID[x] = sz(BA) , BA.pb(0) ;
	int mv=0 ;
	for(auto v:ad[x]) if(v!=P[x]) if(SZ[v]>SZ[mv]) mv=v ;
	if(mv == 0) return ;
	hld(mv,cno) ;
	for(auto v:ad[x]) if(v!=P[x] && v!=mv) hld(v,++cno) ;
}
int upd(int s,int e,int i,int x,int val)
{
	// printf("s == %d | e == %d for i == %d | x == %d\n",s,e,i,x );
	if(x<s||x>e) return seg[i] ;
	if(s==e) return seg[i]=val ;
	int m = (s+e)>>1 ;
	int tl = upd(s,m,i<<1,x,val) ,tr=upd(m+1,e,i<<1|1,x,val) ;
	return seg[i] = level[tl] <= level[tr] ? tl:tr ;
}
int qur(int s,int e,int i,int l,int r)
{
	// printf("s == %d | e == %d for l == %d | r == %d\n",s,e,l,r );
	if(r<s||e<l) return 0 ;
	if(l<=s && e<=r) return seg[i] ;
	int m = (s+e)>>1 ;
	int tl = qur(s,m,i<<1,l,r) ,tr=qur(m+1,e,i<<1|1,l,r) ;
	return level[tl]<=level[tr] ? tl:tr ;
}
int fans(int v)
{
	int u = 1 ,uc = CH[CN[u]],vc,ans=0,q ;
	do
	{
		vc = CH[CN[v]] ;
		// printf("currently  v = %d && vc = %d\n",v,vc) ;
		q = qur(0,sz(BA)-1,1,ID[vc],ID[v]) ;
		ans = level[ans]<=level[q] ? ans:q ;
		v= P[vc] ;
	}while(uc!=vc) ;
	return ans==0?-1:ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,Q,a,b,chain=0 ; cin>>N>>Q ;
	FN(i,N-1) cin>>a>>b ,ad[b].pb(a),ad[a].pb(b);
	level[0]=-1 ; dfs(1) ; hld(1,chain) ;
	level[0] = N+1 ;
	while(Q--)
	{
		cin>>a>>b ;
		if(!a)
		{
			BA[ID[b]] = BA[ID[b]] == 0 ? b :0 ;
			upd(0,sz(BA)-1,1,ID[b],BA[ID[b]]) ;
		}
		else cout<<fans(b)<<endl ;
	}
	return 0 ;
}
