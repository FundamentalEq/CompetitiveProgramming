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
const int L = 3e5+5 ;
vi divisor[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
    int N,a,b ; cin>>N ;
	FEN(i,N) for(int j = i ; j <=N ; j += i) divisor[j].pb(i) ;
    ll ans = 0 ;
    FEN(i,N-1)
    {
        a=i,b=N-i ;
        if(a > b) break ;
        for(auto d:divisor[b]) 
            ans  += lower_bound(divisor[a].begin(),divisor[a].end(),d)  - divisor[a].begin() ;
    }
    cout<<ans<<endl ;
    return 0 ;
}
