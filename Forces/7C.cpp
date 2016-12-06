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
const ll L = 5e18 ;
ll egcd(ll a,ll b,ll &x,ll &y)
{
	if(!a) {x=0,y=1;return b ;}
	ll ret = egcd(b%a,a,y,x) ;
	x = x - (b/a)*y ;
	return ret ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll a,b,c,d,x,y,X,Y,gc,kr,kl,kr2,kl2,kr1,kl1 ;
	 cin>>a>>b>>c ; c = -c ;
	 if(!a && !b)
	 {
		 if(c) cout<<-1<<endl ;
		 else cout<<"1 1"<<endl ;
		 return 0 ;
	 }
	 if(!a)
	 {
		 if(c%b==0) cout<<"1 "<<(c/b)<<endl ;
		 else cout<<-1<<endl ;
		 return 0 ;
	 }
	 if(!b)
	 {
		 if(c%a==0) cout<<(c/a)<<" 1"<<endl ;
		 else cout<<-1<<endl ;
		 return 0 ;
	 }
	gc = egcd(a,b,x,y) ;
	// cout<<__gcd(abs(a),abs(b))<<endl ;
	if(c%gc) { cout<<-1<<endl ; return 0 ;}
	d = c/gc ;
	X = b/gc ;
	Y = a/gc ;
	// cout<<(x*d)<<" "<<(y*d)<<endl ;
	kr1 = (L - x*d)/X ; kl2 = -(L+x*d)/X ;
	kr2 = (L+y*d)/Y ; kl2 =-(L-y*d)/Y ;
	kl = max(min(kr1,kl1),min(kr2,kl2)) , kr = min(max(kr1,kl1),max(kr2,kl2)) ;
	if(kl<=kr)
	{
		// assert((x*d + kl*X)*a + b*(y*d -kl*Y) == c) ;
		cout<<(ll)(x*d + kl*X)<<" "<<(ll)(y*d -kl*Y)<<endl ;
		return 0 ;
	}
	cout<<-1<<endl ;
	return 0 ;
}
