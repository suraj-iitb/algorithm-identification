#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, j;
	int a[100];
	int v, n;
	int k;
	
	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	for (i = 1; i < n; i++){
		for (k = 0; k < n; k++){
			if (k != n - 1)cout << a[k] << " ";
			else cout << a[k] << "\n";
		}
		v = a[i];
		j = i - 1;
		
		while (j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
	for (k = 0; k < n; k++){
		if (k != n - 1)cout << a[k] << " ";
		else cout << a[k] << "\n";
	}
	
	return (0);
}

