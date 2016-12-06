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
const int L  =3e5 + 5 ;
ll pre[L],post[L] ;
ll IN[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>IN[i] ; sort(IN+1,IN+1+N) ; assert(IN[1]<=IN[N]) ;
	for(int i=2;i<=N;++i) pre[i] = pre[i-1] + (IN[i]-IN[i-1])*(i-1) ;
	for(int i=N-1;i>=1;--i) post[i] = post[i+1] + (IN[i+1]-IN[i])*(N-i) ;
	int ans=1 ;
	FEN(i,N)if((pre[i]+post[i])<(pre[ans]+post[ans])) ans=i ;
	cout<<IN[ans]<<endl ;
	return 0 ;
}
