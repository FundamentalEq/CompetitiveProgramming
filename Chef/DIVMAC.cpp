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
const int LL = 1e6+5 ;
pii seg[4*L] ; int A[L] , lpd[LL] ;
void build(int s,int e,int i)
{
	// cout<<"s = "<<s<<" e = "<<e<<endl ;
	if(s==e)
	{
		if(A[s]==1) seg[i]={1,0}  ;
		else seg[i]={lpd[A[s]],1} ;
		return ;
	}
	int m = (s+e)>>1 ;
	build(s,m,i<<1) ,build(m+1,e,i<<1|1) ;
	seg[i] = { max(seg[i<<1].f,seg[i<<1|1].f) , seg[i<<1].s + seg[i<<1|1].s} ;
}
int qur(int s,int e,int i,int l,int r)
{
	if(l<=s && e<=r) return seg[i].f ;
	if(e<l || s>r) return 1 ;
	int m = (s+e)>>1 ;
	return max(qur(s,m,i<<1,l,r),qur(m+1,e,i<<1|1,l,r)) ;
}
void upd(int s,int e,int i,int l,int r)
{
	if(!seg[i].s||e<l||s>r) return ;
	if(s==e)
	{
		A[s] = A[s] / seg[i].f ;
		if(A[s]==1) seg[i]={1,0} ;
		else seg[i].f = lpd[A[s]] ;
		return ;
	}
	int m = (s+e)>>1 ;
	upd(s,m,i<<1,l,r) ,upd(m+1,e,i<<1|1,l,r) ;
	seg[i] = { max(seg[i<<1].f,seg[i<<1|1].f) , seg[i<<1].s + seg[i<<1|1].s} ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	lpd[2]=2 ; for(int i=4;i<LL;i+=2) lpd[i]=2 ;
	for(int i=3;i<LL;i+=2) if(!lpd[i])
	{
		lpd[i]=i ;
		for(int j=i<<1 ; j< LL ; j+=i) if(!lpd[j]) lpd[j]=i ;
	}
	int T,N,M,t,l,r ; cin>>T ;
	while(T--)
	{
		cin>>N>>M ;
		FEN(i,N) cin>>A[i] ;
		build(1,N,1) ;
		while(M--)
		{
			cin>>t>>l>>r ;
			if(t) cout<<qur(1,N,1,l,r)<<" " ;
			else upd(1,N,1,l,r) ;
		}
		cout<<endl ;
	}
	return 0 ;
}
