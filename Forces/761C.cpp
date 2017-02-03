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
const int inf = INT_MAX / 100 ;
int val[55][3] ;
int nu(char c)
{
	if(c>='a' && c<='z') return 0 ;
	if(c>='0' && c<='9') return 1 ;
	return 2 ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M ,ans = inf; string S ;
	cin>>N>>M ;
	FEN(i,N)
	{
		cin>>S ; FN(j,3) val[i][j] = inf ;
		FEN(j,M) val[i][nu(S[j-1])] = min(val[i][nu(S[j-1])],min(j-1,M + 1 -j)) ;
	}
	FEN(a,N) for(int b = a+1 ; b<=N;++b) for(int c = b+1;c<=N;++c)
	{
		int perm[] = {0,1,2} ;
		do
		{
			ans = min(ans,val[a][perm[0]] + val[b][perm[1]] + val[c][perm[2]]) ;
		} while(next_permutation(perm,perm+3));
	}
	cout<<ans<<endl ;
	return 0 ;
}
