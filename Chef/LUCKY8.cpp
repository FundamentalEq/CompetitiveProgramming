#include <bits/stdc++.h>
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define db long double
using namespace std ;
void digitse(ll x,vi &a)
{
	a.clear() ;
	while(x) a.pb(x%10),x/=10 ;
}
int fans(int f,int s,int i)
{
		if(f<s) swap(f,s) ;
		int diff = f-s ;
		s += min(diff,i) ,i -= min(diff,i) ;
		return (f + i/2)*(s + i - i/2) ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T ,ans,s,f,temps,tempf ;
	ll l,r ;cin>>T ;
	bool done ;
	vi a,b ;
	while(T--)
	{
			ans = s = f = done = 0 ;
			cin>>l>>r ;
			digitse(l,a) ,digitse(r,b) ;
			while(sz(a)<sz(b)) a.pb(0) ;
			reverse(a.begin(),a.end()) ,reverse(b.begin(),b.end()) ;
			FN(i,sz(a))
			{
					if(a[i] == b[i])
					{
							s+= a[i]==7 ;
							f+= a[i]==4 ;
					}
					else
					{
							if(a[i]<4 && 7<b[i]) ans = max(ans,fans(f,s,sz(a)-i) );
							else if(a[i]<4 && 4<b[i]) ans=max(ans,fans(f+1,s,sz(a)-i-1) );
							else if(a[i]<7 && 7<b[i]) ans = max(ans,fans(f,s+1,sz(a)-i-1)) ;
							else if(b[i]-a[i]>1) ans=max(ans,fans(f,s,sz(a)-i-1)) ;
							
							//x[i] == a[i]
							temps = s , tempf = f ;
							temps += a[i] == 7 , tempf += a[i]==4 ;
							for(int j = i+1 ; j < sz(a) ; ++j)
							{
									if(a[j] < 4) ans = max(ans,fans(tempf,temps,sz(a)-j) );
									else if(a[j]<7) ans = max(ans,fans(tempf,temps+1,sz(a)-j-1)) ;
									else if(a[j]<9) ans = max(ans,fans(tempf,temps,sz(a)-j-1)) ; 
									temps += a[j] == 7 , tempf += a[j]==4 ;
							}
							ans = max(ans,temps*tempf) ;	
							//x[i] == b[i]
							temps = s , tempf = f ;
							temps += b[i] == 7 , tempf += b[i]==4 ;
							for(int j = i+1 ; j < sz(a) ; ++j)
							{
									if(b[j] > 7) ans = max(ans,fans(tempf,temps,sz(a)-j) );
									else if(b[j]>4) ans = max(ans,fans(tempf+1,temps,sz(a)-j-1)) ;
									else if(b[j]>0) ans = max(ans,fans(tempf,temps,sz(a)-j-1)) ; 
									temps += b[j] == 7 , tempf += b[j]==4 ;
							}
							ans = max(ans,temps*tempf) ;	
							cout<<ans<<endl ;
							done = 1;
							break ;
					}
			}
			if(!done) cout<<s*f<<endl ;
	}
	return 0 ;
}
