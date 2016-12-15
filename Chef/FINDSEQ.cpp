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
const int L = 1005 ;
const int inf = 2e9 ;
int IN[L] ,A[5]; vi pre[L] ,suf[L] ;
string B ;
bool satsify(int b1,int b2,int a1,int a2)
{
    if((a1!=a2) && (B[b1]>B[b2]) == (a1>a2)) return true ;
    return false ;
}
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL) ;
	int T,N,upper ; cin>>T ;
    bool ans ;
    while(T--)
    {
        ans = false ;
        cin>>N>>B ;
        FEN(i,N) cin>>IN[i] ;
        FEN(i,N-3)
        {
            pre[i].clear() ;
            FEN(j,i-1) if(satsify(0,1,IN[j],IN[i]))pre[i].pb(IN[j]) ;
            sort(pre[i].begin(),pre[i].end()) ;
        }
        for(int i=4;i<=N;++i)
        {
            suf[i].clear() ;
            for(int j=i+1;j<=N;++j) if(satsify(3,4,IN[i],IN[j]))suf[i].pb(IN[j]) ;
            sort(suf[i].begin(),suf[i].end()) ;
        }
        vi::iterator it ;
        set<int> S ;
        set<int>::iterator it2 ;
        for(int i=2;i<=(N-3);++i) if(!pre[i].empty())
        {
            S.clear() ;
            if(satsify(1,2,IN[i],IN[i+1])) S.insert(IN[i+1]) ;
            for(int j=i+2;j<N;++j) //b1 and b3 are satisfied
            {
                if(satsify(1,3,IN[i],IN[j]) && !S.empty() && !suf[j].empty())
                {
                    upper = inf ;
                    for(int k=5;k>0;--k)
                    {
                        if(B[0]-'0' == k)
                        {
                            it = lower_bound(pre[i].begin(),pre[i].end(),upper) ;
                            if(it == pre[i].end()) --it ;
                            while(it!=pre[i].begin() && *it >= upper) --it ;
                            if(*it < upper && satsify(0,1,*it,IN[i]) && satsify(0,3,*it,IN[j])) A[0] = upper = *it ;
                            else break ;
                        }
                        else if(B[1] -'0' == k)
                        {
                            if(IN[i] >= upper) break ;
                            A[1] = upper = IN[i] ;
                        }
                        else if(B[2]-'0' == k)
                        {
                            it2 = S.lower_bound(upper) ;
                            if(it2 == S.end()) --it2 ;
                            while(it2!=S.begin() && *it2 >= upper) --it2 ;
                            if(*it2 < upper && satsify(2,3,*it2,IN[j])) A[2] = upper = *it2 ;
                            else break ;
                        }
                        else if(B[3] -'0' == k)
                        {
                            if(IN[j] >= upper) break ;
                            A[3] = upper = IN[j] ;
                        }
                        else if(B[4]-'0' == k)
                        {
                            it = lower_bound(suf[j].begin(),suf[j].end(),upper) ;
                            if(it == suf[j].end()) --it ;
                            while(it!=suf[j].begin() && *it >= upper) --it ;
                            if(*it < upper&& satsify(4,1,*it,IN[i]) && satsify(4,3,*it,IN[j])) A[4] = upper = *it ;
                            else break ;
                        }
                        if(k==1) ans = true ;
                  }
              }
              if(ans) break ;
              if(satsify(1,2,IN[i],IN[j])) S.insert(IN[j]) ;
            }
            if(ans) break ;
        }
        if(!ans) cout<<-1<<endl ;
        else
        {
            int k = 0 ;
            FEN(i,N) if(IN[i] == A[k])
            {
                A[k++] = i-1 ;
                if(k == 5) break ;
            }
            FN(i,5) cout<<A[i]<<" " ; cout<<endl ;
        }
    }
    return 0 ;
}
