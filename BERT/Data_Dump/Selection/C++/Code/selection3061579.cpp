#include <iostream>
using namespace std;

const int MAX = 100;

int SelectionSort(int A[],  int n){  // 不稳定 
	int count = 0;
	int min;
	for( int i = 0; i < n-1; i ++){
		min = i;
		for( int j = i; j < n; j++)
			if( A[min] > A[j] )
				min = j;
		swap(A[i], A[min]);
		if( i != min )  // 如果i==min，说明最小的元素是未排序序列的第一个，不需要交换 
			count++; 
	}
	return count;
}

void PrintInfo(int A[], int n){
	for(int i = 0; i < n; i++){
		if(i) cout << " ";
		cout << A[i];
	}
	cout << "\n";
	
		
}

int main()
{
	int n;
	int A[MAX];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	int count = SelectionSort(A, n);
	PrintInfo(A, n);
	cout << count << "\n";
	return 0;	
} 










