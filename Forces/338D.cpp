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
const int L = 1e5+5 ;
ll A[L] ;
ll GcD(ll x,ll y)
{
	assert(x>=0 && y>=0) ;
	if(!x && !y) return 1 ;
	while(x&&y) x>y ? x%=y : y%=x ;
	return x+y ;
}
void eea(ll a[],ll b[])
{
	if(b[0]==0) return ;
	ll c[3],q=a[0]/b[0] ;
	c[0] = a[0] - b[0]*q ;
	c[1] = a[1] - b[1]*q ;
	c[2] = a[2] - b[2]*q ;
	FN(i,3) a[i]=b[i] ,b[i]=c[i] ;
	return eea(a,b) ;
}
// ll make(ll r,ll m)
// {
// 	 if(r>=0) return r%m ;
//
// 	 return ((abs(r)/m + 1)*m + r)%m ;
// }
ll solve(ll r1,ll m1,ll r2,ll m2)
{
	r1 = (r1%m1 + m1)%m1 ; r2 = (r2%m2 + m2)%m2 ;
	if(r2 < r1) swap(r1,r2) ,swap(m1,m2) ;
	ll x[] = {m1,1,0},y[]={m2,0,1} ;
	eea(x,y) ;
	ll delx = m2/x[0] ;
	x[1] = (x[1]%delx + delx)%delx ;
	x[1] = (x[1]*((r2-r1)/x[0]))%delx ;
	// cout<<"m1 = "<<m1<<" x[1] = "<<x[1]<<" (r2-r1) = "<<(r2-r1)<<" x[0] = "<<x[0]<<" r1 = "<<r1<<endl ;
	ll ans = m1*x[1]+ r1 ;
	// cout<<"ans is "<<ans<<endl ;
	// cout<<"ans%m1 == "<<(ans%m1)<<" r1 "<<r1<<endl ;
	assert(ans%m1 == r1) ; assert(ans%m2 == r2) ;
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll N,M; int K ; cin>>N>>M>>K ;
	FEN(i,K) cin>>A[i] ;
	ll lcm = 1 ;
	bool ans = true ;
	if(K==1)
	{
		if(A[1]<=N && A[1]<=M) cout<<"YES"<<endl ;
		else cout<<"NO"<<endl ;
		return 0 ;
	}
	FEN(i,K)
	{
		// cout<<i<<endl ;
		ll gcd = GcD(lcm,A[i]) ;
		// if(gcd<=0) {cout<<-1<<endl;return 0 ;}
		lcm = (lcm/gcd)*A[i] ;
		if(lcm > N) {ans = false ; break ;}
	}
	if(!ans)
	{
		cout<<"NO"<<endl ;
		return 0 ;
	}
	// cout<<"lcm is within bounds"<<endl ;
	ll X = A[1] ;
	ll cur = A[1] ;
	for(int i=2;i<=K;++i)
	{
		if((X+i-1)%GcD(cur,A[i])) {ans=false ; break ;}
		X = solve(X,cur,-i+1,A[i]) ;
		cur = (cur/GcD(cur,A[i]))*A[i] ;
		if(X==-1) {ans=false ; break ;}
		if(GcD(X+i-1,cur)!=A[i]) {ans=false;break;}
		// cout<<"at "<<i<<" X = "<<X<<" and cur = "<<cur<<endl ;
		if(!X) X=cur ;
	}
	// cout<<"at the end the ans is "<<ans<<endl ;
	if(X==-1 || (X+K-1)>M ) ans=false ;
	cout<<(ans?"YES":"NO")<<endl ;
	return 0 ;
}
