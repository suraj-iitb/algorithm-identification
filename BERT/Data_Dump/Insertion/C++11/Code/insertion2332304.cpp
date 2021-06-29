/*
 * main.cpp
 *
 *  Created on: 2017/05/14
 *      Author: YamajiTakashi
 */

#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;

void print_seq(int32_t *seq_, int32_t len_) {
	string str = "";
	for (int32_t i = 0; i < len_ ; i++) {
		str += to_string(seq_[i]) + ' ';
	}
	str.erase(--str.end());
	cout << str << endl;
}

int main(void) {
	uint32_t N;
	cin >> N;
	int32_t *A = new int32_t[N];

	for (int32_t i = 0; i < N; i++) {
		cin >> A[i];
	}

	print_seq(A, N);

	for (int32_t i = 1; i < N; i++) {
		int32_t v = A[i];
		int32_t j = i - 1;
		while(j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		print_seq(A, N);
	}

}
