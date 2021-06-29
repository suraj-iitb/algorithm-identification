#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i];
		if (i == n - 1)break;
		cout << " " ;
	}
	cout << endl;
}

int main()
{
	int n, m;
	cin >> n;
	vector<int> v;
	int j, k;
	for (int i = 0; i < n; i++) { cin >> m; v.push_back(m); }
	for (int i = 0; i < n; i++)
	{
		j = v[i];
		for (k = i ; k >= 0; k--)
		{
			if (k>0 && v[k-1] > j)v[k] = v[k-1];
			else  
			{
				v[k] = j;
				break;
			}
		}
		print(v, n);
	}
	return 0;
}
