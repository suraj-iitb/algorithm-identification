#include <iostream>
using namespace std;

int bubbleSort(int *A, unsigned N)
{
	bool flag = true;
	int count = 0;
	while (flag) {
		flag = false; 
		for (int i = N - 1; i >= 1; i--)
		{
			if (A[i] < A[i - 1])
			{
				swap(A[i], A[i - 1]);
				count++;
				flag = true;
			}
		}
	}
	return count;
}

int main() {
	unsigned N = 0;
	cin >> N;
	int *A = new int[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int sort_time = bubbleSort(A, N);
	for (int i = 0; i < N; i++){
		cout << A[i];
                if(i!=(N-1))
                   cout<<' ';
}
	cout << endl;
	cout << sort_time<<endl;
	return 0;
}
