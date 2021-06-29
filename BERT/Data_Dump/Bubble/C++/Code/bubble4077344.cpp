#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, count = 0;
	scanf("%d", &n);
	
	vector<int> v;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		v.push_back(m);
	}
	
	for(int i = 0; i < v.size()-1; i++)
		for(int j = v.size()-1; j > i; j--)
		{
			if(v[j] < v[j-1])
			{
				swap(v[j], v[j-1]);
				count++;
			}
		}
    
 	int i;
 	
	for(i = 0; i < v.size()-1; i++)
		printf("%d ", v[i]);
	printf("%d\n%d\n", v[i], count);
	
	return 0;
}
