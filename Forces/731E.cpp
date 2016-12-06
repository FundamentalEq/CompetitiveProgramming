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
ll pre[L],IN[L],dp[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>IN[i] , pre[i] = pre[i-1] + IN[i] ;
	dp[N] = 0 ;
	set<ll> S ; S.insert(pre[N]) ;
	for(int i=N-1;i>0;--i)
	{
		auto it =  --S.end() ;
		dp[i] = *it ;
		S.insert(pre[i]-dp[i]) ;
	}
	cout<<dp[1]<<endl ;
	return 0 ;
}
