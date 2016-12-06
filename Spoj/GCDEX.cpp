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
const int L = 1e6+2 ;
int totient[L] ;
ll T[L],R[L] ;
void EulerTotientSieve(int limit)
{
   ++limit ;
   for(int i=2;i<limit;++i) totient[i] = i ;
   totient[2] = totient[1] = 1 ; for(int j=4;j<limit;j+=2) totient[j] >>=1 ;
   for(int i=3;i<limit;i+=2) if(totient[i] == i)
   {
       totient[i] =i-1 ;
       for(int j=i<<1;j<limit;j+=i) totient[j] = totient[j] - totient[j]/i ;
   }
}
int main()
{
	//std::ios::sync_with_stdio(false); //cin.tie(NULL) ; cout.tie(NULL) ;
    EulerTotientSieve(L) ;
    FEN(i,L-1) T[i] = T[i-1] + totient[i] ; 
    int N,r ; ll ans ;
    FEN(i,L-1) R[i] = ((ll)i*(ll)(i-1))/2 ;
    while(scanf("%d",&N) && N)//while(cin>>N && N)
    {
        ans = 0 ;
        for(int i=1;i<=N;)
        {
            r = N/i ;
            ans += R[r]* (T[N/r] - T[N/(r+1)]) ;
            i = N/r + 1 ; 
        }
        printf("%lld\n",ans) ;
    }
    return 0 ;
}
