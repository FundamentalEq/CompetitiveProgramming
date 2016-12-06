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
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	string S,A="rb" ;
	cin>>S ;
	int ans = INT_MAX ;
	int cur=0 ,r=0,b=0;
	FN(i,sz(S))
	{
		if(S[i]!=A[cur])
		{
			r += S[i]=='r' ;
			b += S[i]=='b' ;
		}
		cur^=1 ;
	}
	ans = min(r,b) + abs(b-r) ;
	cur=1,r=0,b=0 ;
	FN(i,sz(S))
	{
		if(S[i]!=A[cur])
		{
			r += S[i]=='r' ;
			b += S[i]=='b' ;
		}
		cur^=1 ;
	}
	ans = min(min(r,b)+abs(b-r),ans) ;
	cout<<ans<<endl ;
	return 0 ;
}
