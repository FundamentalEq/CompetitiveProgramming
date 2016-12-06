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
int querry(int A[])
{
	cout<<"? " ;
	FN(i,4)cout<<A[i]<<" " ; //cout<<endl ;
	fflush(stdout) ;
	int temp ; cin>>temp ;
	return temp ;
}
void bsearch(int A[],int k)
{
	// cout<<"k is "<<k<<endl ; fflush(stdout);
	int lo=(k&1)?A[1]:A[0] ,hi=(k&1)?A[3]:A[2] ;
	while(lo<hi)
	{
		// cout<<"lo = "<<lo<<" hi = "<<hi<<endl ;
		int mid=(lo+hi+((k>1)?0:1))>>1 ;
		int B[4] ; FN(i,4) B[i]=A[i] ; B[k]=mid ;
		if(querry(B))
		{
			if(k>1) hi=mid ;
			else lo=mid ;
		}
		else
		{
			if(k>1)lo=mid+1 ;
			else hi=mid-1 ;
		}
	}
	A[k]=(k>1)?hi:lo ;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N ; cin>>N ;
	int A[4],B[4] ;
	FN(i,4) A[i]=B[i]=(i>1)?N:1 ;
	bsearch(A,3);bsearch(A,2);bsearch(A,0);bsearch(A,1);
	bsearch(B,0);bsearch(B,1);bsearch(B,2);bsearch(B,3);
	cout<<"! " ; FN(i,4)cout<<A[i]<<" " ; FN(i,4)cout<<B[i]<<" " ;
	cout<<endl ; fflush(stdout) ;
	return 0 ;
}
