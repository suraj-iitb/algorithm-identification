#include<stdio.h>
#include<iostream>
using namespace std;

void trace(int A[], int N)
{
	for (int i = 0; i < N; i++) 
	{
		if (i > 0)cout << " ";
		cout << A[i];
	}
	cout << endl;
}
/*バブルソート*/
int bubbleSort(int A[],int N,int x) {
	bool flag = 1;
	while(flag)
	{
		int temp;
		int i = 0;
		flag = 0;
		for (int j = N - 1; j >= i+1; j--)
		{

			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				
				flag = 1;
				x++;
			}

		}
		i++;
	}
	return x;
}

int main() {
	int N ;
	int A[100];
	int x = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];

	x = bubbleSort(A, N,x);
	trace(A, N);cout << x<<endl;

}
