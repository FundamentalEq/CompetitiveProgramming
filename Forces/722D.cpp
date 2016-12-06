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
map<int,int> X ;
bool fix(int x)
{
	// cout<<x<<endl ;
	int cur = x>>1  ;
	if(!cur) return false ;
	while(X[x]>0 && cur>0)
	{
		// cout<<" for x "<<x<<" == "<<X[x]<<endl ;
		if(X[cur]==0) X[cur]=1 ;
		else
		{
			// cout<<"cur "<<cur<<" == "<<X[cur]<<endl ;
			if(fix(cur)) X[cur]=1 ;
			else return false ;
		}
		cur>>=1 ; X[x]-- ;
	}
	if(X[x]) return false ;
	X.erase(x) ;
	return true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,temp ; cin>>N ;
	FEN(i,N) cin>>temp , X[temp]++ ;
	while(fix(X.rbegin()->f)) ;
	for(auto x:X) FN(i,x.s) cout<<x.f<<" " ;
	cout<<endl ;
	return 0 ;
}
