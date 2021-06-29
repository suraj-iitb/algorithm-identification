#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int cnt[100001];

int main()
{
	int n;
	cin >> n;
	for(int i =0;i<n;i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	bool j = false;
	for(int i =0;i<100001;i++)
	{
		while(cnt[i])
		{
			if(j)cout<<' ';
			cout<<i;
			cnt[i]--;
			j =1;
		}
	}
	cout<<endl;
	return 0;
}
