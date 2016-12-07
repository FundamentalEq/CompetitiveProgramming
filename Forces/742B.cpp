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
const int L = 2e5+5 ;
int ct[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,x,temp ; cin>>N>>x ;
    ll ans = 0 ;
    FEN(i,N) 
    {
        cin>>temp ;
        ans += ct[x^temp] ;
        ++ct[temp] ;
    }
    cout<<ans<<endl ;
    return 0 ;
}
