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
int dsum(int x)
{
    int ans = 0 ;
    while(x) ans += x%10 ,x/=10 ;
    return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ,ans = 1; cin>>N ;
    FEN(i,N) if(N%i == 0 ) if(dsum(i) > dsum(ans)) ans = i ;
    cout<<ans<<endl ;
    return 0 ;
}
