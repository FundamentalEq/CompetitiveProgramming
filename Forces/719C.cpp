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
char S[L] ;
string add1(string nu)
{
	int cur = sz(nu)-1 ;
	while(cur>=0)
	{
		if(nu[cur]!='9')
		{
			nu[cur]++ ;
			return nu ;
		}
		else nu[cur--]='0' ;
	}
	return nu = "1" + nu ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,T ; cin>>N>>T ;
	string nu ; cin>>nu ;
	int dot=0 ; while(nu[dot]!='.') ++dot ;
	int cur=-1 ,zero=sz(nu);
	for(int i=dot+1;i<sz(nu);++i) if(nu[i]>='5') {cur=i;break;}
	if(cur==-1)
	{
		cout<<nu<<endl ;
		return 0 ;
	}
	while(cur>dot && T>0)
	{
		int x = cur-1 ; T-- ;
		if(x!=dot)
		{
			nu[x]++ ,zero=cur ; cur=x ;
			while(cur>dot && nu[cur]<'5') --cur ;
		}
		else
		{
			nu = nu.substr(0,dot) ;
			cout<<add1(nu)<<endl ;
			return 0 ;
		}
	}
	nu=nu.substr(0,zero);
	cout<<nu<<endl ;
	return 0 ;
}
