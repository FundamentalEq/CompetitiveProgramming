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
const int L = 2e5+5 ;
vi ad[L] ;int C[L] ;bool done[L] ;
void dfs(int x,map<int,int> &ct,int &sz)
{
	++sz , ++ct[C[x]] ,done[x]=true ;
	for(auto v:ad[x]) if(!done[v]) dfs(v,ct,sz) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int M,N,K,l,r ; cin>>N>>M>>K ;
	FEN(i,N) cin>>C[i] ;
	FEN(i,M) cin>>l>>r , ad[l].pb(r),ad[r].pb(l) ;
	map<int,int> ct ;
	int ans = 0,mx=0,sz=0 ;
	FEN(i,N) if(!done[i])
	{
		dfs(i,ct,sz) ;
		for(auto &it:ct) mx=max(mx,it.s) ;
		ans += sz-mx ;
		ct.clear() ,sz=0 ,mx=0;
	}
	cout<<ans<<endl ;
	return 0 ;
}
