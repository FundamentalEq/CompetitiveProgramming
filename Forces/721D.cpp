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
const int L = 2e5 + 5 ;
bool S[L] ; ll IN[L] ;// int A[L] ;
struct comp { bool operator()(int x,int y){return IN[x]>IN[y];}};
priority_queue<int,vi,comp> Q ;
void print_ans(int N)
{
	FN(i,N) cout<<(S[i]?-IN[i]:IN[i])<<" " ;
	cout<<endl ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,K; ll X ; cin>>N>>K>>X ;
	FN(i,N) cin>>IN[i] , S[i] = (IN[i]<0) ,IN[i]=abs(IN[i]) ;//,A[i]=i ;
	FN(i,N) Q.push(i) ;
	int ng = 0 ; FN(i,N) ng += S[i] ;
	while(IN[Q.top()]==0)
	{
		if(K==0)
		{
			print_ans(N) ;
			return 0 ;
		}
		int cur = Q.top() ;  Q.pop() ;
		IN[cur]=X ; --K ;
		if(ng%2==0) S[cur]=1 , ++ng ;
		Q.push(cur) ;
	}
	if(ng%2==0)
	{
		int cur = Q.top() ;  Q.pop() ;
		if(IN[cur]<K*X)
		{
			ll t = IN[cur]/X + 1 ;
			IN[cur] = t*X - IN[cur] , S[cur]^=1 ;
			K -= t ;
		}
		else
		{
			IN[cur] -= K*X ;
			K=0 ;
		}
		Q.push(cur) ;
	}
	while(K--)
	{
		int cur = Q.top() ;  Q.pop() ;
		IN[cur] += X ;
		Q.push(cur) ;
	}
	print_ans(N) ;
	return 0 ;
}
