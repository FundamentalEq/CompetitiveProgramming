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
#define vi vector<ll>
#define ll long long
#define db long double
using namespace std ;
const int mod = 1e9+7 ;
void convulate(int N,vi &A,vi &B,vi &temp)
{
    FN(i,N+1) temp[i] = 0 ;
    FN(i,N+1) for(int j=0;i+j<=N;++j) temp[i+j] = (temp[i+j] + (ll)(A[i]*B[j])%mod )%mod ;
    FN(i,N+1) A[i] = temp[i] ;

}
int main()
{
	std::ios::sync_with_stdio(false);
	ll T,M,N,D,X,y; vi F,poly,A,temp ;
	cin>>T ;
    while(T--)
    {
        cin>>M>>N>>X>>D ;
        A.clear(),F.clear() ;
        poly.resize(D+1); A.resize(N+1,0) ,temp.resize(N+1),F.resize(N+1,0) ; F[0] = 1 ;
        FN(i,D+1) cin>>poly[i] ; reverse(poly.begin(),poly.end()) ;
        FN(i,N+1) 
        {
            y = (ll)(X*i)%mod ;
            FN(j,D+1) A[i] = ( (ll)(A[i]*y)%mod + poly[j] )%mod ;
        }
        while(M)
        {
            if(M&1) convulate(N,F,A,temp) ;
            convulate(N,A,A,temp) ;
            M >>= 1 ;
        }
        cout<<F[N]<<endl ;
    }
	return 0 ;
}
