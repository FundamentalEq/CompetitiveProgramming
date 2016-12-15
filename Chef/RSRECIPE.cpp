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
const int L = 65540 ;
vector<pii> ad[L] ;
bool done[L],impos ;
ll pre[L] ;
void dfs(int x)
{
    done[x] = true ;
 //   cout<<"incoming : "<<x<<" : "<<pre[x]<<endl ;
    for(auto &v:ad[x]) 
    {
        if(done[v.f])   impos = (pre[v.f]!=(pre[x] + v.s)) ;
        else pre[v.f] = pre[x] + v.s , dfs(v.f) ;
        if(impos) return ;
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,u,v,w ; cin>>N>>M ;
    while(M--) cin>>u>>v>>w,ad[u-1].pb({v,w}) ,ad[v].pb({u-1,-w}) ;
    dfs(0) ;FEN(i,N) if(!done[i]) dfs(i) ;
    if(impos) cout<<-1 ;
    else FEN(i,N) cout<<(ll)(pre[i] - pre[i-1])<<" " ; cout<<endl ;
    return 0 ;
}
