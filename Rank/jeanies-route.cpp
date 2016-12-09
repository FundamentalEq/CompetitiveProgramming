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
const int  L = 1e5+5 ;
const int inf = 1e9 ;
vector<pii> ad[L] ; bool des[L] ; int SZ[L] ;
int dfs(int x,int p,int &sum,int &mx,int &K)
{
    int d1 = -inf ,d2 = -inf ;
    SZ[x] = des[x] ;
    for(auto &v:ad[x]) if(v.f!=p)
    {
        d1 = max(d1,dfs(v.f,x,sum,mx,K) + v.s ) ;
        if(d1>d2) swap(d1,d2) ;
        SZ[x] += SZ[v.f] ;
        if(SZ[v.f]>0 && SZ[v.f] < K) sum += v.s ;
    }
    if(d1>0) mx = max(mx,d1+d2) ;
    if(d2>0 && des[x] ) mx=max(mx,d2) ;
    if(des[x]) d2 = max(d2,0) ;
    return d2 ;
}
int main()
{
	std::ios::sync_with_stdio(false);
    int N,K,a,b,c ; cin>>N>>K ;
    FEN(i,K) cin>>a,des[a] = 1 ;
	FEN(i,N-1) cin>>a>>b>>c , ad[a].pb({b,c}) ,ad[b].pb({a,c}) ;
    int sum = 0 , mx = 0 ;
    dfs(1,-1,sum,mx,K) ;
    cout<<(2*sum - mx)<<endl ;
    return 0 ;
}
