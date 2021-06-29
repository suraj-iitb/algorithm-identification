#include<iostream>
static const int MAX = 100;
using namespace std;

void trace(int A[], int N)
{
	int i;
	for(i=0; i<N; i++){
		if(i>0){
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
}

void selectionSort(int A[], int N)
{
	int i, j, tmp, minj, count;
	int _A[N];
	
	count = 0;
	
	for(i=0; i<N; i++){
		minj = i;
		for(j=i; j<N; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		
		tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
		
		if(i != minj)count++;
	}
	
	trace(A, N);
	
	cout << count << endl;
}

int main()
{
	int N, i;
	int A[MAX];
	
	cin >> N;
	for(i=0; i<N; i++)cin >> A[i];
	
	selectionSort(A, N);
	
	return 0;
}
