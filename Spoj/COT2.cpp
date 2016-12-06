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
const int L = 4e4+5 ;
const int LL = 1e5+5 ;
struct tu { int u,v,i ;} ;
tu store[LL] ; int Ans[LL] ;
vi ad[L],ET ;
int W[L],S[L],E[L],times[L],CT[L],sqN ,Left,Right,XX[L],SZ ;
map<int,int> X ;
void dfs(int x,int p=-1)
{
	ET.pb(x) , ++times[x] ; S[x] = sz(ET)-1 ;
	for(auto v:ad[x]) if(v!=p)
	{
		dfs(v,x) ;
		ET.pb(x) ,++times[x];
	}
	if(times[x]==1) ET.pb(x),++times[x] ;
	E[x] = sz(ET)-1 ;
}
struct comp
{
	 bool operator()(tu l,tu r)
	 {
		 if(l.u/sqN != r.u/sqN) return l.u/sqN < r.u /sqN ;
		 else return l.v < r.v ;
	 }
 } ;
void add(int x)
 {
	 XX[x]++ ;
	 if(XX[x]==1) ++SZ ;
 }
void removeX(int x)
{
	--XX[x] ;
	if(XX[x] == 0) --SZ ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,a,b ; cin>>N>>M ;
	sqN = ceil(sqrt(N)) ;
	FEN(i,N) cin>>W[i] ,X[W[i]]=0;
	int temp = 1 ;
	for(auto &w:X) 	w.s = temp++ ;
	FEN(i,N) W[i] = X[W[i]] ; X.clear() ;
	FEN(i,N-1) cin>>a>>b,ad[a].pb(b),ad[b].pb(a) ;
	ET.pb(-1) ;	dfs(1) ;
	FN(i,M)
	{
		cin>>a>>b ;
		if(E[a] < S[b] || E[b] < S[a]) store[i].u = min(E[a],E[b]) ,store[i].v =max(S[a],S[b]) ;
		else store[i].u = min(S[a],S[b]) ,store[i].v = max(S[a],S[b]) ;
		store[i].i = i ;
	}
	sort(store,store+M,comp()) ;
	Left=1,Right=1 ; CT[ET[1]]=1 ; add(W[ET[1]]) ;
	FN(i,M)
	{
		while(Left > store[i].u)
		{
			--Left ;
			CT[ET[Left]] = (CT[ET[Left]] + 1 + times[ET[Left]])%times[ET[Left]]  ;
			if(!CT[ET[Left]]) removeX(W[ET[Left]]) ;
			if(CT[ET[Left]] == 1) add(W[ET[Left]]) ;
		}
		while(Right < store[i].v)
		{
			++Right ;
			CT[ET[Right]] = (CT[ET[Right]] + 1 + times[ET[Right]])%times[ET[Right]]  ;
			if(!CT[ET[Right]]) removeX(W[ET[Right]]) ;
			if(CT[ET[Right]]==1) add(W[ET[Right]]) ;
		}
		while(Left < store[i].u)
		{
			CT[ET[Left]] = (CT[ET[Left]] - 1 + times[ET[Left]])%times[ET[Left]]  ;
			if(!CT[ET[Left]]) removeX(W[ET[Left]]) ;
			if(CT[ET[Left]] == times[ET[Left]] - 1) add(W[ET[Left]]) ;
			++Left ;
		}
		while(Right > store[i].v)
		{
			CT[ET[Right]] = (CT[ET[Right]] - 1 + times[ET[Right]])%times[ET[Right]]  ;
			if(!CT[ET[Right]]) removeX(W[ET[Right]]) ;
			if(CT[ET[Right]] == times[ET[Right]] -1) add(W[ET[Right]]) ;
			--Right ;
		}
		Ans[store[i].i] = SZ ;
	}
	FN(i,M) cout<<(Ans[i]==0?1:Ans[i])<<endl ;
	return 0 ;
}
