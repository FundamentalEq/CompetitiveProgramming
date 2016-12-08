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
const int L = 1e4+5 ;
vi ad[L] ;
int ArtIndex[L],ArtLow[L] ; bool IsArt[L] ;
void Art_dfs(int x,int &ct,int p=-1)
{
    int discovery = 0 ;
    ArtIndex[x] = ArtLow[x] = ++ct ;
    for(auto v:ad[x]) if(v!=p)
    {
        if(ArtIndex[v]) ArtLow[x] = min(ArtLow[x],ArtIndex[v]) ;
        else
        {
            ++discovery ; Art_dfs(v,ct,x) ;
            ArtLow[x] = min(ArtLow[x] ,ArtLow[v]) ;
            if(p!=-1 && ArtLow[v] >= ArtIndex[x]) IsArt[x] = true ;
        }
    }
    if(p == -1 && discovery >= 2) IsArt[x] = true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,u,v,ans,ct ;
    while(cin>>N>>M && !(N==0 && M==0))
    {
        FEN(i,N) ad[i].clear(),ArtLow[i] =ArtIndex[i] = IsArt[i] = 0 ;
        while(M--) cin>>u>>v, ad[u].pb(v),ad[v].pb(u) ;
        ct = 0 ;FEN(i,N) if(!ArtIndex[i]) Art_dfs(i,ct) ;
        ans = 0 ; FEN(i,N) if(IsArt[i]) ++ans ;
        cout<<ans<<endl ;
    }
    return 0 ;
}
