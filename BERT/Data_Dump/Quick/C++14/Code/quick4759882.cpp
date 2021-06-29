#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
class card {
public:
	char suit; int number;
	card() : suit('?'), number(-1) {};
	card(char suit_, int number_) : suit(suit_), number(number_) {};
	bool operator==(const card& c) const {
		return suit == c.suit && number == c.number;
	}
};
void quicksort(std::vector<card> &A, int l, int r) {
	if(r - l <= 1) return;
	int ptr = l;
	for(int i = l; i < r - 1; ++i) {
		if(A[i].number <= A[r - 1].number) {
			std::swap(A[i], A[ptr++]);
		}
	}
	std::swap(A[ptr], A[r - 1]);
	quicksort(A, l, ptr);
	quicksort(A, ptr + 1, r);
}
int main() {
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::vector<card> A(N);
	for(int i = 0; i < N; ++i) {
		std::string str;
		std::cin >> str >> A[i].number;
		A[i].suit = str[0];
	}
	std::vector<card> B(A);
	std::stable_sort(B.begin(), B.end(), [](const card& c1, const card& c2) { return c1.number < c2.number; });
	quicksort(A, 0, N);
	std::cout << (A == B ? "Stable" : "Not stable") << '\n';
	for(int i = 0; i < N; ++i) {
		std::cout << A[i].suit << ' ' << A[i].number << '\n';
	}
	return 0;
}
