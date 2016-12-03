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
vi ad[L],online ; int C[L] ;
void dfs(int x,int c,int &w,int &size)
{
	if(c==0)++w ; ++size ;
	C[x]=c ;
	for(auto v:ad[x]) if(C[v]==-1) dfs(v,c^1,w,size) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll A,B,AC,AD ;
	int T,N,M,a,b,w,size,d,left ; cin>>T ;
	FEN(i,L-1) C[i]=-1 ;
	while(T--)
	{
		cin>>N>>M ;
		// FEN(i,N) C[i]=-1 ,ad[i].clear();
		FEN(i,M) cin>>a>>b, ad[a].pb(b), ad[b].pb(a) ,online.pb(a),online.pb(b) ;
		A=B=d=0 ;
		for(auto i:online) if(C[i]==-1)
		{
			w=size=0 ;
			dfs(i,0,w,size) ;
			d += size ;
			assert(abs(size-2*w)<=1) ;
			if(A<=B) A+= max(w,size-w) ,B+=min(w,size-w) ;
			else A += min(w,size-w) ,B += max(w,size-w) ;
		}
		left = N-d ;
		AC = max(A,B) + min(left/2,left - left/2) ;
		AD = min(A,B) + max(left/2,left - left/2) ;
		cout<<(ll)(AC*AD - M)<<endl ;
		for(auto i:online) C[i]=-1,ad[i].clear() ;
		online.clear() ;
	}
	return 0 ;
}
