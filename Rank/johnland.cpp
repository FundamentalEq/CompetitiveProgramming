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
vector<pii> ad[L] ;    
vector< pair< pii,int> > edges ;
vector<ll> ans ;
struct comp{ bool operator()(pair<pii,int> a,pair<pii,int>b) { return a.s < b.s ; } };
int dsu[L],child[L] ; 
int fp(int x) {  if(!dsu[x]) return x ;  return dsu[x] = fp(dsu[x]) ;}
int dfs(int x,int N,int p = -1)
{
    int SZ = 1 ,tsz;
    for(auto &v:ad[x]) if(v.f!=p) 
    {
        tsz= dfs(v.f,N,x) ; SZ += tsz ;
        ans[v.s] = (ll)tsz*(ll)(N-tsz) ;
    }
    return SZ ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,a,b,c ;
    cin>>N>>M ;
    ans.resize(M+100,0) ;
    FEN(i,M)cin>>a>>b>>c , edges.pb({{a,b},c}) ;
    sort(edges.begin(),edges.end(),comp()) ;
    FEN(i,N) child[i] = 1 ;
    for(auto &e:edges)
    {
        a = fp(e.f.f) , b = fp(e.f.s) ;
        if(a == b) continue ;
        if(child[a] > child[b]) swap(a,b) ;
        dsu[a] = b ,child[b] += child[a] ;
        ad[e.f.f].pb({e.f.s,e.s}) , ad[e.f.s].pb({e.f.f,e.s}) ;
    }
    dfs(1,N) ;
    int last = -1 ;
    FN(i,M+99) 
    {
        ans[i+1] += ans[i]/2 ,ans[i] %=2 ;
        if(ans[i]) last = i ;
    }
    for(int i=last;i>=0;--i) cout<<ans[i] ;  cout<<endl ;
    return 0 ;
}
