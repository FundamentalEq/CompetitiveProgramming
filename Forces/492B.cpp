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
db A[1005] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,L ; cin>>N>>L ;
	FN(i,N) cin>>A[i] ;
	sort(A,A+N) ;
	db ans=A[0] ;
	FN(i,N-1) ans=max(ans,(A[i+1]-A[i])/2) ;
	ans=max(ans,L-A[N-1]) ;
	cout<<setprecision(9)<<ans<<endl ;
	return 0 ;
}
