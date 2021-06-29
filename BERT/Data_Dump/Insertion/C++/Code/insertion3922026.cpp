#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 202000 ;
int a[MAXN], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i)
		if (i != n) cout << a[i] << " " ;
		else cout << a[i] << endl;
	for (int i = 2; i <= n; ++i)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
		for (int k = 1; k <= n; ++k) 
			if (k != n) cout << a[k] << " ";
			else cout << a[k] << endl;
	}
	return 0;
}

