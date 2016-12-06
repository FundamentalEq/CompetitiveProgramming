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
#define pdd pair<db,db>
const int L =1e5+5 ;
pdd seg[5*L] ;
db P[L] ;
pdd build(int s,int e,int i)
{
	if(s==e) return seg[i]=mp(P[s],P[s]) ;
	int m = (s+e)>>1 ;
	pdd x = build(s,m,i<<1) ,y=build(m+1,e,(i<<1)|1) ;
	// cout<<"for i "<<i<<endl<<"x = "<<x.f<<" "<<x.s<<endl<<"y = "<<y.f<<" "<<y.s<<endl ;
	seg[i].f = (x.f*y.f)/(1-((1-y.f)*x.s)) ;
	seg[i].s = y.s + ( x.s*y.f*(1-y.s)/(1-(x.s*(1-y.f))) );
	return seg[i] ;
}
pdd upd(int s,int e,int i,int I)
{
	if(I<s||I>e) return seg[i] ;
	if(s==e && s==I) return seg[i]=mp(P[I],P[I]) ;
	int m = (s+e)>>1 ;
	pdd x=upd(s,m,i<<1,I),y=upd(m+1,e,(i<<1)|1,I) ;
	seg[i].f = x.f*y.f/(1-((1-y.f)*x.s)) ;
	seg[i].s = y.s + ( x.s*y.f*(1-y.s)/(1-(x.s*(1-y.f))) );
	return seg[i] ;
}
pdd qu(int s,int e,int i,int l,int r)
{
	if(l<=s&&e<=r) return seg[i] ;
	if(e<l||s>r) return mp(-1,-1) ;
	int m = (s+e)>>1 ;
	pdd x=qu(s,m,i<<1,l,r) ,y=qu(m+1,e,(i<<1)|1,l,r) ;
	if(x.f==-1) return y ;
	if(y.f==-1) return x ;
	pdd ans ;
	ans.f = x.f*y.f/(1-((1-y.f)*x.s)) ;
	ans.s = y.s + ( x.s*y.f*(1-y.s)/(1-(x.s*(1-y.f))) );
	return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,Q ; cin>>N>>Q ;
	db a,b ;
	FEN(i,N) cin>>a>>b , P[i]=a/b ;
	build(1,N,1) ;
	int type,l,r,i ;
	while(Q--)
	{
		cin>>type ;
		if(type==1)
		{
			cin>>i>>a>>b ;
			P[i]=a/b ;
			upd(1,N,1,i) ;
		}
		else
		{
			cin>>l>>r ;
			pdd ans=qu(1,N,1,l,r) ;
			cout<<setprecision(10)<<ans.f<<endl ;
		}
	}
	return 0 ;
}
