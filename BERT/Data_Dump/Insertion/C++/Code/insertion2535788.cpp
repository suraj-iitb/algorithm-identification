#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 1000;

class Insertion_Sort {
public:
	int i, v, j, element;

	void Sort(int A[], int N) {
		for (int i = 1; i < N; i++) {
			v = A[i];
			j = i-1;
			while (j >= 0 && A[j]>v) {
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = v;
			trace(A, N);
		}
	}

	void trace(int A[],int N) {
		int i;
		for (i = 0; i < N; i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << A[i]; 
		}
		cout << endl;

	}
};

	int main() {
		int N;
		int A[MAX];

		cin >> N;

		int element;

		for (int i = 0; i < N; i++) {
			cin >> element;
			A[i] = element;
		}
		

		Insertion_Sort is;
		
		is.trace(A, N);
		
		is.Sort(A, N);


		return 0;

	}
