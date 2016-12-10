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
const int L = 1e5+5 ;
const ll inf = (ll)(1e18) ;
vector<pii> ad[L] ; 
string S ;
int pre[L];ll Mdis[L] ; bool Dfound[L] ;
struct compare_diajsktra{ bool operator() (pair<ll,int> a,pair<ll,int> b) {return a.f > b.f ;} } ;
priority_queue< pair<ll,int> , vector<pair<ll,int> > ,compare_diajsktra> Mheap ;
void diajkstra(int N,ll &ans)
{
    while(!Mheap.empty()) Mheap.pop() ;
    FEN(i,N) Mdis[i] = inf ,Dfound[i]=0;
    int left = 0 ;
    FEN(i,N) 
    {
        if(S[i-1] =='H') ++left ;
        else Mheap.push({0,i}) ,Mdis[i]=0 ,pre[i]=0;
    }
    pair<ll,int> head ;
    while(!Mheap.empty())
    {
        head = Mheap.top() ; Mheap.pop() ;
        if(Dfound[head.s]) continue ; Dfound[head.s] = true ;
        if(S[head.s-1]=='H')
        {
            --left ;
            ans += pre[head.s] ;
        }
        if(left == 0) break ;
        for(auto &v:ad[head.s]) if(!Dfound[v.f]) if(Mdis[v.f] > v.s)
        {
            Mdis[v.f] = v.s ;
            pre[v.f] = v.s ;
            Mheap.push({Mdis[v.f],v.f}) ;
        }
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T,N,M,x,y,z ; ll ans ;
    cin>>T ;
    while(T--)
    {
        S.clear() ;
        cin>>N>>M>>S ;
        FEN(i,N) ad[i].clear() ; 
        ans = 0 ;
        while(M--) 
        {
            cin>>x>>y>>z ;
            if(z>=0) ad[x].pb({y,z}) ,ad[y].pb({x,z}) ;
            else
            {
                ans += z ;
                ad[x].pb({y,0}) ,ad[y].pb({x,0}) ;
            }
        }
        diajkstra(N,ans) ;
        cout<<ans<<endl ;
    }
    return 0 ;
}
