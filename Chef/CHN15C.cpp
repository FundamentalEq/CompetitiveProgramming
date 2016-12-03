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
const int L =105 ;
int A[L] ; int dp[L][L] ;
int fans(int i,int j,int N)
{
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j] ;
	// if(i==j) return dp[i][j]=0 ;
	// cout<<"i "<<i<<" j "<<j<<endl ;
	int li=0,gi=0,lj=0,gj=0 ;
	for(int k=1;k<i;++k)
	{
		li += (A[k]<A[i])?1:0 ;
		gi += (A[k]>A[i])?1:0 ;
		lj += (A[k]<A[j])?1:0 ;
		gj += (A[k]>A[j])?1:0 ;
	}
	for(int k=j+1;k<=N;++k)
	{
		li += (A[k]<A[i])?1:0 ;
		gi += (A[k]>A[i])?1:0 ;
		lj += (A[k]<A[j])?1:0 ;
		gj += (A[k]>A[j])?1:0 ;
	}
	// cout<<li<<" "<<lj<<" "<<gi<<" "<<gj<<endl;
	return dp[i][j]=min(fans(i+1,j,N)+min(li,gi),fans(i,j-1,N)+min(lj,gj)) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ; cin>>T;
	while(T--)
	{
		int N ; cin>>N ;
		FEN(i,N) cin>>A[i] ;
		FEN(i,N) FEN(j,N) dp[i][j]=-1 ;
		cout<<fans(1,N,N)<<endl ;
	}
	return 0 ;
}
