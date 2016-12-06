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
const int L = 5e3+5 ;
vector< pii > ad[L] ; int dp[L][L] ; int prev[L][L] ,indegree[L];
int main()
{
	std::ios::sync_with_stdio(false);
	// cout<<"the declration is not the problem"<<endl ;
	int N,M ; ll T ; cin>>N>>M>>T ;
	int u,v,t ;
	while(M--) cin>>u>>v>>t ,ad[u].pb(mp(v,t)) ,++indegree[v] ;
	queue<int> Q ;
	FEN(i,N) if(indegree[i]==0) Q.push(i) ;
	while(!Q.empty())
	{
		int v = Q.front() ; Q.pop() ;
		if(v==1) continue ;
		FN(i,sz(ad[v]))
		{
			--indegree[ad[v][i].f] ;
			 if(indegree[ad[v][i].f]==0) Q.push(ad[v][i].f) ;
		}
	}
	Q.push(1) ; dp[1][1]=0 ; prev[1][1]=1 ;
	while(!Q.empty())
	{
		int v = Q.front() ; Q.pop() ;
		if(v==N) break ;
		FN(i,sz(ad[v]))
		{
			FEN(k,N-1) if(prev[v][k]!=0)
			{
				if((ll)(dp[v][k]+ad[v][i].s)>(ll)T) continue ;
				if(dp[ad[v][i].f][k+1] > dp[v][k] + ad[v][i].s || prev[ad[v][i].f][k+1]==0)
				{
					dp[ad[v][i].f][k+1] = dp[v][k] + ad[v][i].s ;
					prev[ad[v][i].f][k+1] = v ;
				}
			}
			--indegree[ad[v][i].f] ;
			 if(indegree[ad[v][i].f]==0) Q.push(ad[v][i].f) ;
		}
	}
	// Q.clear() ;
	int K=0 ;
	FEN(k,N) if(dp[N][k]<=T && prev[N][k]!=0) K=k ;
	cout<<K<<endl ;
	vi ans ; int cur = N ;
	while(K)
	{
		ans.pb(cur) ;
		cur = prev[cur][K--] ;
	}
	reverse(ans.begin(),ans.end()) ;
	FN(i,sz(ans)) cout<<ans[i]<<" " ;
	cout<<endl ;
	return 0 ;
}
