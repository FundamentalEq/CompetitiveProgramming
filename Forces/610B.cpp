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
ll A[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	ll mn=LLONG_MAX ;
	FEN(i,N) cin>>A[i] ,mn=min(mn,A[i]) ;
	vi temp ;
	FEN(i,N)
	{
		A[i]-=mn ;
		if(A[i]==0) temp.pb(i) ;
	}
	int mx=0 ;
	FN(i,sz(temp)-1) mx=max(mx,temp[i+1]-temp[i]-1) ;
	if(sz(temp)==0) mx=N ;
	else mx=max(mx,temp[0]-1 + N-temp[sz(temp)-1]) ;
	cout<<mn*N + mx <<endl ;
	return 0 ;
}
