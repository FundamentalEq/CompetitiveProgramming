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
	int yh,ya,yd,mh,ma,md,H,A,D ; cin>>yh>>ya>>yd>>mh>>ma>>md>>H>>A>>D ;
	int ans=INT_MAX ;
	int limit = mh*max(0,ma-yd) ; limit = max(limit+5,101) ;
	for(int a=max(ya,md+1);;++a)
	{
		int n = ceil((db)mh/(db)(a-md)) ;
		for(int d=yd;d<=ma;++d)
		{
			int h = n*(ma-d)+1 ;
			ans=min(ans,max(h-yh,0)*H + (d-yd)*D + (a-ya)*A) ;
		}
		// cout<<ans<<endl ;
		if(n==1) break ;
	}
	if(ans==INT_MAX) ans=(max(ya,md+1)-ya)*A ;
	cout<<ans<<endl ;
	return 0 ;
}
