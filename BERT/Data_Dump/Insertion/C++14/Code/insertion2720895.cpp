#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REPEAT(i, n) FOR(i, 0, n)

using namespace std;

void c_3_2() {
	int n;

	cin >> n;
	// int price[n];
	vector<int> a(n);
	REPEAT(i, n) {
		cin >> a[i];
	}
	REPEAT(k, a.size()) {
		cout << (k ? " " : "") << a[k];
	}
	cout << endl;
	FOR(i, 1, n) {
		int j;

		const auto v = a[i];
		j = i - 1;
		while (j >= 0 and a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		REPEAT(k, a.size()) {
			cout << (k ? " " : "") << a[k];
		}
		cout << endl;
	}
}

void c_2_5() {
	//string s;
	int n;
	cin >> n;
	// int price[n];
	vector<int> price(n);
	REPEAT(i, n) {
		cin >> price[i];
	}
	int maxPrice[n];
	int currentMaxPrice;
	currentMaxPrice = 0;	// or -infinite
	for (int i = n - 1; i >= 0; i--) {
		if (price[i] > currentMaxPrice) {
			currentMaxPrice = price[i];
		}
		maxPrice[i] = currentMaxPrice;
	}
	int maxUp = maxPrice[1] - price[0];
	for (int i = 1; i < n - 1; i++) {
		const int diff = maxPrice[i + 1] - price[i];
		if (diff > maxUp) {
			maxUp = diff;
		}
	}
	cout << maxUp << "\n";
	// 正解との違い: 最大ではなく最小を保持するようにすれば先頭から処理でき、配列を使う必要すらない
	// 競技プログラミングとしてのアドバイス: FOR, REPEATマクロを使いタイプミスをする可能性を減らす
	//   配列の変わりにvectorを用いて宣言以上の領域へのアクセスを検知したりsegmentation faultで落ちるようにする
}

int main() {
	ios::sync_with_stdio(false);
	c_3_2();
	return 0;
}

