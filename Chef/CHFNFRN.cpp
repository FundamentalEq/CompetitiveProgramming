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
const int L = 1005 ;
bool ad[L][L],ans ; int col[L],N,M ;
void color(int x,int C=0)
{
		col[x]=C ;
		FEN(i,N) if(ad[x][i])
		{
			if(col[i]==-1) color(i,C^1) ;
			else if (col[i]!= C^1) ans=false ;
			if(!ans) return ;
		}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ; cin>>T ;
	while(T--)
	{
		cin>>N>>M ;
		FEN(i,N) FEN(j,N) if(i!=j)ad[i][j]=1 ;
		FEN(i,N) col[i]=-1 ;
		int a,b ;
		while(M--) cin>>a>>b , ad[a][b]=ad[b][a]=0 ;
		ans=true ;
		for(int i=1;i<=N && ans;++i) if(col[i]==-1) color(i) ;
		if(ans) cout<<"YES"<<endl ;
		else cout<<"NO"<<endl ;
	}
	return 0 ;
}
