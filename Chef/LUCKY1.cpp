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
ll ans[L] ;
map<int,int> A ;
int foo(int x)
{
    int f=0,s=0;
    while(x)
    {
        f += x%10 == 4 ;
        s += x%10 == 7 ;
        x/=10 ;
    }
    return s-f ;
}
int main()
{
	std::ios::sync_with_stdio(false);
    int cur = 0 ; A[0]=1 ;
    FEN(i,L-3)
    {
        cur += foo(i) ;
        ans[i] =  A[cur] + ans[i-1] ;
        ++A[cur] ;
    }
    //FEN(i,L-3) ans[i] += ans[i-1] ;
    int T,N ; cin>>T ;
    while(T--) cin>>N , cout<<ans[N]<<endl ;
	return 0 ;
}
