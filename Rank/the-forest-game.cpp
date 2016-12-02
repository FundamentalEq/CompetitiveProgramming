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
const int L = 3e5+5 ;
int C[L] ,P[L] ; bool done[L] ;
ll sum,tot ;
struct comp{bool operator()(int x,int y){return C[x]>C[y];}};
void fix(int x)
{
	if(done[x]) return ;
	if(P[x]!=-1) fix(P[x]) ;
	sum -= C[x] ;
	tot += sum ;
	done[x]=true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>C[i],sum+=C[i] ;
	FEN(i,N-1) cin>>P[i+1] ; P[1]=-1 ;
	vi toremove ; FEN(i,N) toremove.pb(i) ;
	sort(toremove.begin(),toremove.end(),comp()) ;
	FN(i,N) if(!done[toremove[i]]) fix(toremove[i]) ;
	cout<<tot<<endl ;
	return 0 ;
}
