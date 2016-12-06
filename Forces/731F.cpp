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
const int L = 2e5+5 ;
int ct[L]; bool is[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ,temp; cin>>N ;
	FEN(i,N) cin>>temp ,++ct[temp],is[temp]=true ;
	for(int i=2e5;i>0;--i) ct[i] += ct[i+1] ;
	ll mx = 0 , p ,largest ;
	FEN(i,(int)2e5) if(is[i])
	{
		largest =  ((ll)(2e5)/i)*(ll)i ;
		assert(largest<=(int)2e5) ;
		p = largest*ct[largest] ;
		largest -= i ;
		while(largest >= i)
		{
			p += largest*(ll)(ct[largest] - ct[largest+i]) ;
			largest -= i ;
		}
		mx = max(mx,p) ;
	}
	cout<<mx<<endl ;
	return 0 ;
}
