#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

struct Read {
	long long operator()(void) {
		long long d;
		std::cin >> d;
		return d;
	}
}read;
struct ReadReal {
	double operator()(void) {
		double d;
		std::cin >> d;
		return d;
	}
}readReal;
struct ReadString {
	std::string operator()(void) {
		std::string s;
		std::cin >> s;
		return s;
	}
}readString;

struct Print {
	void operator()(double d, int digit) {
		std::cout << std::fixed << std::setprecision(digit) << d;
	}
	template <typename T>
	void operator()(T t) {
		std::cout << t;
	}
	template <typename T>
	void operator()(const std::vector<T> &v, const std::string &sep = " ") {
		if (v.empty()) return;
		Print()(v[0]);
		for(int i = 1;  i < v.size(); ++i) {
			Print()(sep);
			Print()(v[i]);
		}
		return;
	}
}print;
struct Println {
	void operator()(void) {
		std::cout << std::endl;
	}
	void operator()(double d, int digit) {
		print(d, digit);
		Println()();
	}
	template <typename T>
	void operator()(T t) {
		print(t);
		Println()();
	}
	template <typename T>
	void operator()(const std::vector<T> &v, const std::string &sep = " ") {
		print(v, sep);
		Println()();
		return;
	}
}println;

int SelectionSort(vector<int> *vec) {
	auto &v = *vec;
	int count = 0;
	REP(i, v.size()) {
		int minj = i;
		FOR(j, i, v.size()) {
			if (v[minj] > v[j]) {
				minj = j;
			}
		}
		if (i != minj) {
			int tmp = v[minj];
			v[minj] = v[i];
			v[i] = tmp;
			count++;
		}
	}
	return count;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	auto size = read();
	vector<int> v(size);
	REP(i, size) {
		v[i] = read();
	}
	int count = SelectionSort(&v);
	println(v);
	println(count);

	return 0;
}

