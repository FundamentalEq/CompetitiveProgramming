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
const int L = 505 ;
ll IN[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N ;ll mn,lc ; cin>>T ;
	while(T--)
	{
		cin>>N ;
		mn = LLONG_MAX ;
		FEN(i,N) cin>>IN[i] ;
		FEN(i,N) for(int j=i+1;j<=N;++j)
		{
			lc = (IN[i]/__gcd(IN[i],IN[j]))*IN[j] ;
			mn = min(mn,lc) ;
		}
		cout<<mn<<endl ;
	}
	return 0 ;
}
