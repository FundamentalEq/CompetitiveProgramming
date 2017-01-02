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
int dis(int a,int b,int &d,int s)
{
    if((b-a)*d >= 0) return (b-a)*d ;
    if(a<b)
    {
        d = 1 ;
        return a + b ;
    }
    d = -1 ;
    return 2*s - a - b ; 
}
int main()
{
	std::ios::sync_with_stdio(false);
	int s,x1,x2,t1,t2,p,d ; cin>>s>>x1>>x2>>t1>>t2>>p>>d ;
    int ans = abs(x1-x2) * t2 ;
    ans = min(ans , (dis(p,x1,d,s) + dis(x1,x2,d,s))*t1 ) ;
    cout<<ans<<endl ;
    return 0 ;
}
