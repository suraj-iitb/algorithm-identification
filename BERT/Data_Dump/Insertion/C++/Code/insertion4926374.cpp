
#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}

	int v;
	int j;
	
	for (int k = 0; k < n; k++)
	{
		if (k != n - 1) {
			cout << a[k] << " ";
		}
		else {
			cout << a[k] << endl;
		}

	}
	
	for (int i = 1; i <= n - 1; i++) {
		v = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}

		for (int k = 0; k < n; k++) 
		{
			if(k != n - 1){
				cout << a[k] << " ";
			}
			else {
				cout << a[k] << endl;
			}
			
		}
	}

	
}












