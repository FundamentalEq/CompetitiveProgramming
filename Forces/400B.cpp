#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 5;
char a[N][N]; int flag[N];
int main()
{
	bool ok = 1; 
	int ans = 0, n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) 
	{
		string s; cin >> s;
		for(int j = 0; j < s.length(); j++)
			a[i][j+1] = s[j];
	}
	for(int i = 1; i <= n; i++) 
	{
		int s, d;
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == 'S') s = j;
			if(a[i][j] == 'G') d = j;
		}
		if(d > s) ok = 0;
		else if(s > d)
		{
			int dist = s-d;
			if(flag[dist] == 0) 
			{
				flag[dist] = 1;
				ans++;
			}
		}
	}
	cout << (ok ? ans : -1) << endl;
	return 0;
}
