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
	std::ios::sync_with_stdio(false);
	int A[105] ;
	int N ; cin>>N ;
	FEN(i,N) cin>>A[i] ;
	int mn1=0 ,mn2=INT_MAX ;
	FEN(i,N-1) mn1=max(mn1,A[i+1]-A[i]) ;
	for(int i=2;i<=N-1;++i) mn2=min(mn2,A[i+1]-A[i-1]) ;
	cout<<max(mn1,mn2)<<endl ;
	return 0 ;
}
