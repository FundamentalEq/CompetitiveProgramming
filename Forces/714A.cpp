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
int main()
{
	std::ios::sync_with_stdio(false);
	ll l1,r1,l2,r2,k ; cin>>l1>>r1>>l2>>r2>>k ;
	ll x=max(l1,l2) ,y=min(r1,r2) ;
	ll ans=-1 ;
	if(x>y) ans=0 ;
	else ans=y-x+1 ;
	if(x<=k && k<=y && ans!=0) --ans ;
	cout<<ans<<endl ;
	return 0 ;
}
