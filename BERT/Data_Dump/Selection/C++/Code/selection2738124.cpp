#include<iostream>
void printAns(int arr[], int len) {
	using std::cout;
	using std::endl;
	for (int i = 0; i < len; i++)
	{
		if (i)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
}
int main() {
	using namespace std;
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	int step = 0;
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(arr[i], arr[min]);
			step++;
		}
	}
	printAns(arr, len);
	cout << step << endl;
	return 0;
}
