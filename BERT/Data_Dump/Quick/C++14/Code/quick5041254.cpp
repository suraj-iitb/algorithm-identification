#include <bits/stdc++.h>
using namespace std;

#define MAX 2000000

int A[MAX];

struct card {
	char mark;
	int num;
	bool operator < (const card& right) const {
		return num < right.num;
	}
	bool operator == (const card& right) const {
		return num == right.num and mark == right.mark;
	}
	bool operator != (const card& right) const {
		return num != right.num or mark != right.mark;
	}
};

void swap(card A[], int a, int b) {
	card tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}

int partition(card A[], int p, int r) {
	int x = A[r].num;
	int i = p-1;
	for (int j = p; j < r; j++) {
		if (A[j].num <= x) {
			i++;
			swap(A, i, j);
		}
	}
	swap(A, i+1, r);
	return i+1;
}

void quicksort(card A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

bool is_equal(card A[], card B[], int n) {
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) return false;
	}
	return true;
}

signed main() {
	int n;
	cin >> n;

	card cards[n];

	for (int i = 0; i < n; i++) {
		cin >> cards[i].mark >> cards[i].num;
	}

	card stable_cards[n];
	memcpy(stable_cards, cards, sizeof(cards));

	stable_sort(stable_cards, stable_cards + n);

	quicksort(cards, 0, n - 1);

	if (is_equal(cards, stable_cards, n)) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}

	for (int i = 0; i < n; i++) {
		cout << cards[i].mark << ' ' << cards[i].num << endl;
	}
}


