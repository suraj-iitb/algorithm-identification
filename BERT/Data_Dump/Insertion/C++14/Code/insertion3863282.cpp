#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int N;
	cin >> N;
	auto cards = make_unique<int[]>(N+1);
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	auto printCards = [&]() {
		cout << cards[0];
		for (int i = 1; i < N; i++) {
			cout << " " << cards[i];
		}
		cout << endl;
	};

	printCards();

	for (int i = 1; i < N; i++) {
		int v = cards[i];
		int j = i - 1;

		while (j >= 0 && cards[j] > v) {
			cards[j + 1] = cards[j];
			j--;
		}

		cards[j + 1] = v;

		printCards();
	}

	return 0;
}
