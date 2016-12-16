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
struct snode
{
    snode *l,*r ;
    int val,size ;
    bool reverse ;
    snode(snode* tl=NULL,snode* tr=NULL,int tval=0) { l=tl,r=tr,val=tval,size=1,reverse=0 ; }
} *Nil;
void update(snode *X)
{
    if(X == Nil) return ;
    X->size = X->l->size + X->r->size + 1 ;
}
stack <snode*> Updates ;
void do_updates(void) { while(!Updates.empty()) { update(Updates.top()) ; Updates.pop() ; } } //do all the pending updates
snode* link(snode* L,snode *X,snode* R) { X->l=L,X->r=R ; update(X) ;return X;}
snode* lzig(snode* L,snode* X) { return link(L->l,L,link(L->r,X,X->r)) ; } //right rotation lzig(node,parent(node)) ;
snode* rzig(snode* X,snode* R) { return link(link(X->l,X,R->l),R,R->r) ; } //left rotation rzig(parent(node),node) ;
snode *access(snode* X)
{
    if(X == Nil) return NULL ;
    if(X->reverse)
    {
        swap(X->l,X->r) ;
        if(X->r!=Nil) X->r->reverse ^=1 ;
        if(X->l!=Nil) X->l->reverse ^=1 ;
        X->reverse = false ;
    }
    return X ;
}
void foo(snode *head)
{
    if(head == Nil) return ;
    head = access(head) ;
    foo(head->l) ;
    cout<<(int)(head->val)<<" " ;
    foo(head->r) ;
}
void print(snode *head)
{
    if(head == Nil) return ;
    head = access(head) ;
    cout<<(int)(head->val)<<endl ;
    cout<<"--left-->" ; print(head->l) ;
    cout<<"--right-->" ;print(head->r) ;
    cout<<"<--back--"<<endl ;
}
snode* SplayIndex(snode* X,int Index)
{
    if(Index) --Index ;
    if(!access(X)) return X ;
    snode Header(Nil,Nil) ;
    snode *l,*r ; l = r = &Header ;
    while(access(X) && X->l->size!=Index)
    {
        if(access(X->l) && X->l->l->size > Index) { X = lzig(X->l,X) ; continue ;}
        if(access(X->r) && X->l->size + 1 + X->r->l->size + 1 <= Index) { X = rzig(X,X->r) ; continue ; }
        if(X->l->size > Index)
        {
            snode *P = X ; X=X->l ;
            r->l = P ,Updates.push(P) ;
            r = P ;
        }
        else
        {
            Index -= X->l->size + 1 ;
            snode *P = X ; X= X->r ;
            l->r = P ; Updates.push(P) ;
            l = P ;
        }
    }
    r->l = X->r ,l->r = X->l ; Updates.push(X->r) ,Updates.push(X->l) ;
    do_updates() ;
    X->l = Header.r , X->r = Header.l ; update(X) ;
    return X ;
}
void split(snode *head,int x,snode **l,snode **r)
{
    if(x == 0)
    {
        *l = Nil , *r = head ;
        return ;
    }
//    cout<<"inside split x = "<<x<<endl ;
    head = SplayIndex(head,x) ;
  //  cout<<"printing head";print(head) ; cout<<endl ;
    *r = head->r , *l = link(head->l,head,Nil) ;
    //cout<<"printing l";print(*l);cout<<endl ;
   // cout<<"printing r";print(*r);cout<<endl ;
}
snode* create(int l,int r)
{
    if(l>r) return Nil ;
    if(l==r) return new snode(Nil,Nil,l) ;
    int m = (l+r)>>1 ;
    return link(create(l,m-1),new snode(Nil,Nil,m),create(m+1,r)) ;
}
snode* merge(snode* l, snode* r)
{
    if(!access(r)) return l ;
    if(!access(l)) return r ;
//    cout<<"inside merge before" ; print(r) ; cout<<endl<<endl ;
    r = SplayIndex(r,0) ;
  //  cout<<"inside merge" ; print(r) ; cout<<endl<<endl ;
    r = link(l,r,r->r) ;
    return r ;
}
int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL) ;
	Nil = new snode ; Nil->size = 0 ,Nil->l=Nil->r = Nil ;
    snode *head = Nil,*aa,*bb,*cc,*t ;
    int N,M,a,b,c ; cin>>N>>M ;
    head = create(1,N) ;
    while(M--)
    {
        cin>>a>>b>>c ;
        split(head,a,&aa,&t) ; head = t ;
    //    cout<<"aa" ; print(aa) ; cout<<endl<<endl ;
        split(head,b,&bb,&t) ; head = t ;
        head = merge(aa,head) ;
      //  cout<<"merg1"; foo(head) ; cout<<endl<<endl ;
        split(head,c,&cc,&t) ; head = t ;
        //cout<<"cc" ; print(cc) ; cout<<endl<<endl ;
        bb->reverse ^=1 ;
        head = merge(bb,head) ;
       // cout<<"merg2"; foo(head) ; cout<<endl<<endl ;
        head = merge(cc,head) ;
       // cout<<"merg3"; foo(head) ; cout<<endl<<endl ;
    }
    foo(head) ; cout<<endl ;
    return 0 ;
}
