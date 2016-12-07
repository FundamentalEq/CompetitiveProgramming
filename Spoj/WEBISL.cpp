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
#define endl '\n'
using namespace std ;
const int L = 1e7+5 ;
int Index[L],LowLink[L] ; bool onstack[L] ;
stack<int> Tstack ;
vi ad[L],online ;
int ans[L];
void tarzan(int x,int &In)
{
    Index[x] = LowLink[x] = ++In ; onstack[x] = true ;
    Tstack.push(x) ;
    for(auto v:ad[x]) 
    {
        if(!Index[v]) tarzan(v,In) , LowLink[x] = min(LowLink[x],LowLink[v]) ;
        else if(onstack[v]) LowLink[x] = min(LowLink[x],Index[v]) ;
    }
    if(Index[x] == LowLink[x]) //x is the root of the scc
    {
        int temp = x ;
        while(Tstack.top()!=x) online.pb(Tstack.top()),temp = min(temp,Tstack.top()),Tstack.pop() ;
        online.pb(x) , Tstack.pop() ;
        for(auto v:online) ans[v] = temp ,onstack[v] = false ;
        online.clear() ;
    }
}
void scc(int N)
{
    int In = 0 ;
    FEN(i,N) if(!Index[i]) tarzan(i,In) ; 
}
int main()
{
	std::ios::sync_with_stdio(false);
    int N,M,u,v ; cin>>N>>M ;
    while(M--) cin>>u>>v, ad[u+1].pb(v+1) ;
    scc(N) ;
	FEN(i,N) cout<<(ans[i] - 1)<<endl ;
    return 0 ;
}
