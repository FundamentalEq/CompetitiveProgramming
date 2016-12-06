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
vector<ll> EulerTotientSieve(int limit)
{
   vector<ll> totient(limit+1) ;
   totient[1] = 1 ,totient[0] = 0 ; for(int i=2;i<=limit;++i) totient[i] = i ;
   totient[2] = 1 ; for(int j=4;j<=limit;j+=2) totient[j] = totient[j]  - totient[j]/2 ;
   for(int i=3;i<=limit;i+=2) if(totient[i] == i)
   {
       totient[i] =i-1 ;
       for(int j=i<<1;j<=limit;j+=i) totient[j] = totient[j] - totient[j]/i ;
   }
   return totient ;
}
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL) ;
    int L = 1e6+5 ;
    vector<ll> totient = EulerTotientSieve(L) ;
    FEN(i,L-1) totient[i] += totient[i-1] ;
//    cout<<"totient is set"<<endl ;
    ll N,r,d,ans ;
    while(cin>>N && N!=0)
    {
        ans = 0 ;
        for(int i=1;i<=N;)
        {
            r = N/i ;
            ans += (r*(r-1))/2 * (totient[N/r] - totient[N/(r+1)]) ;
            i = N/r + 1 ; 
        }
        cout<<ans<<endl ;
    }
    return 0 ;
}
