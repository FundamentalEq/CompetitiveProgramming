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
const int L = 1e5+ 5 ;
int type[L],ans[L] ; pii IN[L] ; bool book[1005][1005] ;
vi ad[L] ; bool done[L] ;
int M ;
using namespace std ;
void act(int x,int &books)
{
	if(type[x]==4) return ;
	if(type[x]==1)
	{
		if(!book[IN[x].f][IN[x].s] )book[IN[x].f][IN[x].s]=1,++books ;
		else done[x]=false ;
	}
	if(type[x]==2)
	{
		if(book[IN[x].f][IN[x].s]) book[IN[x].f][IN[x].s]=0,--books ;
		else done[x]=false ;
	}
	if(type[x]==3)
		FEN(i,M)
		{
			if(book[IN[x].f][i])book[IN[x].f][i]=0,--books ;
			else book[IN[x].f][i]=1,++books ;
		}
}
void cal(int x,int books=0)
{
	act(x,books) ;
	ans[x]=books ;
	FN(i,sz(ad[x])) cal(ad[x][i],books) ;
	 if(type[x]==1)type[x]=2 ;
	 else if(type[x]==2) type[x]=1 ;
	 if(!done[x]) return ;
	 act(x,books) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,Q ; cin>>N>>M>>Q ;
	FEN(q,Q)
	{
		cin>>type[q] ;
		if(type[q]==1 ||type[q]==2) cin>>IN[q].f>>IN[q].s ;
		else cin>>IN[q].f ;
		if(type[q]==4) ad[IN[q].f].pb(q);
		else ad[q-1].pb(q) ;
	}
	FEN(q,Q) done[q]=true ;
	cal(0) ;
	FEN(i,Q) cout<<ans[i]<<endl ;
	return 0 ;
}
