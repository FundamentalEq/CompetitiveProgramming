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
	int N,cur=0,a ; cin>>N ;
	bool ans = true ;
	while(N--)
	{
		cin>>a ;
		if(a == 0 && cur!=0) ans = false ;
		cur = (cur + a)%2 ;
	}
	if(cur) ans = false ;
	cout<<(ans?"YES":"NO")<<endl ;
	return 0 ;
}
