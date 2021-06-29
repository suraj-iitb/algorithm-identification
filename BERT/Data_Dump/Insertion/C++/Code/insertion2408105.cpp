/*
?????????: Getting Started - Insertion Sort
URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp
?????°
7/5
14:23 ?????£????????????part3
14:29 ????????????
*/
#include <iostream>
using namespace std;

void print(int* A, int N)
{
	cout << A[0];
	for(int i=1;i<N;i++){
		cout << " ";
		cout << A[i];
	}
	cout << endl;
}

void insertionSort(int* A, int N)
{
	for(int i=1; i<N; i++){
		int v = A[i];
		int j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		print(A,N);
	}
}



int a[100];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	print(a,N);
	insertionSort(a,N);

}
