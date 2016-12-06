#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		string s; cin >> s;
		vector<int> ans;
		for(int j = 1; j <= 12; j++)
		{
			int flag = 1;
			if(12%j == 0)
			{
				int jump = 12/j;
				for(int k = 0; k < jump; k++)
				{
					flag = 1;
					for(int l = 0; l < 12; l += jump)
					{
					//	cout << l+k << " ";
						if(s[l+k] == 'O') flag = 0;
					}
					if(flag == 1)
					{
						ans.push_back(j);
						break;
					}
				}
			}	
		}
		cout << ans.size() << " ";
		for(int j = 0; j < ans.size(); j++) cout << ans[j] << "x" << 12/ans[j] << " ";
		cout << endl;
	}
	return 0;
}
