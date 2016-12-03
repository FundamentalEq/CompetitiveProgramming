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
const int mod = 1e9+7 ;
int dp[305][L] ; int fac[305] ;
int fdp(int n,int m)
{
	if(m < (n*(n+1))/2) return 0 ;
	if(n==1) return 1 ;
	if(dp[n][m]!=-1) return dp[n][m] ;
	return dp[n][m] = ((ll)fdp(n,m-n)+(ll)fdp(n-1,m-n))%mod ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	FN(i,305) FN(j,L) dp[i][j]=-1 ;
	fac[0]=1 ; FEN(i,300) fac[i] = ((ll)fac[i-1]*(ll)i)%mod ;
	int T,N,M,ans ; cin>>T ;
	while(T--)
	{
		cin>>N>>M ;
		ans = fdp(N,M) ;
		ans = ((ll)ans*(ll)fac[N])%mod ;
		cout<<ans<<endl ;
	}
	return 0 ;
}
