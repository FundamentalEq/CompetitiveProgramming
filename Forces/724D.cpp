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
string dp[L] ;
deque<int> Q ;
int main()
{
	std::ios::sync_with_stdio(false);
	string S ; int M ; cin>>M ;
	cin>>S ;
	string temp ;
	FN(i,sz(S))
	{
		while(!Q.empty() && Q.front() < i-M )
		{
			dp[Q.front()].clear() ;
			Q.pop_front() ;
		}
		if(Q.empty())
		{
			dp[i]=S[i] ;
			Q.push_back(i) ;
		}
		else
		{
			int v = Q.front() ;
			int k=0 ;
			while(k<sz(dp[v]) && dp[v][k]<S[i]) ++k ;
			dp[i] = dp[v].substr(0,k) + S[i] ;
			if(k!=sz(dp[v]))
			{
				dp[i] = dp[i] + dp[v].substr(k,sz(dp[v])-k+1) ;
			}
			temp = S[i] ;
			if(i<M && (temp < dp[i])) dp[i]=temp ;
			while(!Q.empty() && dp[Q.back()]<=dp[i]) dp[Q.back()].clear() , Q.pop_back() ;
			Q.push_back(i) ;
		}
	}
	cout<<dp[Q.front()]<<endl ;
	return 0 ;
}
