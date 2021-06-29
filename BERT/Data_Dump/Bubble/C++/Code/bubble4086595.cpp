#include <iostream>
using namespace std;
static const int MAX = 100;

void bubbleSort(int A[], int n)
{
	int cnt = 0;
	bool flag = true;
	
	for (int i = 0; flag == true; i++){
		flag = false;
		for (int j = n-1; j > i; j--){
			if (A[j] < A[j-1]){
				int temp;
				temp = A[j-1];
				A[j-1] = A[j];
				A[j] = temp;
				flag = true;
				cnt++;
			}
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
	bubbleSort(A, n);
	
	return 0;
}
