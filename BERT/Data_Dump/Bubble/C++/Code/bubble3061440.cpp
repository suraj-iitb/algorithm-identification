#include <iostream>
using namespace std;

const int MAX = 100;

int BubbleSort(int A[], int n){
	int count = 0; // 定义一个计数器 
	int flag = 1;
	while(flag){
		flag = 0;
		for(int i = n-1; i >= 1; i--){
			if( A[i-1] > A[i] ){
				swap(A[i-1], A[i]);
				count++; 
				flag = 1;
			}
		}
	}
	return count;
}

void PrintfInfo(int A[], int n){
	for(int i = 0; i < n; i++){
		if( i > 0 ) 
			cout << " ";
		cout << A[i];
	}
	cout << "\n";
}

int main()
{
	int n;
	cin >> n;
	int A[MAX];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	int count = BubbleSort(A, n);
	PrintfInfo(A, n);
	cout << count << "\n";
	return 0;
} 
