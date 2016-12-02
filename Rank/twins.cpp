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
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M ; cin>>N>>M ;
    vector<bool> prime(M-N+1,0) ;
    for(int i = 2 ; i < min(32000,N) ; ++i)
    {
        for(int j = ceil((db)N/(db)i)*i ; j <= M ; j+=i ) prime[j-N] = 1 ;
    }
    for(int i=N;i<=M;++i) if(!prime[i-N])
    {
        for(int j = i<<1 ; j<=M ; j+=i) prime[j-N] = 1 ;
    }
    int ans = 0 ;
    for(int i=N;(i+2)<=M;++i) if(!prime[i-N] && !prime[i+2-N]) ++ans ;
    cout<<ans<<endl ;
    return 0 ;
}
