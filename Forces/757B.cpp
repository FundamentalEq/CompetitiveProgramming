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
int G[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,temp ; cin>>N ;
    while(N--)
    {
        cin>>temp ;
        for(int i=2;i*i <= temp ; ++i) if(temp%i == 0)
        {
            ++G[i] ;
            while(temp%i == 0) temp/=i ;
        }
        if(temp > 1) ++G[temp] ;
    }
    int mx = 1 ;
    for(int i=2;i<L;++i) mx = max(mx,G[i]) ;
    cout<<mx<<endl ;
    return 0 ;
}
