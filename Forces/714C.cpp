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
};
node *head ;
node *new_node(void)
{
	node *temp=new node ;
	FN(i,2) temp->child[i]=NULL ;
	temp->ct=0 ;
	return temp ;
}
string topat(ll x)
{
	string temp="" ;
	// cout<<x<<"   =   " ;
	FEN(i,18) temp = temp + ((x&1)?"1":"0") , x/=10 ;
	// cout<<temp<<endl ;
	return temp ;
}
void add(string S,int c)
{
	node *cur=head ;
	for(int level=0;level<18;++level)
	{
		int bit = S[level]=='0' ?0:1 ;
		if(cur->child[bit]==NULL) cur->child[bit]=new_node() ;
		cur=cur->child[bit] ;
		cur->ct += c ;
	}
}
int query(string S)
{
	// cout<<S<<endl ;
	node *cur=head ;
	for(int level=0;level<18;++level)
	{
		int bit=S[level]=='0'?0:1 ;
		if(cur->child[bit]==NULL) return 0 ;
		cur=cur->child[bit] ;
	}
	return cur->ct ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T; cin>>T ;
	string type , pattern ;
	head=new_node() ;
	while(T--)
	{
		cin>>type ;
		if(type=="+")
		{
			ll a ;
			cin>>a ;
			string cur = topat(a) ;
			add(cur,1) ;
		}
		else if(type=="-")
		{
			ll a ; cin>>a ;
			string cur = topat(a) ;
			add(cur,-1) ;
		}
		else if(type=="?")
		{
			cin>>pattern ; reverse(pattern.begin(),pattern.end()) ;
			while(sz(pattern)<18) pattern = pattern + "0" ;
			cout<<query(pattern)<<endl ;
		}
	}
	return 0 ;
}
