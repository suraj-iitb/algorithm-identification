#include <iostream>
using namespace std;

#define SIZE 100

void bubbleSort(int n, int* A){
	bool flag = true;
	int tmp;
	int count = 0;
	
	while(flag){
		flag = false;
		for(int i = n - 1; i > 0; --i){
			if(A[i] < A[i - 1]) {
				tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				flag = true;
				++count;
			}
		}
	}
	
	for(int i = 0; i < n; ++i){
		if(i != n - 1)
			cout << A[i] << ' ';
		else
			cout << A[i] << endl;
	}
	cout << count << endl;

}

int main(void){
	int n;
	int A[SIZE];
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> A[i];
	
	bubbleSort(n, A);
	
	return 0;
}
