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
const int L = 16 ;
int dp[1<<L][2][L*L] ,R[L],B[L] ;
string C[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
    int N,red = ,blue =0 ,ans = 0 ; cin>>N ;
    memset(dp,-1,sizeof(dp)) ;
    FN(i,N) 
    {
        cin>>C[i]>>R[i]>>B[i] ;
        red += max(R[i] - N,0) ,blue += max(B[i] -N,0) ;
        R[i] = min(R[i],N) , B[i] = min(B[i],N) ;
    }
    FEN(i,(1<<N) - 1)
    {

    }
	return 0 ;
}
