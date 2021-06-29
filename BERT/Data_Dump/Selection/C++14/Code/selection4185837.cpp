#include<bits/stdc++.h>
using namespace std;



int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	int k;
	int minj;
	int count = 0;
	for (int i = 0;i < N;i++)cin >>A[i];
	for (int i = 0;i < N;i++)
	{
		minj = i;
		for (int j = i;j < N;j++)
		{
			if (A[j] < A[minj]) {
				minj = j;
			}
				
			
		}
		k = A[i];
		A[i] = A[minj];
		A[minj] = k;
		if(minj!=i)count++;
	}

	for (int i = 0;i < N;i++) {
		if (i != 0) {
			cout << " ";
		}cout << A[i];
	}cout << endl;
	cout << count << endl;
	return 0;
}
