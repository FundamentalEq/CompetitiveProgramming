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
#define inf LLONG_MAX 
using namespace std ;
const int L = 1e5+5 ;
string IN[L] ;
int C[L] ;
ll dp[L][4] ;
ll add(ll x,ll y)
{
	if(x==inf ||y==inf) return inf ;
	return x+y ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FN(i,N) cin>>C[i] ;
	FN(i,N) cin>>IN[i] ;
	dp[0][2]=dp[0][3]=C[0] ;
	FN(i,N-1)
	{
		string ta,tb ;
		ta=IN[i],tb=IN[i+1] ;
		reverse(ta.begin(),ta.end()) ,reverse(tb.begin(),tb.end()) ;
		dp[i+1][0] = (IN[i]<=IN[i+1])?min(dp[i][0],dp[i][1]) : inf ;
		dp[i+1][1] = (ta<=IN[i+1]) ? min(dp[i][2],dp[i][3]) : inf ;
		dp[i+1][2] = (IN[i]<=tb) ? add(min(dp[i][0],dp[i][1]),C[i+1]) : inf ;
		dp[i+1][3] = (ta<=tb) ? add(min(dp[i][2],dp[i][3]),C[i+1]) : inf ;
	}
	ll ans=inf ;
	FN(i,4) ans=min(ans,dp[N-1][i]) ;
	cout<< (ll)( ans==inf ? -1 : ans)<<endl ;
	return 0 ;
}
