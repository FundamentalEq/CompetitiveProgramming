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
bool valid(string &A)
{
	FN(i,sz(A)) if( A[i]!='?' && (A[i] == A[(i-1+sz(A))%sz(A)] || A[i]==A[(i+1)%sz(A)]) ) return false ;
	return true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T,K ; string S ; bool ans  ;
	cin>>T;
	while(T--)
	{
		ans = true ;
		cin>>K>>S ;
		if(sz(S) == 1 )
		{
			cout<<(S=="?"?"0":S)<<endl ;
			continue ;
		}
		if(!valid(S))
		{
			cout<<"NO"<<endl ;
		 	continue ;
		}
		if(K==2)
		{
			if(sz(S)%2 == 0)
			{
				string temp = S ;
				FN(i,sz(S))
				{
					if(temp[i]!= '0'+i%2 && temp[i]!='?') {ans=false;break;}
					else temp[i] = '0' + i%2 ;
				}
				if(!ans)
				{
					temp = S ; ans=true;
					FN(i,sz(S))
					{
						if(temp[i]!='0'+1-i%2 && temp[i]!='?') {ans=false;break;}
						else temp[i] = '0' + 1 - i%2 ;
					}
				}
				cout<<(ans?temp:"NO")<<endl ;
				continue ;
			}
			else cout<<"NO"<<endl ;
			continue ;
		}
		FN(i,sz(S)) if(S[i]=='?')
		{
			S[i] = '0' ;
			while(S[i] == S[(i-1+sz(S))%sz(S)] || S[i] == S[(i+1)%sz(S)]) ++S[i] ;
			if(S[i]-'0'>=K) { ans = false ; break ; }
		}
		cout<<(ans?S:"NO")<<endl ;
	}
	return 0 ;
}
