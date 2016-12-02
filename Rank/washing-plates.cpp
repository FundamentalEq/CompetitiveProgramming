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
const int L = 2e5+5 ;
pair<ll,ll> IN[L] ;
struct comp { bool operator()(pair<ll,ll> a,pair<ll,ll>b) { return (a.f+a.s)>(b.f+b.s); }};
int main()
{
	std::ios::sync_with_stdio(false);
	int N ,K ; cin>>N>>K ;
	FN(i,N) cin>>IN[i].f>>IN[i].s ;
	sort(IN,IN+N,comp()) ;
	ll ans=0 ;
	FN(i,K) ans += IN[i].f ;
	for(int i=K;i<N;++i) ans -= IN[i].s ;
	cout<<max(ans,(ll)0)<<endl ;
	return 0 ;
}
