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
const int L = 1e5+5 ;
const int sqL = 320 ;
int store[sqL][L] , inc[sqL][sqL];
int A[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,U,a,b,limit ; cin>>N>>U  ;
	limit = ceil(sqrt(N)) ;
	while(U--)
	{
		cin>>a>>b ;
		if(a>=limit) for(int i=b;i<=N;i+=a) ++A[i] ;
		else ++store[a][b] ;
	}
	// FEN(i,N) cout<<A[i]<<" ";
	FEN(i,N) FEN(j,limit) inc[j][i%j] += store[j][i] ,A[i]+= inc[j][i%j];
	FEN(i,N) cout<<A[i]<<" ";
	cout<<endl ;
	return 0 ;
}
