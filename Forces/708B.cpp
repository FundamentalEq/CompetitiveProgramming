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
const int L = 1e5+5 ;
ll nc2(ll x) { return ( x*(x-1) )/2 ; }
string cons(int z,int o,int a01,int a10)
{
	string ans ;
	if(z==0)
	{
		FN(i,o) ans = ans + "1" ;
		return ans ;
	}
	if(o==0)
	{
		FN(i,z) ans = ans + "0" ;
		return ans ;
	}
	if(a01>=o)
	{
		int temp = a01/o ;
		FN(i,temp) ans = ans + "0" ;
		return ans + cons(z-temp,o,a01%o,a10) ;
	}
	if(a10>=z)
	{
		int temp = a10/z ;
		FN(i,temp) ans = ans + "1" ;
		return ans + cons(z,o-temp,a01,a10%z) ;
	}
	cout<<"error"<<endl ;
	assert(false) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll a,b,c,d ; cin>>a>>b>>c>>d ;
	ll z = ceil(sqrt((db)2*a)) ,o=ceil(sqrt((db)2*d)) ;
	string ans ;
	if(a==0 && d==0)
	{
		if(b==0&&c==0) ans="0" ;
		else if(b==0 && c==1) ans="10" ;
		else if(b==1 && c==0) ans="01" ;
		else ans="Impossible" ;
	}
	else if( nc2(z) == a && nc2(o)==d && nc2(z+o) -a-b-c-d == 0) ans=cons(z,o,b,c) ;
	else if( d==0 && nc2(z+1)-a-b-c==0)  ans=cons(z,1,b,c) ;
	else if( a==0 && nc2(o+1)-b-c-d==0)  ans=cons(1,o,b,c) ;
	else ans="Impossible" ;
	cout<< ans<<endl ;
	return 0 ;
}
