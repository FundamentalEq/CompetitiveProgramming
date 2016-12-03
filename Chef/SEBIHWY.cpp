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
	int T ; cin>>T ;
	while(T--)
	{
			db s,sg,fg,d,t ; cin>>s>>sg>>fg>>d>>t ;
			db sp = s + ((d)*180)/t ;
			db seb = abs(sg-sp) ;
			db f = abs(fg -sp) ;
			if(f == seb) cout<<"DRAW"<<endl ;
			else cout<<(seb<f?"SEBI":"FATHER")<<endl ;
	}
	return 0 ;
}
