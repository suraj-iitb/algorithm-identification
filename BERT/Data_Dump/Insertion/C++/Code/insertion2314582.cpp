#include <iostream>

#define SIZE 100

using namespace std;

int *insertion(int, int[]);
void trace(int, int[]);

int main(void) {
	int n, seq[SIZE];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	trace(n, seq);

	insertion(n, seq);

	cin >> n;

	return 0;
}

int *insertion(int n, int seq[]) {
	for (int i = 1; i < n; i++) {
		int key = seq[i];
		int j = i - 1;
		while (j >= 0 && seq[j] > key) {
			seq[j + 1] = seq[j];
			j--;
		}
		seq[j + 1] = key;
		trace(n, seq);
	}
	return seq;
}

void trace(int n, int seq[]) {
	for (int k = 0; k < n; k++) {
		if (k > 0) {
			cout << " ";
		}
		cout << seq[k];
	}
	cout << "\n";
}
