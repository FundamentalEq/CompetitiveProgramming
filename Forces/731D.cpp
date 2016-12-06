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
const int L = 1e6+5 ;
int Next[L] ; bool del[L] ;
void mark(int l,int r)
{
	// cout<<"incoming "<<l<<" : "<<r<<endl ;
	int temp ;
	for(int i=l;i<=r;i=temp) del[i]=1,temp=Next[i],Next[i]=max(Next[i],r+1) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,C,temp,tempn ; cin>>N>>C ;
	FN(i,C) Next[i] = i+1 ;
	vi nu[2] ; bool cur=0,prev,ans=true ;
	cin>>tempn ;
	while(tempn--) cin>>temp , nu[cur].pb(temp) ;
	while(--N)
	{
		prev = cur ;
		cur ^= 1 ;
		nu[cur].clear() ;
		cin>>tempn ;
		while(tempn--) cin>>temp ,nu[cur].pb(temp) ;
		int x = -1 ;
		FN(i,min(sz(nu[prev]),sz(nu[cur]))) if(nu[prev][i]!=nu[cur][i]) {x=i;break ;}
		if(x == -1) {if(sz(nu[prev]) > sz(nu[cur])) ans=false ;}
		else
		{
			// cout<<"x = "<<x<<endl ;
			if(nu[prev][x] < nu[cur][x]) mark(C-nu[cur][x]+1,C-nu[prev][x]) ;
			else mark(0,C-nu[prev][x]) ,mark(C-nu[cur][x]+1,C-1) ;
		}
	}
	// cout<<"ans is "<<ans<<endl ;
	if(!ans) { cout<<-1<<endl ; return 0 ; }
	else FN(i,C) if(!del[i]) {cout<<i<<endl ; return 0 ;}
	cout<<-1<<endl ;
	return 0 ;
}
