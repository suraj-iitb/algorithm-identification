#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int num[100];
	int i, j;
	int ans = 0;
	
	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> num[i];
	}
	
	for (i = 0; i < n; i++){
		for (j = n - 1; j > i; j--){
			if (num[j - 1] > num[j]){
				swap(num[j-1],num[j]);
				ans++;
			}
		}
	}
	
	for (i = 0; i < n; i++){
		cout << num[i];
		if (i == n - 1){
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	cout << ans << "\n";
	
	return (0);
}

