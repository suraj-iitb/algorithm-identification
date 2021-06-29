#include <bits/stdc++.h>
using namespace std;

struct Card {
	char sign;
	int num;
	int inputTime;
};

int partition(Card *ca, int p, int r) {
	int x = ca[r].num;
	int i, j;
	i = p - 1;
	for (j = p; j < r; j++) {
		if (ca[j].num <= x) {
			i++;
			swap(ca[i], ca[j]);
		}
	}
	i++;
	swap(ca[i], ca[r]);
	return i;
}

void quickSort(Card *ca, int p, int r) {
	if (p < r) {
		int q = partition(ca, p, r);
		quickSort(ca, p, q - 1);
		quickSort(ca, q + 1, r);
	}
}

int main(void) {
	int n, i;
	cin >> n;
	Card ca[n];
	for (i = 0; i < n; i++) {
		cin >> ca[i].sign >> ca[i].num;
		ca[i].inputTime = i;
	}

	quickSort(ca, 0, n-1);
	bool flag = true;
	for (i = 1; flag && i < n - 1; i++) {
		if (ca[i].num == ca[i - 1].num && ca[i].inputTime < ca[i - 1].inputTime)
			flag = false;
	}
	if (flag) {
		cout << "Stable\n";
	} else {
		cout << "Not stable\n";
	}

	for (i = 0; i < n; i++) {
		cout << ca[i].sign << " " << ca[i].num << endl;
	}
}
