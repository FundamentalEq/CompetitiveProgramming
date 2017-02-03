#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define f first
// #define s second
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define db long double
using namespace std ;
int main()
{
	std::ios::sync_with_stdio(false);
	ll N,cur = 0,mul = 1 , ans = 0; string K ; cin>>N>>K ;
	ll PW[10] ; PW[0] = 1 ; FEN(i,10) PW[i] = PW[i-1] * 10 ;
	int s = 0 ;
	for(int i = sz(K) - 1 ; i>=0 ; --i)
	{
		if( ( cur + PW[s]*max(1,( K[i] - '0')) )< N ) cur = ( cur + PW[s]*( K[i] - '0') ) , ++s;
		else
		{
			ans += cur*mul ;
			mul *= N ;
			cur = K[i] - '0' , s = 1;
		}
	}
	if(s > 0) ans += cur*mul ;
	cout<<ans<<endl ;
	return 0 ;
}
