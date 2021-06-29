#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, key = 0, j = 0;
	scanf("%d", &n);
	
	vector<int> v;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		v.push_back(m);
	}
	
	vector<int>::iterator it;
	
	for(int i = 0; i <= v.size()-1; i++)
	{
		key = v[i];
		
		for(j = i - 1; j >= 0 && v[j] > key; j--)
			v[j+1] = v[j];
		
		v[j+1] = key;
		
		for(it = v.begin(); it != v.end()-1; it++)
				printf("%d ", *it);
		printf("%d\n", *it);
		
	}
	
	return 0;
}
