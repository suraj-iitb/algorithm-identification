#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num[100];
	int i, j;
	int min;
	int n;
	int ans = 0;
	
	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> num[i];
	}
	
	for (i = 0; i < n; i++){
		min = i;
		for (j = i; j < n; j++){
			if (num[j] < num[min]){
				min = j;
			}
		}
		if (num[i] != num[min]){
			swap(num[i],num[min]);
			ans++;
		}
	}
	
	for (i = 0; i < n; i++){
		cout << num[i];
		if (i == n - 1){
			cout << "\n";
			cout << ans << "\n";
		}
		else cout << " ";
	}
	
	return (0);
}

