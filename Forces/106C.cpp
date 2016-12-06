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
const int L = 1e3+5 ;
struct tuple {int a,b,c,d ;} ;
tuple IN[15] ; int dp[15][1005] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,c,d ; cin>>N>>M>>c>>d ;
	FEN(i,M) cin>>IN[i].a>>IN[i].b>>IN[i].c>>IN[i].d ;
	return 0 ;
}
