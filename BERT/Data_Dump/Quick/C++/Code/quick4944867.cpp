#include <iostream>

using namespace std;

struct card {
	char pic;
	int num;
	int i; //入力が何番目かを記録する。安定か調べるため
};

int partition(card A[], int p, int r) {
	int x = A[r].num;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j].num <= x) {
			i++;
			card temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	card temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;
}

void QuickSort(card A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int main() {

	int n, isStable = 1;
	cin >> n;
	card* S = new card[n];
	for (int i = 0; i < n; i++) {
		cin >> S[i].pic;
		cin >> S[i].num;
		S[i].i = i;
	}

	QuickSort(S, 0, n - 1);

	for (int i = 0; i < n-1; i++) {
		if (S[i].i > S[i + 1].i && S[i].num == S[i+1].num) {
			isStable = 0;
			break;
		}
	}
	if (isStable == 1) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << S[i].pic << " ";
		cout << S[i].num << endl;
	}

	return 0;
}
