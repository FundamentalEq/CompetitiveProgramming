#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for(int i=1;i<=(int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define db double
using namespace std ;
const int L = 1e6+5 ;
struct tuple { int l,r,i ; } ;
tuple Q[L] ;
map<int,int> last ;
int fw[L],IN[L],ans[L],pre[L] ;
int comp(const void *x,const void *y)
{
	tuple a= *(tuple*)x,b=*(tuple*)y ;
	return a.r - b.r ;
}
void upd(int x,int N,int A)
{
	if(x==0) return ;
	for(;x<=N;x+= x&-x ) fw[x]^=A ;
}
int query(int x)
{
	int ans=0 ;
	for(;x>0;x-=x&-x) ans ^= fw[x] ;
	return ans ;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int N ; cin>>N ;
    FEN(i,N) cin>>IN[i],pre[i]=pre[i-1]^IN[i] ;
    int M ; cin>>M ;
    FEN(i,M) cin>>Q[i].l>>Q[i].r ,Q[i].i=i ;
    qsort(Q+1,M,sizeof(Q[0]),comp) ;
    int i=1 ;
    FEN(it,M)
    {
	for(;i<=Q[it].r;++i)
	{
		upd(last[IN[i]],N,IN[i]) ;
		upd(i,N,IN[i]) ;
		last[IN[i]]=i ;
	}
	int temp = pre[Q[it].r]^pre[Q[it].l-1] ;
	temp ^= query(Q[it].r)^query(Q[it].l-1) ;
	ans[Q[it].i]=temp ;
    }
    FEN(i,M) cout<<ans[i]<<endl ;
    return 0 ;
}
