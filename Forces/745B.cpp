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
int dp[505][505] ;
string A[505] ;
int l = -1 ,r = 5000 ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M ; cin>>N>>M ;
    FEN(i,N) cin>>A[i] ;
    bool ans = true ;
    int mx = 0 ;
    FEN(i,N)
    {
        int ct = 0 ;
        FEN(j,M) 
        {
            if(A[i][j-1]=='X')
            {
                ++ct ;
                dp[i][j] = dp[i][j-1] + 1 ;
                if(ct!=dp[i][j]) ans = false ;
                if(mx > 0 && dp[i][j]!=dp[i-1][j]) ans = false ; 
            }
        }
        if(mx == 0 && ct > 0) mx = ct  ;
        if(mx>0 && ct>0 && mx!=ct) ans=false;  
    }
//    cout<<mx<<endl ;
  //  cout<<ct<<endl ;
    if(ans && mx > 0) cout<<"YES"<<endl ;
    else cout<<"NO"<<endl; 
    return 0 ;
}
