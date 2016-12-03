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
vi ad[30] ;
bool win[30][30] ,done[30][30] ;
void cal_lps(string &S,vi &lps)
{
    int len=0 ;lps.clear() ; lps.pb(0) ;
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
void kmp(string &text,string &pattern,vi &lps)
{
	for(int i=0,j=0;i<sz(text);)
	{
        if(text[i]==pattern[j])
		{
			++i,++j ;
			if(j==sz(pattern)) ad[i-sz(pattern)].pb(i-1),j=lps[j-1] ;
        }
		else
		{
			if(j) j = lps[j-1] ;
			else ++i ;
		}
	}
}
int fans(int i,int j)
{
	if(j<i) return 0 ;
	if(done[i][j]) return win[i][j] ; done[i][j] = true ;
	vi temp ;
	for(int x=i;x<=j;++x)
		for(auto y:ad[x])
		{
			if(y<=j) temp.pb( fans(i,x-1) ^ fans(y+1,j) ) ;
			else break ;
		}
	win[i][j] = 0 ;
	sort(temp.begin(),temp.end()) ;
	for(auto t:temp)
	{
		if(t == win[i][j]) ++win[i][j] ;
		if(t > win[i][j]) break ;
	}
	return win[i][j] ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ; cin>>T ;
	while(T--)
	{
			string S,word ; cin>>S ;
			int N ; cin>>N ;
			vi lps ;
			FN(i,sz(S)) ad[i].clear() ;
			FN(i,sz(S)) FN(j,sz(S)) win[i][j]=done[i][j]=false ;
			FN(i,N)
			{
				cin>>word ;
				cal_lps(word,lps) ;
				kmp(S,word,lps) ;
			}
			FN(i,sz(S)) sort(ad[i].begin(),ad[i].end()) ;
			cout<<(fans(0,sz(S)-1)?"Teddy":"Tracy")<<endl  ;
	}
	return 0 ;
}
