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
pii IN[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	ll N,R,avg ; cin>>N>>R>>avg ;
	avg*=N ;
	ll sum=0 ;
	FN(i,N) cin>>IN[i].s>>IN[i].f ,sum+=IN[i].s ;
	sort(IN,IN+N) ;
	ll ans=0,indi=0 ;
	while(sum<avg)
	{
		if(avg-sum<=R-IN[indi].s) ans +=(avg-sum)*IN[indi].f , sum=avg;
		else ans += (R-IN[indi].s)*IN[indi].f ,sum+=R-IN[indi].s ;
		indi++ ;
	}
	cout<<ans<<endl ;
	return 0 ;
}
