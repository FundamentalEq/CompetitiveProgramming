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
ll dp[55][1030];
string IN[55],s ;
vector<string> possible ;
void gen_pos(ll x)
{
    ll temp = x ;
    if(x>=(ll)1e9) return ;
    s.clear() ;
    while(x) s.pb(x%10 +'0' ) ,x/=10 ;
    while(sz(s)<9) s.pb('0') ;
    reverse(s.begin(),s.end()) ;
    possible.pb(s) ;
    gen_pos(10*temp+4) ,gen_pos(10*temp+7) ;
}
void make(string &a)
{
    reverse(a.begin(),a.end()) ;
    while(sz(a)<9) a.pb('0') ;
    reverse(a.begin(),a.end()) ;
//    cout<<a<<endl ;
}
int gmask(string &a,string &b)
{
    int ans = 0 ;
    FN(i,10) 
    {
        if(a[i]>b[i]) return -1 ;
        if(a[i] == b[i]) ans |= 1<<i ;
    }
    return ans ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	gen_pos(4) ,gen_pos(7) ;
    int T,N ; cin>>T ;
    while(T--)
    {
        cin>>N ;
        FEN(i,N) cin>>IN[i] ,make(IN[i]);
        ll ans = 0 ; int mask ;
        dp[0][0] = 1 ;
        for(auto l:possible)
        {
            FEN(i,N)
            {
                FN(j,1<<10) dp[i][j] = dp[i-1][j] ;
                mask = gmask(IN[i],l) ;
                if(mask == -1) continue ;
                FN(j,1<<10) dp[i][j|mask] += dp[i-1][j] ;
            }
//            cout<<l<<" : "<<dp[N][(1<<9)-1]<<endl ;
            ans += dp[N][(1<<10)-1] ;
        }
        cout<<ans<<endl ;
    }
    return 0 ;
}
