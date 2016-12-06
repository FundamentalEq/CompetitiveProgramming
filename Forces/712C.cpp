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
	int x,y ; cin>>x>>y ;
	int Y[3] ; FN(i,3) Y[i]=y ;
	int ans=0 ;
	while(Y[0]!=x||Y[1]!=x||Y[2]!=x)
	{
		FN(i,3) if(Y[i]!=x)
		{
			++ans ;
			Y[i]=min(x,Y[(i+1)%3]+Y[(i+2)%3]-1) ;
		}
	}
	cout<<ans<<endl ;
	return 0 ;
}
