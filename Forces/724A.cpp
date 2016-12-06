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
int A[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
string S[]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int day(string x)
{
	FN(i,7) if(S[i]==x) return i ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	string a,b ; cin>>a>>b ;
	int x = day(a) , y=day(b) ;
	bool ans=false ;
	FN(m,12)
	{
		if((x+A[m])%7 == y) ans=true ;
	}
	cout<<(ans?"YES":"NO")<<endl ;
	return 0 ;
}
