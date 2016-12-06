#include <bits/stdc++.h>
#define FN(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define FEN(i,n) for (ll i = 1;i <= (ll)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define f first
#define s second
#define pii pair<ll,ll>
#define vi vector<ll>
#define ll long long
#define db long double
using namespace std ;
ll M ;
ll reach(ll A[])
{
	ll h = A[0] , a = A[1] ,x=A[2] ,y=A[3] ;
	FEN(t,M)
	{
		h = (h*x+y)%M ;
		if(h==a) return t ;
	}
	return -1 ;
}
ll find(ll A[],ll T)
{
	ll h=A[0],x=A[2],y=A[3] ;
	ll c=1 ,d=0 ;
	FN(i,T)
	{
		c = (c*x)%M ;
		d = (d*x + y)%M ;
	}
	ll ans = ( (c*h)%M + d )%M ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll A[4],B[4] ;
	cin>>M ;
	FN(i,4) cin>>A[i] ; FN(i,4)cin>>B[i] ;
	ll t1 = reach(A) ;
	if(t1==-1)
	{
		cout<<-1<<endl ;
		return 0 ;
	}
	B[0] = find(B,t1) ;
	if(B[0]==B[1])
	{
		cout<<t1<<endl ;
		return 0 ;
	}
	A[0]=A[1] ;
	ll c = reach(A) ;
	ll o = reach(B) ;
	if(c==-1 || o==-1)
	{
		cout<<-1<<endl ;
		return 0 ;
	}
	cout<<(t1 + c*o)<<endl ;
	return 0 ;
}
