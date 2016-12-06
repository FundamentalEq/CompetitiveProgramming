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
	ll l,r,k ; cin>>l>>r>>k ;
	vector<ll> ans ;
	ll cur=1 ;
	while(1)
	{
		if(cur>=l && cur<=r) ans.pb(cur) ;
		if(cur > LLONG_MAX/k) break ;
		cur*=k ;
		if(cur>r) break ;
	}
	if(sz(ans)==0) cout<<-1<<endl ;
	else
	{
		FA(it,ans) cout<<*it<<" " ;
		cout<<endl ;
	}
	return 0 ;
}
