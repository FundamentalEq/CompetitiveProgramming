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
const int mod = 1e9+7 ;
const int L = 1e5+1 ;
const int MX = 2e5+101 ;
ll FW[2][2*L + 105] ;
ll A[2*L+105],B[2*L+105] ;
void upd(int x,ll c,ll tree[])
{
	x+=L ;
	tree[x] = (tree[x]+c)%mod ;
}
ll qu(int i,int j,ll tree[])
{
	i=max((int)-1e5,i) ,j=min((int)1e5+100,j) ;
	i+=L,j+=L ;
	return (tree[j]-tree[i-1]+mod)%mod ;
}
void make(int a,ll C[],int t,int k)
{
	// cout<<a<<" "<<k<<" "<<t<<endl ;
	FEN(i,MX) FW[0][i]=FW[1][i]=0 ;
	int sw=0 ;
	upd(a,1,FW[sw]) ;
	FEN(i,MX) FW[sw][i] = (FW[sw][i]+FW[sw][i-1])%mod ;
	FN(stage,t)
	{
		sw^=1 ;
		FEN(i,MX) FW[sw][i]=0 ;
		for(int i=-1e5;i<=1e5+100;++i) upd(i,qu(i-k,i+k,FW[sw^1]),FW[sw]) ;
		FEN(i,MX) FW[sw][i] = (FW[sw][i]+FW[sw][i-1])%mod ;
		// cout<<"stage is "<<stage<<endl ;
		// for(int i=-1e5;i<=1e5+100;++i) if(qu(i,i,FW[sw])!=0) cout<<"i == "<<i<<" -- "<<qu(i,i,FW[sw])<<endl ;
	}
	// for(int i=-1e5;i<=1e5+100;++i) if(qu(i,i,FW[sw])!=0) cout<<"i == "<<i<<" -- "<<qu(i,i,FW[sw])<<endl ;
	FEN(i,MX) C[i]=qu(i-L,i-L,FW[sw]) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int a,b,k,t ; cin>>a>>b>>k>>t ;
	make(a,A,t,k) , make(b,B,t,k) ;
	// for(int i=-1e5;i<=1e5+100;++i) if(A[i]!=0) cout<<" at i "<<i<<" "<<A[i]<<endl ;
	FEN(i,MX) B[i]=(B[i]+B[i-1])%mod ;
	ll ans=0 ;
	FEN(i,MX) ans=(ans + (A[i]*B[i-1])%mod)%mod ;
	cout<<ans<<endl ;
	return 0 ;
}
