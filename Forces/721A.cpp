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
    string S ; vi ans ; int N ;
    cin>>N>>S ;
    int cur=0 ;
    FN(i,sz(S))
    {
        if(S[i]=='B') ++cur ;
        else
        {
            // cout<<i<<" "<<cur<<endl ;
            if(cur!=0) ans.pb(cur) ;
            cur=0 ;
        }
    }
    if(cur!=0) ans.pb(cur) ;
    cout<<sz(ans)<<endl ;
    if(sz(ans))
    {
        FN(i,sz(ans)) cout<<ans[i]<<" " ;
        cout<<endl ;
    }
    return 0 ;
}
