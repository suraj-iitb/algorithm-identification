#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int arr[500001];
int ans = 0;

void marge_sort(int l,int r)
{
	if(r-l==1)return;
	int mid = (l+r)/2;
	marge_sort(l,mid);
	marge_sort(mid,r);
	vector<int> v;
	int i = l;
	int j = mid;
	while(1)
	{
		
		if(i==mid||j==r)break;
		ans++;
		if(arr[i]<arr[j])
		{
			
			v.push_back(arr[i]);
			i++;
		}
		else
	 	{
			 v.push_back(arr[j]);
			 j++;
		}
	}
	
	for(;i<mid;i++)v.push_back(arr[i]),ans++;
	for(;j<r;j++)v.push_back(arr[j]),ans++;
	for(int k = l;k<r;k++)
	{
		arr[k] = v[k-l];
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i =0;i<n;i++)
	{
		cin >> arr[i];
	}
	marge_sort(0,n);
	for(int i = 0;i<n;i++)
	{
		if(i)cout<<' ';
		cout<<arr[i];
	}
	cout<<endl;
	cout<<ans<<endl;
	return 0;
}
