#include "bits/stdc++.h"
#define mod 1e7+9
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
const int L =1e5+5 ;
struct tuple
{ int u,v,x ;} ;
int C[505] ,P[L],Ch[L],pre[505],type[L] ;
long long S[505][505] ;
tuple IN[L] ;
int fp(int x)
{
	if(P[x]==0) return x ;
	return P[x]=fp(P[x]) ;
}
	
int main()
{
	int N,M,K ; cin>>N>>M>>K ;	
	for(int i=1;i<=K;++i) cin>>C[i],pre[i]=pre[i-1]+C[i] ;
	for(int i=1;i<=N;++i) Ch[i]=1 ;
	for(int i=1;i<=M;++i) 
	{
		cin>>IN[i].u>>IN[i].v>>IN[i].x ;
		if(IN[i].x == 0)
		{
			int u = fp(IN[i].u) , v= fp(IN[i].v) ;
			if(Ch[u]<Ch[v]) swap(u,v) ;
			P[v]=u , Ch[u] += Ch[v] ;
		}
	}
	bool ans=true ;
	for(int k=1;k<=K && ans ;++k)
	{
		for(int i=pre[k-1]+1;i+1<=pre[k];++i) if( fp(i)!=fp(i+1)) 
		{
			ans=false ;
			break ;
		}
		for(int i=pre[k-1]+1;i<=pre[k];++i) type[i]=k ;
	}
	if(!ans)
	{
		cout<<"No"<<endl ;
		return 0 ;
	}
	for(int i=1;i<=K;++i) for(int j=1;j<=K;++j) if(i!=j) S[i][j]=INT_MAX ;
	for(int i=1;i<=M;++i)
	{
		int u=type[IN[i].u],v=type[IN[i].v] ;
		S[u][v]=min(S[u][v],(long long)IN[i].x) , S[v][u]=min(S[v][u],(long long)IN[i].x) ;
	}
	for(int k=1;k<=K;++k) for(int i=1;i<=K;++i) for(int j=1;j<=K;++j) S[i][j]=min(S[i][j],S[i][k]+S[k][j]) ;
	cout<<"Yes"<<endl ;
	for(int i=1;i<=K;++i) for(int j=1;j<=K;++j) if( S[i][j]==INT_MAX) S[i][j]=-1 ;
	for(int i=1;i<=K;++i)
	{
		for(int j=1;j<=K;++j) cout<<S[i][j]<<" " ;
		cout<<endl ;
	}
	return 0;
}
