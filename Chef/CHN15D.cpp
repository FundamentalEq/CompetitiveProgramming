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
#define point pair<db,db>
const int L =1e5+5 ;
const db EPS = 1e-5 ;
const db bottom = -1e13 ;
db temp[L],A[L] ;
point Y[L],line[L] ;
ll count_no_of_inversions_merge(db base[],int l,int r)
{
	int m = (l+r)>>1 ;
	int p=l,q=m+1 ;
	ll ans = 0 ;
	for(int k=l;k<=r;++k)
	{
		if(q>r) temp[k]=base[p++] ,ans += r-m ;
		else if(p>m) temp[k]=base[q++] ;
		else if(base[p]<base[q]) temp[k]=base[p++] , ans += q-m-1 ;
		else temp[k]=base[q++] ;
	}
	for(int k=l;k<=r;++k) base[k]=temp[k] ;
	return ans ;
}
ll count_no_of_inversions(db base[],int l,int r)
{
	if(l==r) return 0;
	int m = (l+r)>>1 ;
	ll left = count_no_of_inversions(base,l,m) ;
	ll right = count_no_of_inversions(base,m+1,r) ;
	return count_no_of_inversions_merge(base,l,r) + left + right ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ;ll K ; cin>>N>>K ;
	FEN(i,N) cin>>line[i].f>>line[i].s ;
	db lo = -1e12 ,hi=1e12 ;
	while(hi-lo>EPS)
	{
		db m = (lo+hi)*0.5 ;
		FEN(i,N)
		{
			Y[i].f = (bottom-line[i].s)/line[i].f ;
			Y[i].s = (m-line[i].s)/line[i].f ;
			// cout<<"i "<<i<<" "<<Y[i].s<<endl ;
		}
		FEN(i,N-1) assert(Y[i].f!=Y[i+1].f) ;
		sort(Y+1,Y+N+1) ;
		FEN(i,N) A[i]=Y[i].s ;
		ll cur = count_no_of_inversions(A,1,N) ;
		// cout<<"for mid "<<m<<" inversionsa are "<<cur<<endl  ;
		if(cur<K)lo=m ;
		else hi=m ;
		// break ;
	}
	cout<<setprecision(11)<<hi<<endl ;
	return 0 ;
}
