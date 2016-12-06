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
map<string,int> store ;
int main()
{
	std::ios::sync_with_stdio(false);
	string S ;
	int N ; cin>>N ;
	while(N--) cin>>S , store[S]++ ;
	vi temp ; FA(it,store) temp.pb(it->s) ;
	sort(temp.begin(),temp.end()) ;
	cout<<temp[sz(temp)-1]<<endl ;
	return 0 ;
}
