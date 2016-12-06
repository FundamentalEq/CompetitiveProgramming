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
map<char,int> A ;
int main()
{
	std::ios::sync_with_stdio(false);
	string S ; cin>>S ;
	if(sz(S)&1)
	{
		cout<<-1<<endl ;
		return 0 ;
	}
	FN(i,sz(S)) A[S[i]]++ ;
	int X=abs(A['L']-A['R']) ,Y=abs(A['U']-A['D']) ;
	cout<< abs((int)(X-Y)/2) + min(X,Y) <<endl ;
	return 0 ;
}
