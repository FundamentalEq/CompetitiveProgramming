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
const int L =505 ;
bool ispalin[L][L] ;
int dp[L][L],C[L] ;
int fans(int i,int j)
{
	if(i>j) return 0 ;
	if(ispalin[i][j]) return 1 ;
	if(dp[i][j]!=0) return dp[i][j] ;
	int ans=INT_MAX ;
	ans=min(ans,fans(i+1,j)+1) ;
	if(C[i]==C[i+1]) ans=min(ans,fans(i+2,j)+1) ;
	for(int k=i+2;k<=j;++k) if(C[i]==C[k]) ans=min(ans,fans(i+1,k-1)+fans(k+1,j)) ;
	return dp[i][j]=ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>C[i] ;
	for(int i=N;i>=1;--i)
		for(int j=i;j<=N;++j)
			ispalin[i][j]=(i==j)|((C[i]==C[j])&(ispalin[i+1][j-1])) ;
	cout<<fans(1,N)<<endl ;
	return 0 ;
}
