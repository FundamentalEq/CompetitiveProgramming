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
const int L = 1e6+5 ;
int mobious[L] , ct[L] ;ll dp[L] ;
void MobiousFunction(int limit)
{
    ll temp ;
    mobious[1] = 2 ;
    for(int i=2;i<=limit;++i) if(!mobious[i])
    {
        mobious[i] = 1 ;
        temp = (ll)i*(ll)i ;
        if(temp<=limit) for(int j=temp ;j<=limit;j+=temp) mobious[j]=-1 ;
        for(int j = i<<1;j<=limit;j+=i) if(mobious[j]!=-1) ++mobious[j] ;
    }
    FEN(i,limit) 
    {
        if(mobious[i]==-1) mobious[i]=0 ;
        else mobious[i] = (mobious[i]&1)?-1:1 ; 
    }
}
ll nc3(ll x){ return ( x*(x-1)*(x-2) )/ 6 ; }

int main()
{
	std::ios::sync_with_stdio(false);
	MobiousFunction(L-1) ;
    int N,temp ; cin>>N ;
    FEN(i,N) cin>>temp , ++ct[temp] ;
    FEN(i,L-1) for(int j=i;j<L;j+=i) dp[i] += ct[j] ;
    ll ans = 0 ;
    FEN(i,L-1) ans += mobious[i]*nc3(dp[i])  ;
    cout<<ans<<endl ;
    return 0 ;
}
