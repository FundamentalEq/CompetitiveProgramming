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
const int L = 3e3+5 ;
ll IN[L] ,dp[L][L] ;
set<int> X ;
vi U ;
ll fans(int i,int j)
{
	if(dp[i][j]!=-1) return dp[i][j] ;
	if(i==1 && j==0) return dp[i][j]=abs(IN[1]-U[0]) ;
	if(i==1) return dp[i][j]=min(fans(i,j-1),abs(IN[i]-U[j])) ;
	if(j==0) return dp[i][j]=abs(IN[i]-U[j])+fans(i-1,j) ;
	return dp[i][j]=min(fans(i,j-1),fans(i-1,j)+abs(IN[i]-U[j])) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>IN[i];
	FEN(i,N) IN[i] -= (i-1),X.insert(IN[i]) ;
	FA(it,X) U.pb(*it) ;
	FEN(i,N) FN(j,sz(U)) dp[i][j]=-1 ;
	cout<<fans(N,sz(U)-1)<<endl ;
	return 0 ;
}
