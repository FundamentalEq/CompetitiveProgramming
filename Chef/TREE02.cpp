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
const int L = 2e4+5 ;
vi ad[L] ; ll W[L],req ;
ll dfs(int x,ll &allowed,int p=-1)
{
	// cout<<" current node is "<<x<<endl ;
	// cout<<" allowed "<<allowed<<endl ;
	multiset <ll> temp ;ll tot=0 ,ret;
	for(auto i:ad[x]) if(i!=p)
	{
		ret = dfs(i,allowed,x) ;
		temp.insert(ret) , tot += ret ;
	}
	// cout<<" tot is "<<tot<<endl ;
	while(allowed<(tot+W[x]))
	{
		tot -= *temp.rbegin() ;
		temp.erase(--temp.end());
		req++ ;
	}
	return tot+W[x] ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,K ; cin>>N>>K ;
	ll mx=0 ;
	FEN(i,N) cin>>W[i],mx=max(mx,W[i]) ;
	int a,b; FEN(i,N-1) cin>>a>>b , ad[a].pb(b),ad[b].pb(a) ;
	ll lo=mx-1 , hi=2e14+5,m ;
	while(hi-lo>1)
	{
		m = (lo+hi)/2 ;
		// cout<<"lo = "<<lo<<" m = "<<m<<" hi= "<<hi<<endl ;
		req = 1 ; dfs(1,m) ;
		if(req<=K) hi=m ;
		else lo=m ;
	}
	cout<<hi<<endl ;
	return 0 ;
}
