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
struct node
{
	node* child[2] ;
	int ct ;
} ;
int poo[32] ;
node* new_node(void)
{
	node *temp=new node ;
	temp->child[0]=temp->child[1]=NULL ;
	temp->ct=0 ;
	return temp ;
}
void insert(node *head,int x,int c)
{
	node *cur=head ;
	int bits[32] ; FN(i,31) bits[i]=x&1,x>>=1 ;
	reverse(bits,bits+31) ;
	FN(level,31)
	{
		if(cur->child[bits[level]]==NULL) cur->child[bits[level]]=new_node() ;
		cur=cur->child[bits[level]] ;
		cur->ct+=c ;
	}
}
int querry(node *head,int x)
{
	node *cur=head ;
	int bits[32] ; FN(i,31) bits[i]=x&1,x>>=1 ;
	reverse(bits,bits+31) ;
	int ans[32] ;
	FN(level,31)
	{
		int bit=bits[level]^1 ;	
		bool done=false ;
		if(cur->child[bit]!=NULL) if(cur->child[bit]->ct>0)
		{
			ans[level]=1 ;
			cur=cur->child[bit] ;
			done=true ;
		}
		if(!done)
		{
			ans[level]=0 ;
			cur=cur->child[bit^1] ;
		}
	}
	reverse(ans,ans+31) ;
	int A=0 ;
	FN(i,31) A += ans[i] ? poo[i] : 0  ;
	return A ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	node *head=new_node() ; insert(head,0,1) ;
	poo[0]=1 ;
	FEN(i,31) poo[i]=poo[i-1]<<1 ;
	int Q ; cin>>Q ;
	int x ; string S ;
	FN(i,Q)
	{
		cin>>S>>x ;
		if(S=="+") insert(head,x,1) ;
		else if(S=="-") insert(head,x,-1) ;
		else cout<<querry(head,x)<<endl ;
	}
	return 0 ;
}
