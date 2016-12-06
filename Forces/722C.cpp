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
int P[L],S[L] ;
ll A[L], IN[L] ;
bool exist[L] ;
int fp(int x) {	return (P[x]==0)?x:P[x]=fp(P[x]) ; }
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>IN[i] ; FEN(i,N) cin>>S[i] ;
	ll mx = 0 ;
	vector<ll> ans ;
	for(int i=N;i>=1;--i)
	{
		ans.pb(mx) ;
		int v = S[i] ; A[v] = IN[v] ; exist[v]=true ;
		if(exist[v+1])
		{
			A[v] += A[v+1] ;
			P[v+1]=v ;
		}
		if(exist[v-1])
		{
			A[fp(v-1)] += A[v] ;
			P[v] = fp(v-1) ;
		}
		mx = max(mx,A[fp(v)]) ;
	}
	reverse(ans.begin(),ans.end()) ;
	for(auto i:ans) cout<<i<<endl ;
	return 0 ;
}
