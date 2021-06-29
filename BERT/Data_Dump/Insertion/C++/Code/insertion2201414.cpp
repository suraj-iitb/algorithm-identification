#include<iostream>
#include<vector>
void SHOW(std::vector<int> Card) {
	for (unsigned int i = 0; i < Card.size()-1; ++i) {
		std::cout << Card[i]<<" ";
	}
	std::cout << Card[Card.size() - 1] << std::endl;
}
int main(void) {
	int N;
	std::cin >> N;
	std::vector<int >Card(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> Card[i];
	}
	for (int i = 0; i < N; ++i) {
				int v = Card[i];
		int NumberSequence = i - 1;
		while (0 <= NumberSequence&&Card[NumberSequence] > v) {
				Card[NumberSequence + 1] = Card[NumberSequence];
			--NumberSequence;
			Card[NumberSequence + 1] = v;
		}
		SHOW(Card);
	}
	//	system("pause");
	return 0;
}
