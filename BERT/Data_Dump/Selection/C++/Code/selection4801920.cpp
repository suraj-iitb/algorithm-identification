#include <iostream>
using namespace std;

int main()
{
	int arr[101];
	int m;
	int count = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int mini = i;
		for (int j = i; j < m; j++) {
			if (arr[j] < arr[mini]) mini = j;
		}
		if(mini!=i){
		int t = arr[mini];
		arr[mini] = arr[i];
		arr[i] = t;
		count++;
		}
	}
	
	for (int i = 0; i < m; i++) {
		if(i<m-1)cout << arr[i] << " ";
		else cout << arr[i];
		
	}
	cout <<"\n";

	cout << count << "\n";

}
