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
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	ll sum=0 ;
	set<int> A ;
	int x ;
	FN(i,N)cin>>x, A.insert(x) ;
	bool ans=true ;
	if(sz(A)>3) ans=false ;
	else if(sz(A)==3)
	{
		vi temp ;
		FA(it,A) temp.pb(*it) ;
		if((temp[0]+temp[2])%2 != 0 ) ans=false ;
		else if( (temp[0]+temp[2])/2 != temp[1]) ans=false ;
	}
	cout<<(ans?"YES":"NO")<<endl ;
	return 0 ;
}
