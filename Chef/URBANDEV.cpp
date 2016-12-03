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
struct line { int x1,y1,x2,y2,i ;} ;
bool hoz(line &l){ return l.y1 == l.y2 ;}
void fix(line &l)
{
	if(hoz(l)) { if(l.x1 > l.x2) swap(l.x1,l.x2) ; }
	else { if(l.y1>l.y2) swap(l.y1,l.y2) ;}
}
struct comp
{
	bool operator()(line &l,line &r)
	{
		if(l.x1 == r.x1 )
		{
			if(hoz(l)) return true ;
			else if(hoz(r)) return false ;
		}
		return l.x1 < r.x1 ;
	}
};
//BITS : point update and range query
void bmake(vi &A) { FN(i,sz(A)) A[i]=0 ; }
void bupdate(int x,int c,vi &A) { if(x==0) return ; for(;x<sz(A);x+=x&-x) A[x] += c ; }
int bquery(int x,vi &A) {int ans=0 ; for(;x>0;x-=x&-x) ans+=A[x] ; return ans ;}
int bquery(int l,int r,vi &A) { return bquery(r,A)-bquery(l-1,A); }
//BITS : range update and point query
void bupdate(int l,int r,int c,vi &A) { bupdate(l,c,A),bupdate(r+1,-c,A); }

int main()
{
	std::ios::sync_with_stdio(false);
	int N ,mxY=0; ll ans=0 ; cin>>N ;
	vector< line > A(N+5) ;
	vector< pair<pii,int> > duplicate ;
	vi Ans(N+2) ;
	FN(i,N)
	{
		  cin>>A[i].x1>>A[i].y1>>A[i].x2>>A[i].y2,A[i].i=i ;
		  fix(A[i]) ;
		  mxY = max(mxY,A[i].y2) ;
		  duplicate.pb({{A[i].x1,A[i].y1},i}) ;
		  duplicate.pb({{A[i].x2,A[i].y2},i}) ;
	}
	sort(A.data(),A.data()+N,comp()) ;

	vector<pii> end ;
	vi on(mxY+5,0) ,visited(mxY+5,0) ;

	FN(i,N) if(hoz(A[i])) end.pb({A[i].x2,i}) ;
	sort(end.begin(),end.end()) ;

	int j = 0 ;
	FN(i,N)
	{
		while(j<sz(end) && end[j].f < A[i].x1)
		{
			line temp = A[end[j].s] ;
			Ans[temp.i] = bquery(temp.y1,visited) ;
			bupdate(temp.y1,temp.y1,-Ans[temp.i],visited) ;
			bupdate(temp.y1,-1,on) ;
			++j ;
		}
		if(hoz(A[i])) bupdate(A[i].y1,1,on) ;
		else
		{
			Ans[A[i].i] = bquery(A[i].y1,A[i].y2,on) ;
			ans += (ll)Ans[A[i].i] ;
			bupdate(A[i].y1,A[i].y2,1,visited) ;
		}
	}
	while(j<sz(end))
	{
		line temp = A[end[j].s] ;
		Ans[temp.i] = bquery(temp.y1,visited) ;
		bupdate(temp.y1,temp.y1,-Ans[temp.i],visited) ;
		bupdate(temp.y1,-1,on) ;
		++j ;
	}
	sort(duplicate.begin(),duplicate.end()) ;
	FEN(i,sz(duplicate)-1) if(duplicate[i].f == duplicate[i-1].f)
	{
		--ans ;
		--Ans[duplicate[i].s] , --Ans[duplicate[i-1].s] ;
	}
	cout<<ans<<endl ;
	FN(i,N) cout<<Ans[i]<<" " ; cout<<endl ;
	return 0 ;
}
