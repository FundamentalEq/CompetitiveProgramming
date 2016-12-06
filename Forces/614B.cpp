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
bool beautifil(string S)
{
	if(S[0]!='1') return false ;
	FEN(i,sz(S)-1) if(S[i]!='0') return false ;
	return true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	int ct=0 ;
	string in,A;
	while(N--)
	{
		cin>>in ;
		if(in=="0")
		{
			cout<<"0"<<endl ;
			return 0 ;
		}
		if(beautifil(in)) ct += sz(in)-1 ;
		else A=in ;
	}
	if(sz(A)==0) A="1" ;
 	char ans[sz(A)+ct+5] ;
	int j=0 ;
	FN(i,sz(A)) ans[j++]=A[i] ;
	FN(i,ct) ans[j++]='0' ;
	ans[j]='\0' ;
	cout<<ans<<endl ;
	return 0 ;
}
