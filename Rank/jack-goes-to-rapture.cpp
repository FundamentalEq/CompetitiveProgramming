#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define f first
#define s second
#define pii pair<ll,ll>
#define vi vector<int>
#define ll long long
#define db long double
using namespace std ;
const int L  = 5e4+5 ;
const ll inf = (ll)(1e18) ;
vector<pii> ad[L] ; 
ll Gdis[L] ; bool dis_found[L] ;
struct compare_diajsktra{ bool operator() (pii a,pii b) {return a.f > b.f ;} } ;
priority_queue< pii , vector<pii> ,compare_diajsktra> min_heap ;
void diajkstra(int N,int root = 1)
{
    while(!min_heap.empty()) min_heap.pop() ;
    FEN(i,N) Gdis[i] = inf ,dis_found[i]=0;
    Gdis[root] = 0 ; min_heap.push({0,root}) ;
    pii head ;
    while(!min_heap.empty())
    {
        head = min_heap.top() ; min_heap.pop() ;
        if(dis_found[head.s]) continue ; dis_found[head.s] = true ;
//        cout<<"current is :"<<head.s<<" with :"<<Gdis[head.s]<<endl ;
        for(auto &v:ad[head.s]) if(!dis_found[v.f]) if(Gdis[v.f] > Gdis[head.s] + max((ll)v.s - Gdis[head.s],(ll)0) )
        {
            Gdis[v.f] = Gdis[head.s] + max((ll)v.s - Gdis[head.s] ,(ll)0) ;
            min_heap.push({Gdis[v.f],v.f}) ;
        }
    }
}
int main()
{
	std::ios::sync_with_stdio(false);
    int N,E,u,v,c ; cin>>N>>E ;
    FEN(i,E) cin>>u>>v>>c , ad[u].pb({v,c}) ,ad[v].pb({u,c}) ;
    diajkstra(N) ;
    if(Gdis[N] == inf ) cout<<"NO PATH EXISTS"<<endl ;
    else cout<<Gdis[N]<<endl ;
    return 0 ;
}
