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
	string A ; cin>>A ;
    string B ;
    set<string>X ;
    FEN(i,sz(A))
    {
        B = A.substr(0,sz(A)-1) ;
        B =  A[sz(A)-1] + B ;
//        cout<<B<<endl ;
        X.insert(B) ;
        A = B ;
    }
    cout<<sz(X)<<endl ;
    return 0 ;
}
