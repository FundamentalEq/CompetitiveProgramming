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
const int L = 1e5+5 ;
const db EPS = (db)1e-10 ;
class point
{
	public:
		db x,y ;
		point(db a=0,db b=0) {x=a,y=b ;}
		db slope(point b)
		{
			if(x==0 && b.x==0) return DBL_MAX ;
			return (y-b.y)/(x-b.x) ;
		}
		db distance(point b) { return sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y)) ;}
		//dot product
		db operator ^ (point b) { return x*b.x + y*b.y ;}
		//cross product
		db operator * (point b) { return x*b.y - b.x*y ;}
		//vector subtraction
		point operator - (point b) { return point(x-b.x,y-b.y) ;}
		//vecctor addition
		point operator + (point b) { return point(x+b.x,y+b.y) ;}
};
point P[L] ;
//sort all the points in counterclock wise direction wrt point at location 0
//note : dont care for the distance !!check if the points can be colinear
struct sort_counterclockwise
{
	 bool operator()(point& a,point& b)
	 {
		 if( abs((a-P[0])*(b-P[0])) > EPS )return (a-P[0])*(b-P[0]) > 0 ;
		 else return P[0].distance(a) < P[0].distance(b) ;
	 }
};
void convexhull(vector<point> & Ans,int N)
{
	int bottom = 0 ;vector< point > valid,Hull ; stack< point > X;  point mid ;
	FN(i,N)  if(P[i].y<P[bottom].y || (P[i].y==P[bottom].y && P[i].x < P[bottom].x) ) bottom=i ;
	swap(P[0],P[bottom]) ;
	// cout<<"bottom point is "<<P[bottom].x<<" "<<P[bottom].y<<endl ;
	sort(P+1,P+N,sort_counterclockwise()) ;
	// cout<<"Points ins sorted order"<<endl ;
	// FN(i,N) cout<<P[i].x<<" "<<P[i].y<<endl ;
	valid.pb(P[0]) ;
	FEN(i,N-2) if( abs((P[i]-P[0])*(P[i+1]-P[0]))> EPS ) valid.pb(P[i]) ;
	valid.pb(P[N-1]) ;
	// cout<<"list of valid points"<<endl ;
	// FN(i,sz(valid)) cout<<valid[i].x<<" "<<valid[i].y<<endl ;
	if(sz(valid)<3) return  ;//convex hull cannot be formed
	FN(i,2) X.push(valid[i]) ;
	for(int i=2;i<sz(valid);++i)
	{
		// cout<<"i = "<<i<" point is "<<
		mid = X.top() ;  X.pop() ;
		if( (mid-X.top())*(valid[i]-X.top()) > 0 ) X.push(mid) , X.push(valid[i]) ;
		else X.push(valid[i]) ;
	}
	while(!X.empty()) Ans.pb(X.top()) ,X.pop() ;
	reverse(Ans.begin(),Ans.end()) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,T ; point temp  ;
	cin>>T ;
	while(T--)
	{
		cin>>N ;
		FN(i,N) cin>>P[i].x>>P[i].y ;
		vector<point> Ans ; convexhull(Ans,N) ;
		db perimeter=0 ;
		FN(i,sz(Ans)-1) perimeter += Ans[i].distance(Ans[i+1]) ;
		perimeter += Ans[0].distance(Ans[sz(Ans)-1]) ;
		cout<<perimeter<<endl;
		for(auto &p:Ans) cout<<p.x<<" "<<p.y<<endl ;
		cout<<endl ;
	}
	return 0 ;
}
