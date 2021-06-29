#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap, pair
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt,ceil,M_PI, pow, sin
#include <sstream>	//stringstream,getline
#include <numeric>	//gcd, accumlate
#include <deque>	//deque
#include <random>	//randam_device

using namespace std;

inline void InsertionSort(vector<int>& A) {

	for (unsigned int i = 0; i < A.size(); i++) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
		for (unsigned int k = 0; k < A.size() - 1; k++) {
			cout << A[k] << " ";
		}
		cout << A[A.size() - 1] << endl;
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	InsertionSort(A);

	return 0;

}
