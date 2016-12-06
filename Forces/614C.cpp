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
#define point pair<db,db>
using namespace std ;
const int L = 1e5+5 ;
point IN[L] ;
db dot(point a,point b) { return a.f*b.f + a.s*b.s ;}
point Mi5(point a,point b){ return mp(a.f-b.f,a.s-b.s);}
point mult(db x,point a) {return mp(a.f*x,a.s*x);}
db mod(point a){ return sqrt(a.f*a.f+a.s*a.s);}
db min_dis(point a,point b,point c)
{
	if(dot(Mi5(a,c),Mi5(a,b))*dot(Mi5(b,c),Mi5(a,b)) >=0 ) return 1e12 ;
	// cout<<"A = ("<<a.f<<","<<a.s<<")"<<endl  ;
	// cout<<"B = ("<<b.f<<","<<b.s<<")"<<endl  ;
	point A=Mi5(a,c) ,B=Mi5(b,c) ;
	db area = (A.f*B.s - A.s*B.f) ; area=abs(area) ;
	return area/mod(Mi5(a,b)) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	point P ; int N ; cin>>N>>P.f>>P.s ;
	db dmax=0,dmin=1e13 ;
	FN(i,N) cin>>IN[i].f>>IN[i].s,dmin=min(dmin,mod(Mi5(P,IN[i]))),dmax=max(dmax,mod(Mi5(P,IN[i]))) ;
	// cout<<"dmin is "<<dmin<<endl ;
	FN(i,N) dmin=min(min_dis(IN[i],IN[(i+1)%N],P),dmin) ;
	// cout<<"dmin is "<<dmin<<endl ;
	cout<<setprecision(20)<<M_PI*(dmax*dmax-dmin*dmin) <<endl;
	return 0 ;
}
