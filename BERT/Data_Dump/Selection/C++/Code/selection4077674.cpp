#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, min, count = 0;
	scanf("%d", &n);
	
	vector<int> v;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		v.push_back(m);
	}
	
	for(int i = 0; i < v.size()-1; i++)
	{
		min = i;
		
		for(int j = i; j <= v.size()-1; j++)
			if(v[j] < v[min])
				min = j;
		if(v[min] < v[i])
		{
			swap(v[i], v[min]);
			count++;
		}
	}
	
	int i;
	
	for(i = 0; i < v.size()-1; i++)
		printf("%d ", v[i]);
	printf("%d\n%d\n", v[i], count);
	
	return 0;
}
