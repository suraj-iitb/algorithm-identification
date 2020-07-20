#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int N;
	cin >> N;
	int A[N];
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = N - 1; j > i; j--){
			if(A[j-1] > A[j])
			{
				int temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				count++;
			}
		}
	}
	for(int j = 0; j < N - 1; j++)
	{
		cout << A[j] << " ";
	}
	cout << A[N-1] << endl;
	cout << count << endl;
	return 0;
}
