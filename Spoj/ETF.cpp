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
ll euler_totient(ll M)
{
	ll ans=M ;
	for(ll p=2;p*p<=M;++p) if(M%p==0)
	{
		while(M%p==0) M/=p ;
		ans -= ans/p ;
	}
	if(M>1) ans -= ans/M ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ; cin>>T ;
	while(T--)
	{
		ll N ; cin>>N ;
		cout<<euler_totient(N)<<endl ;
	}
	return 0 ;
}
