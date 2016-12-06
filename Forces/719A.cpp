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
	int N ; cin>>N ;
	int A[100] ;
	FEN(i,N) cin>>A[i] ;
	string ans="-1" ;
	if(N==1)
	{
		if(A[1]==15) ans ="DOWN" ;
		else if(A[1]==0) ans="UP" ;
	}
	else
	{
		if(A[N]==15) ans ="DOWN" ;
		else if(A[N]==0) ans="UP" ;
		else if(A[N]>A[N-1]) ans="UP" ;
		else ans="DOWN" ;
	}
	cout<<ans<<endl ;
	return 0 ;
}
