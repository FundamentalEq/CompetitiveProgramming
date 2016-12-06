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
const int L =1e5+5 ;
int A[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>A[i] ;
	FEN(i,N) cout<<A[i]+A[i+1]<<" " ;
	cout<<endl ;
	return 0 ;
}
