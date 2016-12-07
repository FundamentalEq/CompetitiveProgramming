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
#define endl '\n'
using namespace std ;
const int L = 2e5+5 ;
vi ad[L] ;int color[L] ; bool done[L] ;
pii pairs[L] ;
void dfs(int x,int c=0)
{
    color[x] = c,done[x] = true ;
    for(auto v:ad[x]) if(!done[v]) dfs(v,c^1) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,a,b ; cin>>N ;
    FEN(i,N) cin>>a>>b, ad[a].pb(b) ,ad[b].pb(a) ,pairs[i] = {a,b};
    for(int i = 1 ;i <= 2*N ; i+=2) ad[i].pb(i+1) ,ad[i+1].pb(i) ;
    FEN(i,2*N) if(!done[i]) dfs(i) ;
    FEN(i,N) cout<<(color[pairs[i].f] + 1)<<" "<<(color[pairs[i].s] + 1)<<endl ;
    return 0 ;
}
