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
const int L =1e4+5 ;
const db EPS=1e-6 ;
db A[L] ;
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; db K ; cin>>N>>K ;
	FN(i,N) cin>>A[i] ;
	db lo=0,hi=1000.1 ;
	while(hi-lo>EPS)
	{
		db mid = (lo+hi)/2 ;
		db lost=0,gained=0 ;
		FN(i,N)
		{
			if(A[i]>mid) lost += A[i]-mid ;
			else gained += mid-A[i] ;
		}
		// cout<<"lost "<<lost<<" gained "<<gained<<" mid "<<mid<<endl ;
		if( (lost*(1-(K/100.00)) ) > gained) lo=mid ;
		else hi=mid ;
	}
	cout<<setprecision(7)<<lo<<endl ;
	return 0 ;
}
