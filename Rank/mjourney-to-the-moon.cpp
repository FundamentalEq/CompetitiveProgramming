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
vi ad[L] ;bool done[L] ;
ll nc2(ll x) { return (x*(x-1))/2 ; }
int dfs(int x)
{
    int sz = 0 ;done[x] = true ;
    for(auto v:ad[x]) if(!done[v]) sz += dfs(v) ;
    return sz + 1 ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,I,u,v ; ll ans ;
    cin>>N>>I ;
    ans = nc2(N) ;
    while(I--) cin>>u>>v , ad[u+1].pb(v+1),ad[v+1].pb(u+1) ;
    FEN(i,N) if(!done[i]) ans -= nc2(dfs(i)) ;
    cout<<ans<<endl ;
    return 0 ;
}
