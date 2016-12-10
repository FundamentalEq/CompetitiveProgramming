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
ll Ti[L],Pi[L] , online[L] ;
bool valid(int T,int M,int N,int K)
{
    ll ans = 0 ;
    FEN(i,M) online[i] = max((T-Ti[i])/Pi[i],(ll)0) + (int)(T>=Ti[i]?1:0)  ;
    sort(online+1,online+M+1) ;
    for(int i = M ; i>= max(1,M+1-N) ;--i) ans += online[i] ;
    return ans>=K ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N,M,K ; cin>>T ;
    while(T--)
    {
        cin>>M>>N>>K ;
        FEN(i,M) cin>>Ti[i] ;
        FEN(i,M) cin>>Pi[i] ;
        int lo = 0 , hi = 1e9 ,mid;
        while(hi-lo>1)
        {
            mid = (lo+hi)>>1 ;
            if(valid(mid,M,N,K)) hi = mid ;
            else lo = mid ;
        }
        cout<<hi<<endl ;
    }
    return 0 ;
}
