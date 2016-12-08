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
vi ad[L] ; int kick[L] , dis[L] ;
vi online , lefts ;
void mark(int N,int done,int level = 1)
{
    if(N==done) return ;
    vi a,b ; 
    for(auto x:online)
        for(auto v:ad[x]) ++kick[v] ;
    for(auto x:lefts)
    {
        if(kick[x] == done) b.pb(x) ;
        else dis[x] = level , a.pb(x) ;
    }
    online.clear() , lefts.clear() ;
    online = a , lefts = b ;
    mark(N,done + sz(online) , level + 1) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N,M,u,v,S ; cin>>T ;
    while(T--)
    {
        cin>>N>>M ;
        FEN(i,N) ad[i].clear() , kick[i] = dis[i] = 0 ;
        while(M--) cin>>u>>v, ad[u].pb(v) ,ad[v].pb(u) ;
        cin>>S ;
        FEN(i,N) if(i!=S) lefts.pb(i) ;
        online.pb(S) ;
        mark(N,1) ;
        FEN(i,N) if(i!=S) cout<<dis[i]<<" " ; cout<<endl ;
    }
    return 0 ;
}
