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
const int L = 505 ;
int cur[L][L] , dp[L] ,val[L] ;
multiset< pii > store ;
int cal(int i,int M)
{
	int mx=0 ;
	FEN(j,M) dp[j] =  (cur[i][j]==1) ? dp[j-1]+1:0 ,mx=max(mx,dp[j]);
	return mx ;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,Q ; cin>>N>>M>>Q ;
	FEN(i,N) FEN(j,M) cin>>cur[i][j] ;
	FEN(i,N) val[i]=cal(i,M) ;
	int x,y ;
	while(Q--)
	{
		cin>>x>>y ;
		cur[x][y]^=1 ;
		val[x] = cal(x,M) ;
		int mx=0 ;
		FEN(i,N) mx=max(mx,val[i]) ;
		cout<<mx<<endl ;
	}
	return 0 ;
}
