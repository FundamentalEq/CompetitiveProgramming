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
	int n,K,a,b,left ; cin>>n>>K>>a>>b ;
    char aa = 'G' , bb = 'B' ;
    if(a<b) swap(a,b) , swap(aa,bb) ;
    left = a - (b+1) ;
    if((ll)left > (ll)(b+1)*(ll)(K-1))
    {
        cout<<"NO"<<endl ;
        return 0 ;
    }
    vector<char> ans(n,'$') ;
    int Index = 0 ;
    if(a == b)
        FN(i,2*b) ans[Index++] = (i&1) ? aa : bb ;
    else FN(i,2*b+1)
    {
        if(i&1) ans[Index++] = bb ;
        else
        {
            ans[Index++] = aa ;
            FN(j,min(left,K-1)) ans[Index++] = aa ;
            left -= K-1 ;
        }
    }
    for(auto c:ans) cout<<c ; cout<<endl ;
    return 0 ;
}
