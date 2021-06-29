#include <iostream>
using namespace std;
static const int MAX = 100;

int main()
{
	int N;
	int arr[MAX];
	
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++){
		if (i > 0)
			cout << " ";
		cout << arr[i];

	}
	cout << endl;
	for (int i = 1; i < N; i++){
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		for (int i = 0; i < N; i++){
			if (i > 0)
				cout << " ";
			cout << arr[i];
		}
		cout << endl;
	}
	
	return 0;
}
