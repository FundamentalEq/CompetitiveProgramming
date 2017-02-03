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
vi ad[L] ; int C[L] , candidate;
int fc(int x,int p = -1)
{
	int ret ;
	for(auto v:ad[x]) if(v!=p)
	{
		ret = fc(v,x) ;
		if(ret == -1) return -1 ;
		if(C[v]!=C[x]) {candidate = x  ; return -1 ;}
	}
	return C[x] ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,a,b ; cin>>N ;
	FN(i,N-1) cin>>a>>b , ad[a].pb(b) ,ad[b].pb(a) ;
	FEN(i,N) cin>>C[i] ;
	fc(1) ;
	if(candidate == 0)
	{
		cout<<"YES\n1"<<endl ;
		return 0 ;
	}
	int X = candidate ;
	for(auto v:ad[X]) if(fc(v,X) == -1) {cout<<"NO"<<endl;return 0;}
	cout<<"YES\n"<<X<<endl ;
	return 0 ;
}
