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
const int L = 1e5 +5 ;
int seg[4*L][10] , U[4*L] ,temp[10];
void build(int l,int r,int i)
{
	if(l==r)
	{
		seg[i][0]=1 ;
		return ;
	}
	int m = (l+r)>>1 ;
	build(l,m,i<<1) ,build(m+1,r,(i<<1)|1) ;
	seg[i][0] = seg[i<<1][0]+seg[(i<<1)|1][0] ;
}
void upd(int l,int r,int i,int s,int e)
{
	if(U[i])
	{
		FN(j,10) temp[(j+U[i])%10]=seg[i][j] ;
		FN(j,10) seg[i][j]=temp[j] ;
		if(l!=r) U[i<<1]+=U[i],U[(i<<1)|1]+=U[i] ;
		U[i]=0 ;
	}
	if(e<l||r<s) return ;
	if(s<=l && r<=e)
	{
		U[i]++ ;
		FN(j,10) temp[(j+U[i])%10]=seg[i][j] ;
		FN(j,10) seg[i][j]=temp[j] ;
		if(l!=r) U[i<<1]+=U[i],U[(i<<1)|1]+=U[i] ;
		U[i]=0 ;
		return ;
	}
	int m = (l+r)>>1 ;
	upd(l,m,i<<1,s,e),upd(m+1,r,(i<<1)|1,s,e) ;
	FN(j,10) seg[i][j]=seg[i<<1][j]+seg[(i<<1)|1][j] ;
}
int query(int l,int r,int i,int s,int e)
{
	if(U[i])
	{
		FN(j,10) temp[(j+U[i])%10]=seg[i][j] ;
		FN(j,10) seg[i][j]=temp[j] ;
		if(l!=r) U[i<<1]+=U[i],U[(i<<1)|1]+=U[i] ;
		U[i]=0 ;
	}
	if(e<l||s>r) return 0 ;
	if(s<=l && r<=e)
	{
		int ans=0 ;
		FN(j,10) ans += seg[i][j]*j ;
		return ans ;
	}
	int m = (l+r)>>1 ;
	return query(l,m,i<<1,s,e) + query(m+1,r,(i<<1)|1,s,e) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,Q ; cin>>N>>Q ;
	int l,r,t ;
	build(1,N,1) ;
	while(Q--)
	{
		cin>>t>>l>>r ;
		if(t==1) upd(1,N,1,l,r) ;
		else cout<<query(1,N,1,l,r)<<endl ;
	}
	return 0 ;
}
