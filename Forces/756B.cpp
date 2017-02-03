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
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL) ;
	vi T,dp ; T.pb(-1000000000) , dp.pb(0) ;
	int N,t,sum = 0 ,c,j; cin>>N ;
	FEN(i,N)
	{
		cin>>t ; dp.pb(dp[i-1] + 20) ;
		j = lower_bound(T.begin(),T.end(),t + 1 - 90 )  - T.begin() - 1 ;
		dp[i] = min(dp[i],dp[j] + 50) ;
		j = lower_bound(T.begin(),T.end(),t + 1 - 1440 )  - T.begin() - 1 ;
		dp[i] = min(dp[i],dp[j] + 120) ;
		c = max(dp[i] - sum,0) ;
		cout<<c<<endl ;
		sum += c ;
		T.pb(t) ;
	}
	return 0 ;
}
