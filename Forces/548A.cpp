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
	string S; cin>>S ;
	int K ; cin>>K ;
	bool ans=true ;
	if(sz(S)%K !=0) ans=false ;
	K = sz(S)/K ;
	if(ans)
	{
		for(int i=0;(i+K-1)<sz(S);i+=K)
		{
			int end = i+K-1 ;
			for(int j=0;i+j<=end-j;++j) if(S[i+j]!=S[end-j]) ans=false ;
		}
	}
	cout<<(ans?"YES":"NO")<<endl ;
	return 0 ;
}
