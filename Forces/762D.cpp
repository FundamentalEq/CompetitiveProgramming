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
const ll inf = LLONG_MAX/100 ;
int IN[3][L] ; ll dp[3][L] ; bool visited[3][L] ;
int X[]={1,-1,0,0} ,Y[]={0,0,1,-1} ;
ll foo(int a,int b,int i,int j)
{
    if(a < 0 || a > 2 || j-b > 1 || b > j) return -inf ;
    if(visited[a][b]) return -inf ; visited[a][b] = 1 ;
    if(a == i & b == j) 
    {
        visited[a][b] = 0 ;
        return IN[i][j] ;
    }
    ll ans = -inf ;
    FN(I,4) ans = max(ans,foo(a+X[I],b+Y[I],i,j)) ;
    visited[a][b] = 0 ;
    return ans + IN[a][b] ;
}
ll foo2(int a,int i,int j)
{
    ll ans = 0 ;
    if(a == i) return IN[i][j] ;
    if(a < i)  for(int I = a;I<=i;++I) ans += IN[I][j] ;
    if(a > i)  for(int I = a ;I>=i;--I) ans += IN[I][j] ;
    return ans ;

}
int main()
{
	std::ios::sync_with_stdio(false);
    int N ; cin>>N ;
    FN(i,3) FEN(j,N) cin>>IN[i][j] ;
    dp[0][1] = IN[0][1] ;
    dp[1][1] = IN[1][1] + dp[0][1];
    dp[2][1] = IN[2][1] + dp[1][1];
    
    dp[1][0] = dp[2][0] = -inf ;
    
    for(int j=2;j<=N;++j) FN(i,3)
    {
        dp[i][j] = -inf ;
        FN(a,3) dp[i][j] = max(dp[i][j],dp[a][j-2] + foo(a,j-1,i,j)) ;
        FN(a,3) dp[i][j] = max(dp[i][j],dp[a][j-1] + foo2(a,i,j)) ;
    }
    cout<<dp[2][N]<<endl;
    return 0 ;
}
