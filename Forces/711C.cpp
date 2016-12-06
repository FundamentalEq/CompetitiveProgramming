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
const int L = 105 ;
ll dp[L][L][L] ,cost[L][L] , color[L];
ll add(ll x,ll y){ if(x==inf||y==inf) return inf ; return x+y ;}
int main()
{
	std::ios::sync_with_stdio(false);
	FN(i,L)FN(b,L)FN(c,L) dp[i][b][c]=inf ;
	int N,K,M ; cin>>N>>M>>K ;
	FEN(i,N) cin>>color[i] ;
	FEN(i,N) FEN(c,M) cin>>cost[i][c] ;
	if(color[1]) dp[1][1][color[1]]=0 ;
	else FEN(c,M) dp[1][1][c]=cost[1][c] ;

	for(int i=2;i<=N;++i)
	{
		if(color[i])
			FEN(b,K)
			{
				FEN(c,M) if(c!=color[i]) dp[i][b][color[i]]=min(dp[i][b][color[i]],dp[i-1][b-1][c]) ;
				dp[i][b][color[i]]=min(dp[i][b][color[i]],dp[i-1][b][color[i]]) ;
			}
		else
			FEN(b,K)
			{
				int x=-1,y=-1 ;
				FEN(c,M)
				{
					if(x==-1) x=c ;
					else if(dp[i-1][b-1][c]<=dp[i-1][b-1][x]) y=x,x=c ;
					else if(dp[i-1][b-1][c]<=dp[i-1][b-1][y]) y=c ;
				}
				FEN(c,M) dp[i][b][c]=add( min(dp[i-1][b-1][c==x?y:x],dp[i-1][b][c]) , cost[i][c] ) ;
			}
	}
	ll mn=inf ;
	FEN(c,M) mn=min(dp[N][K][c],mn) ;
	cout<< (mn==inf?-1:mn)<<endl ;
	return 0 ;
}
