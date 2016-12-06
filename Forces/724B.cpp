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
int A[25][25] ;
int dis(int B[],int M)
{
	int ans=0 ;
	FEN(i,M) if(B[i]!= i) ++ans ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M ; cin>>N>>M ;
	bool ans=false ;
	FEN(i,N) FEN(j,M) cin>>A[i][j] ;
	int mx= 0 ;
	FEN(i,N) mx= max(mx,dis(A[i],M)) ;
	if(mx<=2) ans=true ;
	if(!ans)
	{
		FEN(a,M) for(int b=a+1;b<=M;++b)
		{
			mx=0 ;
			FEN(i,N)
			{
				swap(A[i][a],A[i][b]) ;
				mx = max(dis(A[i],M),mx) ;
				swap(A[i][b],A[i][a]) ;
				if(mx>2) break ;
			}
			if(mx<=2) {ans=true ;break ;}
		}
	}
	cout<<(ans?"YES":"NO")<<endl ;
	return 0 ;
}
