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
int dp[1005][105] ,K,M,PM[1005],PK[1005] ;
inline int addK(ll x,ll y){return (x+y)%K ;}
inline int addM(ll x,ll y){return (x+y)%M ;}
inline int mulK(ll x,ll y){return (x*y)%K ;}
inline int mulM(ll x,ll y){return (x*y)%M ;}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,ans=0 ; cin>>N>>K>>M ;
	PM[0] = PK[0] = 1 ; FEN(i,N) PM[i] = mulM(PM[i-1],10),PK[i] = mulK(PK[i-1],10) ;
	FEN(i,9) dp[1][i%K] = addM(dp[1][i%K],1) ;
	FEN(i,N)
	{
		if(i == 1) FEN(j,9) dp[i+1][mulK(j,PK[i])] = addM(dp[i+1][mulK(j,PK[i])],1) ;
		FEN(k,K-1) FEN(j,9) dp[i+1][addK(k,mulK(j,PK[i]))] = addM(dp[i+1][addK(k,mulK(j,PK[i]))],dp[i][k]) ;
		if(i == N) ans = addM(ans,dp[N][0]) ;
		if(i == N-1) ans = addM(ans,mulM(dp[i][0],9)) ;
		if(i < N-1) ans = addM(ans,mulM(dp[i][0],mulM(9,PM[N-i-1]))) ;
	}
	cout<<ans<<endl ;
	return 0 ;
}
