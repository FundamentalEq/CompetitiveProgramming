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
string S ;
bool makenice(int i,int j)
{
	// cout<<i<<" "<<j<<endl ;
	int A[26] ;
	FN(k,26) A[k]=0 ;
	// FN(k,26) cout<<A[i]<<" " ; cout<<endl ;

	int q=0 ;
	for(int k=i;k<=j;++k)
	{
		if(S[k]=='?') continue ;
		if(A[S[k]-'A']>0)
		{
			// cout<<k<<endl ;
			return false ;
		}
		// cout<<k<<" "<<S[k]<<endl ;
		A[S[k]-'A']++ ;
	}
	int indi=0 ;
	// FN(k,26) cout<<A[k]<<" " ; cout<<endl ;
	for(int k=i;k<=j;++k) if(S[k]=='?')
	{
		while(A[indi]!=0) ++indi ;
		// cout<<indi<<endl ;
		S[k]=(char)('A'+indi) ;
		++indi ;
	}
	return true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>S;
	bool nice=false ;
	if(sz(S)<26)
	{
		cout<<-1<<endl ;
		return 0 ;
	}
	FN(i,sz(S)-25)
	{
		nice = makenice(i,i+25) ;
		if(nice) break ;
	}
	if(!nice) cout<<-1<<endl ;
	else
	{
		FN(i,sz(S)) if(S[i]=='?') S[i]='A' ;
		cout<<S<<endl ;
	}
	return 0 ;
}
