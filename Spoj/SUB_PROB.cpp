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
const int Climit = 52 ;
struct ahoNode
{
    bool word ;
    ahoNode* C[Climit] , *suf ;
    ahoNode(void) { word = 0 ; FN(i,Climit) C[i] = NULL ; suf = NULL ;}
} ;
ahoNode* ahoInsert(vi &S,ahoNode *head)
{
    ahoNode *cur = head ;
    for(auto c:S)
    {
        if(cur->C[c] == NULL) cur->C[c] = new ahoNode ;
        cur = cur->C[c] ;
    }
    return cur ;
}
void ahoSufLinks(ahoNode *head)
{
    head->suf = head ;
    queue<pair<int,ahoNode*> > Q ;
    FN(i,Climit) if(head->C[i]!=NULL)
    {
        head->C[i]->suf = head ;
        FN(j,Climit) if(head->C[i]->C[j]!=NULL) Q.push({j,head->C[i]}) ;
    }
    int level,c ; ahoNode *suf,*p ;
    while(!Q.empty())
    {
        level = sz(Q) ;
        while(level--)
        {
            c = Q.front().f , p = Q.front().s ; Q.pop() ;
            suf = p->suf ;
            while(suf->C[c] == NULL && suf!=head) suf = suf->suf ;
            if(suf->C[c]!=NULL) suf = suf->C[c] ;
            p->C[c]->suf = suf ;
            FN(j,Climit) if(p->C[c]->C[j]!=NULL) Q.push({j,p->C[c]}) ;
        }
    }
}
void ahoFind(vi &S,ahoNode *head) 
{
    ahoNode *cur = head ,*suf ;
    for(auto c:S)
    {
        while(cur->C[c] == NULL && cur!=head) cur = cur->suf ;
        if(cur->C[c]!=NULL) cur = cur->C[c] ;
        cur->word = true ;
        suf = cur->suf ;
        while(suf!=head && !suf->word) suf->word = true , suf = suf->suf ;
    }
}
void convert(vi &A,string &B)
{
     A.clear() ;
     for(auto c:B)
     {
        if(c>='a' && c<='z') A.pb(c-'a') ;
        else A.pb(c-'A' + 26) ;
     }
}
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ;
    string target ; cin>>target;
    int N ; cin>>N ;
    ahoNode* head = new ahoNode ;
    string S ; vi Snew ;
    vector<ahoNode*> ans(N,NULL) ;
    FN(i,N) 
    {
        cin>>S ;
        convert(Snew,S) ;
        ans[i] = ahoInsert(Snew,head) ;
    }
	ahoSufLinks(head) ;
    convert(Snew,target) ;
    ahoFind(Snew,head) ;
    FN(i,N) cout<<(ans[i]->word ? "Y" : "N" )<<endl ;
    return 0 ;
}
