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
	int N,X,Y ; cin>>N>>X>>Y ;
	int cntx=0,cnty=0 ;
	vector<string>ans ;
	while(cntx<X && cnty<Y)
	{
		if((db)((db)(cntx+1)/(db)X) < (db)((db)(cnty+1)/(db)Y)) ans.pb("Vanya"),++cntx ;
		else if((db)((db)(cntx+1)/(db)X) > (db)((db)(cnty+1)/(db)Y)) ans.pb("Vova"),++cnty ;
		else ans.pb("Both"),ans.pb("Both"),++cntx,++cnty ;

	}
	while(N--)
	{
		int A ; cin>>A ;
		cout<<ans[(A-1)%(X+Y)]<<endl ;
	}
	return 0 ;
}
