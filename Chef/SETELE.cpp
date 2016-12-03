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
int dsu[L] , SZ[L] ;
int fp(int x){if(!dsu[x]) return x ; return dsu[x] = fp(dsu[x]) ;}
pair<int,pii> E[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ,u,v,c; ll total = 0 ,ans = 0 ,div,temp=0 ;
	cin>>N ;
	div = (N*(N-1))/2 ;
	FN(i,N-1) cin>>u>>v>>c , total += c , E[i] = {c,{u,v}} ;
	sort(E,E+N-1) ;
	FEN(i,N) SZ[i] = 1 ;
	FN(i,N-1)
	{
			u = fp(E[i].s.f) , v = fp(E[i].s.s) ;
			ans += (ll)SZ[u]*(ll)SZ[v]*(ll)E[i].f ;
			temp += (ll)SZ[u]*(ll)SZ[v] ;
			if(SZ[u] < SZ[v]) swap(u,v) ;
			dsu[v] = u ,SZ[u] += SZ[v];
	}
//	assert(temp == div) ;
	db a = (db)((db)total - ((db)ans/(db)temp) ) ;
	cout<<setprecision(11)<<a<<endl ;
	return 0 ;
}
