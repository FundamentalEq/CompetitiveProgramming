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
const int L = 1005 ;
const int inf = 1e9+5 ;
int ans[L] ,A[L] ,N;
bool P[L] ;
void ask(vi &X)
{
    cout<<(int)sz(X)<<endl ;
    for(auto x:X) cout<<x<<" " ; cout<<endl ;
    fflush(stdout) ;
    FEN(i,N) cin>>A[i] ;
    FEN(i,N) P[i]=false ;
    for(auto x:X) P[x] = true ;
    FEN(i,N) if(!P[i]) ans[i] = min(ans[i],A[i]) ;
}
queue<pii> Q ;
vi a,b ;
void solve(int l,int r)
{
    if(l == r) return ;
    int m = (r+l)/2 ;
    for(int i=m+1;i<=r;++i) a.pb(i) ;
    for(int i=l;i<=m;++i) b.pb(i) ;
    if(m+1!=r) Q.push({m+1,r}) ;
    if(l!=m) Q.push({l,m}) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>N ;
    FEN(i,N) ans[i] = inf ;
    Q.push({1,N}) ;
    while(!Q.empty())
    {
        int l = sz(Q) ;
        a.clear() ; b.clear() ;
        while(l--) solve(Q.front().f,Q.front().s) ,Q.pop() ;
        ask(a) ;
        ask(b) ;
    }
    cout<<-1<<endl ;
    FEN(i,N) cout<<ans[i]<<" " ; cout<<endl ;
    fflush(stdout) ;
    return 0 ;
}
