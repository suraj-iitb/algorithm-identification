#include<iostream>
using namespace std;

void output(int A[], int n){
	int i;
	for (i = 0; i < n; i++)
	{
		if (i>0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

void sort_(int A[],int n){
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = A[i];
		j = i - 1;
		while (j >= 0 && A[j]>k){
			A[j+1] = A[j];
			j--;
		}
		A[j + 1] = k;
		output(A, n);
	}
}


int main(){
	int n, A[100];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	output(A, n);
	sort_(A, n);



	return 0;
}
