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
const int L =205 ;
const int inf = 1e9 ;
int dp[L][2][L*L+5],H[L],A[2] ;
int add(int x,int y) { return (x==inf||y==inf)?inf:x+y ; }
int main()
{
	std::ios::sync_with_stdio(false);
	int N,used=0; cin>>N ;
	cin>>A[0]>>A[1] ;
	FEN(i,N) cin>>H[i] ;
	FEN(i,N)FN(c,2) FN(j,A[c]+1) dp[i][c][j] = inf ;
	dp[1][0][H[1]]=dp[1][1][H[1]]=0 ; used = H[1] ;
	FN(c,2) FN(j,A[c]+1)
	{
		cout<< ((dp[1][c][j]==inf)?-1:dp[1][c][j]) <<" " ;
		if(j == A[c]) cout<<endl ;
	}
	cout<<endl<<endl ;
	for(int i=2;i<=N;++i)
	{
		FN(c,2) FN(j,A[c]+1)
		{
			if(j-H[i]>=0) dp[i][c][j] = min(dp[i-1][c][j-H[i]],dp[i][c][j]) ;
			if(used + H[i] - j >=0  && used +H[i]-j <= A[c^1] )
		 	dp[i][c][j] = min(dp[i][c][j],add( dp[i-1][c^1][used + H[i] -j] ,min(H[i],H[i-1]) ) ) ;

			cout<< ((dp[N][c][j]==inf)?-1:dp[N][c][j]) <<" " ;
			if(j == A[c]) cout<<c<<" "<<i<<endl ;
		}
		used += H[i] ;
	}
	int ans = inf ;

	return 0 ;
}
