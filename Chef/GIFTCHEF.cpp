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
const int mod = 1e9+7 ;
const int L = 3e5+5 ;
ll pre[L] ;
void cal_lps(string &S,vi &lps)
{
    int len=0 ; lps.pb(0) ;
    for(int i=1;i<sz(S);)
    {
        if(S[i]==S[len]) lps.pb(++len) ,++i ;
        else
        {
            if(len!=0) len=lps[len-1] ;
            else lps.pb(0),++i ;
        }
    }
}
void kmp(string &text,string &pattern,vi &lps,vi &online)
{
	for(int i=0,j=0;i<sz(text);)
	{
        if(text[i]==pattern[j])
		{
			++i,++j ;
			if(j==sz(pattern)) online.pb(i-sz(pattern)),j=lps[j-1] ;
        }
		else
		{
			if(j) j = lps[j-1] ;
			else ++i ;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ; string S,F ; vi lps,start ; int j ;
	cin>>T ;
	while(T--)
	{
		lps.clear() ,start.clear() ;
		cin>>S>>F ;
		cal_lps(F,lps) ;
		kmp(S,F,lps,start) ;
		FN(i,sz(S)+1) pre[i] = 0 ;
		j = sz(start) - 1 ;
		for(int i = sz(S)-1 ; i >=0 ;--i)
		{
			pre[i] = pre[i+1]  ;
			if(j>=0) if(i == start[j])
			{
				pre[i] = (pre[i] + 1 + pre[i+sz(F)])%mod ;
				--j ;
			}
		}
		cout<<pre[0]<<endl ;
	}
	return 0 ;
}
