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
#define ll long long
#define vi vector<int>
#define db long double
using namespace std ;
#define vll vector<ll>
//range update range query
void bmake(vll &A) { FN(i,sz(A)) A[i]=0 ; }
void bupdate(int x,ll c,vll &A) { if(x==0) return ; for(;x<sz(A);x+=x&-x) A[x] += c ; }
void bupdate(int l,int r,ll c,vll &A,vll &B)
{
	bupdate(l,c,A) ,bupdate(r+1,-c,A) ;
	bupdate(l,c*(ll)(l-1),B) ,bupdate(r+1,-c*(ll)r,B) ;
}
ll bquery(int x,vll &A) {ll ans=0 ; for(;x>0;x-=x&-x) ans+=A[x] ; return ans ;}
ll bquery(int x,vll &A,vll &B){ return x*bquery(x,A) - bquery(x,B) ;}
ll bquery(int l,int r,vll &A,vll &B) { return bquery(r,A,B)-bquery(l-1,A,B); }

int main()
{
	std::ios::sync_with_stdio(false);
	int T,N,C,t,l,r,c; cin>>T ;
	vll bits , fw ;
	while(T--)
	{
		cin>>N>>C ;
		bits.resize(N+5) , fw.resize(N+5) ;
		bmake(bits),bmake(fw) ;
		while(C--)
		{
			cin>>t ;
			if(t==0) cin>>l>>r>>c , bupdate(l,r,c,bits,fw) ;
			else cin>>l>>r , cout<<(ll)bquery(l,r,bits,fw)<<endl  ;
		}
	}
	return 0 ;
}
