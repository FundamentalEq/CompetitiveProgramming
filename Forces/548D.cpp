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
int A[L],Right[L],Left[L],ans[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>A[i] ;
	stack<int> X ;
	//find each ones Right
	X.push(1) ;
	for(int i=2;i<=N;++i)
	{
		while(!X.empty() && A[X.top()]>A[i])
		{
			Right[X.top()]=i-1 ;
			X.pop() ;
		}
		X.push(i) ;
	}
	while(!X.empty()) Right[X.top()]=N , X.pop() ;
	//find eachs Left
	X.push(N) ;
	for(int i=N-1;i>0;--i)
	{
		while(!X.empty() && A[X.top()]>A[i])
		{
			Left[X.top()] = i+1 ;
			X.pop() ;
		}
		X.push(i) ;
	}
	while(!X.empty()) Left[X.top()]=1,X.pop() ;
	FEN(i,N) ans[Right[i]-Left[i]+1]=max(ans[Right[i]-Left[i]+1],A[i]) ;
	for(int i=N-1;i>0;--i) ans[i]=max(ans[i],ans[i+1]) ;
	FEN(i,N) cout<<ans[i]<<" "; cout<<endl ;
	return 0 ;
}
