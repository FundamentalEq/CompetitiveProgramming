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
int SZ[105] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,K ; string S ;
	cin>>N>>K ;
	while(N--) cin>>S , SZ[sz(S)]++ ;
	cin>>S ;
	FEN(i,sz(S)-1) SZ[i] += SZ[i-1] ;
	int mn = (SZ[sz(S)-1]/K)*5 + SZ[sz(S)-1] + 1 ;
	int mx = ((SZ[sz(S)-1]+SZ[sz(S)]-1)/K)*5 + SZ[sz(S)-1] + SZ[sz(S)] ;
	cout<<mn<<" "<<mx<<endl ;
	return 0 ;
}
