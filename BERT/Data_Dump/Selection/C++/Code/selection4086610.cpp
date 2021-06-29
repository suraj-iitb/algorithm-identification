#include <iostream>
using namespace std;
static const int MAX = 100;

void SelectionSort(int A[], int n)
{
	int cnt = 0;
	
	for (int i = 0; i < n; i++){
		int minIndex = i;
		for (int j = i+1; j < n; j++){
			if (A[j] < A[minIndex]){
				minIndex = j;
			}
		}
		if (minIndex != i){
			int temp;
			temp = A[minIndex];
			A[minIndex] = A[i];
			A[i] = temp;
			cnt++;
		}
	}
	for (int i = 0; i < n; i++){
		if (i > 0)
			cout << " ";
		cout << A[i];
	}
	cout << endl << cnt << endl;
}



int main()
{
	int A[MAX];
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	SelectionSort(A, n);
	
	
	return 0;
}
