#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		int v = a[i];
		int j = i-1;
		while (j >= 0 and v < a[j]){
			int tmp = a[j];
			a[j] = a[j+1];
			a[j+1] = tmp;
			j--;
		}
		for (int k = 0; k < n; k++){
			if (k < n-1) cout << a[k] << " ";
			else cout << a[k] << endl;
		}
	}

}

