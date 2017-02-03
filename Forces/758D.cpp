#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define f first
// #define s second
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define db long double
using namespace std ;
string K ;
ll fval(int l,int r)
{
	ll ans = 0 ;
	l = max(0,l+1) ;
	while(l<=r) ans = ans*10 + K[l++] - '0' ;
	return ans ;
}
int flen(int x) { int ans = 0 ; while(x) ++ans,x/=10 ; return ans ;}
int main()
{
	std::ios::sync_with_stdio(false);
	ll N,mul = 1 , ans = 0; cin>>N>>K ;
	int len = flen(N) ;
	int l = sz(K)-2,r = sz(K)-1,d ;
	for(int i = sz(K) - 1 ; i>=0 ; --i)
	{
		if( fval(l-1,r) < N && r - l + 1 <= len ) --l ;
		else
		{
			d = l ;
			while(K[d+1] == '0' && r-d>1) ++d ;
			ans += fval(d,r)*mul ;
			mul *= N ;
			r = d ;
			++i ;
		}
	}
	if(l<r) ans += fval(-1,r)*mul ;
	cout<<ans<<endl ;
	return 0 ;
}
