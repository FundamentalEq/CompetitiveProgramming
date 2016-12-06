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
#define pll pair<ll,ll>
const int mod = 1e9+7 ;
const int L = 1e5+5;
const int LGMAX = (int)ceil(log2((db)1e9+5)) ;
pll seg[4*L] ,U[4*L] ;
pll IN[L] ;
ll power_2[LGMAX][2][2] ;
void mult(ll A[2][2],ll B[2][2],ll C[2][2])
{
	FN(i,2)FN(j,2) C[i][j]=0 ;
	FN(i,2)FN(j,2)FN(k,2) C[i][j] = (C[i][j]+A[i][k]*B[k][j])%mod ;
}
ll fabonacci(int x)
{
	if(x==0) return 0 ;
	if(x==1) return 1 ;
	--x ;
	ll ans[][2]={{1,0},{0,1}} ;
	ll temp[2][2] ;
	for(int i=0;x>0;++i,x>>=1) if(x&1)
	{
		mult(ans,power_2[i],temp) ;
		FN(a,2) FN(b,2) ans[a][b]=temp[a][b] ;
		cout<<i<<endl<<"curent fab is "<<ans[0][0]<<" at i "<<i<<endl ;
	}
	return ans[0][0] ;
}
pll combine(pll X,pll Y)
{
	ll f = (Y.s - Y.f + mod)%mod ;
	pll ans ;
	ans.f = ((X.s*Y.f)%mod + (f*X.s)%mod )%mod ;
	ans.s = ((X.s*Y.s)%mod + (Y.f*X.f)%mod)%mod ;
	return ans ;
}
pll add(pll A,pll B){return mp((A.f+B.f)%mod,(A.s+B.s)%mod);}
pll build(int l,int r,int i)
{
	U[i]=mp(0,1) ;
	if(l==r) return seg[i]=IN[l] ;
	int m = (l+r)>>1 ;
	return seg[i]=add(build(l,m,i<<1),build(m+1,r,i<<1|1)) ;
}
void apply(int l,int r,int i)
{
	seg[i] = combine(seg[i],U[i]) ;
	if(l!=r) U[i<<1]=combine(U[i<<1],U[i]) ,U[i<<1|1]=combine(U[i<<1|1],U[i]) ;
	U[i]=mp(0,1) ;
}
pll query(int l,int r,int i,int s,int e)
{
	cout<<"l = "<<l<<" r= "<<r<<endl;
	apply(l,r,i) ;
	if(e<l||s>r) return mp(0,1) ;
	if(s<=l&&r<=e) return seg[i] ;
	int m = (l+r)>>1 ;
	return add(query(l,m,i<<1,s,e),query(m+1,r,i<<1|1,s,e)) ;
}
pll upd(int l,int r,int i,int s,int e,pll val)
{
	if(e<l||s>r) {apply(l,r,i); return seg[i];}
	if(s<=l&&r<=e)
	{
		U[i]=combine(U[i],val) ; apply(l,r,i) ;
		return seg[i] ;
	}
	int m = (l+r)>>1 ;
	return seg[i]=add(build(l,m,i<<1),build(m+1,r,i<<1|1)) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	power_2[0][0][0]=power_2[0][0][1]=power_2[0][1][0]=1 ;
	FEN(i,LGMAX-1) mult(power_2[i-1],power_2[i-1],power_2[i]) ;
	int N,M,temp ; cin>>N>>M ;
	FEN(i,N) cin>>temp ,IN[i].f=fabonacci(temp),IN[i].s=fabonacci(temp+1) ;
	build(1,N,1) ;
	int t,l,r ;
	while(M--)
	{
		cin>>t>>l>>r ;
		if(t==1)
		{
			int x ; cin>>x ;
			upd(1,N,1,l,r,mp(fabonacci(x),fabonacci(x+1))) ;
		}
		else cout<<query(1,N,1,l,r).f<<endl ;
	}
	return 0 ;
}
