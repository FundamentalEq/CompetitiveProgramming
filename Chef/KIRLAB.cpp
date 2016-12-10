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
const int L = 1e5+5 ;
int IN[L] ; ll dp[L][2] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int T,N ; cin>>T ;
    while(T--)
    {
        cin>>N ;
        FEN(i,N) cin>>IN[i] ; dp[N+1][0] = dp[N+1][1] = 0 ; IN[N+1] = IN[N] ;
        for(int i=N;i>0;--i)
        {
            dp[i][0] = max(dp[i+1][0],dp[i+1][1]) ;
            if(__gcd(IN[i],IN[i+1]) > 1 ) dp[i][1] = dp[i+1][0] + IN[i] ;
        }
        cout<<max(dp[1][0],dp[1][1])<<endl ;
    }
    return 0 ;
}
