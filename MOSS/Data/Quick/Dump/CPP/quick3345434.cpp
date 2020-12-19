#include<iostream>
#include<algorithm>
using namespace std;
class Card {
public:
	char c;
	int n;
};
bool operator<(const Card&a, const Card&b) {
	return a.n < b.n;
}
bool operator<=(const Card&a, const Card&b) {
	return a.n <= b.n;
}
bool operator==(const Card&a, const Card&b) {
	return a.n == b.n&&a.c == b.c;
}
int partition(Card *line, int p, int r) {
	int i = p - 1;
	Card x = line[r];
	for (int j = p; j < r; ++j) {
		if (line[j] <= x) {
			swap(line[j], line[++i]);
		}
	}
	swap(line[r], line[++i]);
	return i;
}
void quicksort(Card *line, int p, int r) {
	if (p < r) {
		int q = partition(line, p, r);
		quicksort(line,p, q - 1);
		quicksort(line, q + 1, r);
	}
}
int main() {
	int N;
	cin >> N;
	Card *line = new Card[N];
	Card *line2 = new Card[N];
	for (int i = 0; i < N; ++i) {
		cin >> line[i].c >> line[i].n;
		line2[i] = line[i];
	}
	quicksort(line, 0, N - 1);
	stable_sort(line2, line2 + N);
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		if (!(line[i] == line2[i])) {
			flag = true;
			break;
		}
	}
	cout << (flag ? "Not stable" : "Stable") << endl;
	for (int i = 0; i < N; ++i) {
		cout << line[i].c << " " << line[i].n << endl;
	}
	return 0;
}
