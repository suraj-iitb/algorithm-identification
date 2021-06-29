#include <iostream>
#include <vector>

using namespace std;

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) {
		is >> x;
	}
	return is;
}
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (int i = 0; i<vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

void insertionSort(vector<int>& A) {
	for (int i = 1; i < A.size(); i++) {
		cout << A << endl;
		int tmp = A.at(i);
		int j = i - 1;
		while (j >= 0 && A.at(j) > tmp) {
			A.at(j + 1) = A.at(j);
			j--;
		}
		A.at(j + 1) = tmp;
	}
}

int main(void) {
	int num;
	cin >> num;
	vector<int> arr(num);
	cin >> arr;

	insertionSort(arr);

	cout << arr << endl;

	return 0;
}
