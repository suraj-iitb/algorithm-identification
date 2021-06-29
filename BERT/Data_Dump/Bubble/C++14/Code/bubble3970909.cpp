#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
#include<numeric>
#include<random>
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int cnt = 0;
	int n;
	cin >> n;
	vector<int> a;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}

	rep(i, n-1) {
		for(int j=n-2;j>=i;j--)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j], a[j + 1]);
				cnt++;
			}
		}
	}

	rep(i,n)
	{
		if (i) { cout << " " << a[i]; }
		else { cout << a[i]; }
	}
	cout << endl << cnt << endl;

	return 0;
}
