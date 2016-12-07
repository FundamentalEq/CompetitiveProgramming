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
vi ad[1005] ,F[1005]; int hw[1005] ,hb[1005] , We[1005],B[1005] , dp[1005][1005] ;
bool done[1005] ;
void dfs(int x,int g)
{
    F[g].pb(x) ; done[x] = 1 ;
    B[g] += hb[x] ,We[g] += hw[x] ;
    for(auto v:ad[x]) if(!done[v]) dfs(v,g) ;
}
void mark(int i,int w,int b,int W)
{
    if(w>W) return ;
    for(int j=0;(j+w)<=W;++j) dp[i][j+w] = max(dp[i][j+w],dp[i-1][j]+b) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
    int N,M,W ; cin>>N>>M>>W ;
    FEN(i,N) cin>>hw[i] ;
    FEN(i,N) cin>>hb[i] ;
    int u,v ;
    while(M--) cin>>u>>v , ad[u].pb(v) ,ad[v].pb(u) ;
    int grp = 0 ;
    FEN(i,N) if(!done[i]) dfs(i,++grp) ;
	FEN(i,grp)
    {
        mark(i,We[i],B[i],W) ;
        for(auto f:F[i]) mark(i,hw[f],hb[f],W) ;
        FEN(j,W) dp[i][j] = max(dp[i][j],dp[i-1][j]) ;
    }
    int ans = 0 ;
    FEN(i,W) ans = max(ans,dp[grp][i]) ;
    cout<<ans<<endl ;
    return 0 ;
}
