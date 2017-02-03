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
const int L = 2e5+5 ;
int IN[L],temp[L];
map<int,bool> X ;
bool fix(int ee,int oo,int N,int M)
{
    //cout<<"ee is "<<ee<<endl ;
    X.clear() ;
    FEN(i,N) if( (IN[i]&1) == (ee&1) ) X[IN[i]] = false ;
    //for(auto it:X) cout<<it.f<<" "<<it.s<<endl ;
    int e = 0 ;
    FEN(i,N) if( (IN[i]&1) == (ee&1) )
    {
        if(e == (N>>1)) IN[i] = oo ;
        else if(!X[IN[i]]) X[IN[i]] = true , ++e ;
    }
    //for(auto it:X) cout<<it.f<<" "<<it.s<<endl ;
    //cout<<"e is "<<e<<endl ;
    if(e == (N>>1)) 
    {
        FEN(i,N) if( (IN[i]&1) == (ee&1) )
        {
            if(X[IN[i]]) X[IN[i]] = false ;
            else IN[i] = oo ;
        }
        return true ;
    }
    //cout<<"oollaaa"<<endl ;
    int it = ee;
    FEN(i,N) if( (IN[i]&1) == (ee&1) )
    {
        //cout<<"IN[i] = "<<IN[i]<<endl ;
        if(X[IN[i]]) { X[IN[i]] = false ; continue ; }
        if(e == (N>>1)) { IN[i] = oo ; continue ; }
        while(X.find(it)!=X.end()) it += 2 ;
        if(it > M) return false ;
        IN[i] = it ; ++e ;
        //cout<<"it is "<<it<<endl ;
        X[IN[i]] = 1 ;
    }
    return true ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N,M,e=0,ee=2,o=0,oo=1,n,it ; cin>>N>>M ;
    FEN(i,N) cin>>IN[i],e += (IN[i]&1) == 0 ,o+= IN[i]&1,temp[i] = IN[i] ;
    if(e<o) swap(ee,oo) ;
    bool  a = fix(ee,oo,N,M) ;
    a &= fix(oo,ee,N,M) ;
    if( a)
    {
        int ans = 0 ;
        FEN(i,N) if(temp[i]!=IN[i]) ++ans ;
        cout<<ans<<endl ;
        FEN(i,N) cout<<IN[i]<<" " ; cout<<endl ;
    }
    else cout<<-1<<endl; 
    return 0 ;
}
