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
const int L =1e5+5 ;
int SP[L],SG[L],P[L],G[L] ,line[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	FEN(i,N) cin>>line[i],P[i]=G[i]=N+1 ;
	FEN(i,N)
	{
		SP[i] = (line[i]==1)+SP[i-1] ;
		SG[i] = (line[i]==2)+SG[i-1] ;
		P[SP[i]]=min(P[SP[i]],i) ;
		G[SG[i]]=min(G[SG[i]],i) ;
	}
	vector< pii > ans ;
	FEN(t,N)
	{
		int wp=0,wg=0,sp=0,sg=0,i=0 ;
		while(i<N)
		{
			// cout<<"t = "<<t<<" "<<" i is "<<i<<endl ;
			if(sp+t>N ||sg+t>N) break ;
			// if(P[sp+t] == G[sg+t]) break ;
			if(P[sp+t]>N && G[sg+t]>N) break ;
			if(P[sp+t] < G[sg+t])
			{
				++wp ;
				i=P[sp+t] ;
				if(i==N && wp<=wg) {i=-1;break ;}
			}
			else
			{
				++wg ;
				i=G[sg+t] ;
				if(i==N && wg<=wp) {i=-1;break ;}
			}
			sp=SP[i] , sg=SG[i] ;
		}
		// cout<<"at end i "<<i<<endl ;
		if(i==N && wp!=wg) ans.pb(mp(max(wp,wg),t)) ;
	}
	sort(ans.begin(),ans.end()) ;
	cout<<sz(ans)<<endl;
	FA(it,ans) cout<<it->f<<" "<<it->s<<endl ;
	return 0 ;
}
