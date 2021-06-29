#include <iostream>
using namespace std;

const int MAX = 1000;

void PrintInfo(int R[], int n){
	for(int i = 0; i < n; i++){
		if(i > 0)
			cout << " ";
		cout << R[i];
	}
	cout << "\n";
}

void InsertionSort(int R[], int n){
	
	int v;
	int j;  // 作用就是把未排序序列的第一个元素插入到已排好序序列的合适的位置,从i-1开始 
	int i; // 指向未排序序列的第一个元素 
	for(i = 1; i < n; i++){
		v = R[i];
		j = i - 1;
		while( j >= 0 && R[j] > v){
			R[j+1] = R[j];  // 后移
			j--; 
		}
		R[j+1] = v;  // 把v插入到合适的位置 
		PrintInfo(R, n);
	}
}



int main()
{
	int n;
	cin >> n;
	int R[MAX];
	for(int i = 0; i < n; i++)
		cin >> R[i];
	PrintInfo(R, n);
	InsertionSort(R, n);
	return 0; 
}

