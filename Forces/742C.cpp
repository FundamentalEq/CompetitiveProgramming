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
const int L = 105 ;
const int inf = 1e6 ;
int dis[L][L] ;
ll p2[32] ;
ll combine(ll x,ll y)
{
    if(x == -1) return y ;
    return (x*y)/__gcd(x,y) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	p2[0] = 1 ; FEN(i,31) p2[i] = 2*p2[i-1] ;
    int N ,temp ; cin>>N ;
    FEN(i,N) FEN(j,N) dis[i][j] = inf ;
    //FEN(i,N) dis[i][i] = 0 ;
    FEN(i,N) cin>>temp , dis[i][temp] = 1 ;
    FEN(k,N) FEN(i,N) FEN(j,N) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]) ;
    ll t = -1 ; bool ans = true ;
    FEN(i,N) 
    {
        if(dis[i][i] >= inf ) ans = false ;
        else 
        {
            if(dis[i][i]%2 == 0)  t = combine(t,dis[i][i]>>1) ;
            else t = combine(t,dis[i][i]) ;
        }
    }
    if(!ans) cout<<-1<<endl ;
    else cout<<t<<endl ;
    return 0 ;
}
