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
bool lucky(int x)
{
	x=abs(x) ;
	while(x)
	{
		if(x%10 == 8) return true ;
		x/=10 ;
	}
	return false ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int a; cin>>a ; ++a ;
	int ans=1 ;
	while(!lucky(a)) ++a,++ans ;
	// ans = ans==0?10:ans ;
	cout<<ans<<endl ;
	return 0 ;
}
