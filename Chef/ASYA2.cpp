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
int toS(string S)
{
	int ans = 0 ;
	FN(i,sz(S)) ans |= 1<<(S[i]-'A') ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N1,N2 ; cin>>N1>>N2 ;
	vi A,B ; string S ;
	while(N1--) cin>>S , A.pb(toS(S)) ;
	while(N2--) cin>>S , B.pb(toS(S)) ;
	S="ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	int req = toS(S) ;
	int ans=0 ;
	FN(i,sz(A)) FN(j,sz(B)) if((A[i]|B[j])==req) ++ans ;
	cout<<ans<<endl ;
	return 0 ;
}
