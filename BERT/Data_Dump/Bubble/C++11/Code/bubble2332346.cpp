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

int32_t
bubbleSort(int32_t *seq_, int32_t len_) {
	bool flag = true;
	int32_t exchange_number = 0;
	while(flag == true) {
		flag = false;
		for (int j = len_ - 1; j > 0; j--) {
			if (seq_[j] < seq_[j-1]) {
				int32_t tmp = seq_[j];
				seq_[j] = seq_[j-1];
				seq_[j-1] = tmp;
				exchange_number++;
				flag = true;
			}
		}
	}
	return exchange_number;
}

int main(void) {
	uint32_t N;
	cin >> N;
	int32_t *A = new int32_t[N];

	for (int32_t i = 0; i < N; i++) {
		cin >> A[i];
	}

	int32_t n = bubbleSort(A, N);
	print_seq(A, N);
	cout << n << endl;
}
