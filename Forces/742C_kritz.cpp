#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
const int N=1e3+5;
vi ad[10000];set<int> ck;bool visited[10000];int size[N];bool kp[N];
void cc(int v,bool &ki,int &l)
{
  if(visited[v]==1) return;
  visited[v]=1;l++;if(ck.find(v)!=ck.end()) ki=true;
  for(int i=0;i<ad[v].size();++i)
  {
    if(ck.find(ad[v][i])!=ck.end()) ki=true;
    cc(ad[v][i],ki,l);
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int n,m,k,u,c,v;bool ki=false;int l=0;
  cin>>n>>m>>k;
  int j=0;ll ans=0;int mx=0;
  for(int i=0;i<k;++i){ cin>>c; ck.insert(c);}
  for(int i=0;i<m;++i) { cin>>u>>v; ad[u].push_back(v);ad[v].push_back(u);}
  for(int i=1;i<=n;++i)
  {
    if(visited[i]==0)
    {
    cc(i,ki,l);
    size[j]=l;kp[j++] = ki;
    }
    ki=false;l=0;
  }
  for(int i=0;i<j;++i)
  {
    cout<<size[i]<<" "<<kp[i]<<endl;
    if(kp[i]==true) mx=max(mx,size[i]);
    else ans+=size[i];
  }
  ans+=mx;
  ans=ans*(ans-1)/2;
  u=0;
  for(int i=0;i<j;++i)
  {
    if(kp[i]==true && size[i]<mx)
    ans+=size[i]*(size[i]-1) /2;
    else if(size[i]==mx) u++;
  }
  ans+=(u-1) * (ll)(mx*(mx-1))/2;
  cout<<(int)(ans-m)<<endl;
  return 0;
}
