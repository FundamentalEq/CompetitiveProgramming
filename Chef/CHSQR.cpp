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
const int L  = 405 ;
int A[L][L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N ; cin>>T ;
	while(T--)
	{
		cin>>N ;
		int s = N/2 ,r=1;
		FEN(i,N)
		{
			r=1 ;
			FEN(j,N) A[i][(s+j-1)%N+1] = r ,r = r%N + 1 ;
			s = s%N + 1 ;
		}
		FEN(i,N){ FEN(j,N) cout<<A[i][j]<<" " ; cout<<endl ; }
	}
	return 0 ;
}
