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
const int L = 1e3+5 ;
vi ad[L] ;
bool gov[L] ,done[L];
int dfs(int x)
{
    int s = 1 ; done[x] = 1 ;
    for(auto v:ad[x]) if(!done[v]) s += dfs(v) ;
    return s ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,K,a,b,c ;
    cin>>N>>M>>K ;
    FEN(i,K) cin>>c, gov[c] = true ;
    FEN(i,M) cin>>a>>b, ad[a].pb(b),ad[b].pb(a) ;
    ll ans = 0 ,s ;
    vi online ;
    FEN(i,N) if(gov[i])
    {
        s = dfs(i) ;
        online.pb(s) ;
    }
    FEN(i,N) if(!done[i]) ans += dfs(i) ;
    sort(online.begin(),online.end()) ;
    online[sz(online)-1] += ans ;
    ans = 0 ;
    for(auto x:online)
    {
        s = x ;
        ans += (x*(x-1))/2 ;
    }
    ans -= M ;
    cout<<ans<<endl ;
    return 0 ;
}
