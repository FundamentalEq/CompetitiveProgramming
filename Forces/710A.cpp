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
	string IN ; cin>>IN ;
	if('b' <= IN[0] && IN[0]<='g' && '2'<=IN[1] && IN[1] <= '7') cout<<8 ;
	else if( IN=="a1" || IN=="a8" ||IN=="h1"||IN=="h8") cout<<3 ;
	else cout<<5 ;
	cout<<endl ;
	return 0 ;
}
