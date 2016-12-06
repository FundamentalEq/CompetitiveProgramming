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
const int L =1e6+5 ;
ll Y[L] ; int CT[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	ll N,M,dx,dy ; cin>>N>>M>>dx>>dy ;
	ll cx=0,cy=0 ;
	FN(i,N)
	{
		Y[cx]=cy ;
		cx=(cx+dx)%N ,cy=(cy+dy)%N ;
	}
	while(M--)
	{
		cin>>cx>>cy ;
		ll c = (cy-Y[cx]+N)%N ;
		++CT[c] ;
	}
	int ans=0 ;
	FN(i,N) if(CT[i]>CT[ans]) ans=i ;
	cout<<"0 "<<ans<<endl ;
	return 0 ;
}
