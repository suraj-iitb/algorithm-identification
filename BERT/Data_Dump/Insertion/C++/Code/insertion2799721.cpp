/*
 * ITP1_6_B.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: 13743
 */

#include<iostream>

using namespace std;

void printSeq(int *s, int n) {
	cout << s[0];
	for(int i=1; i<n; i++) {
		cout << " " << s[i];
	}
	cout << endl;
}

int main() {
	int N;
	int seq[100];
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> seq[i];
	}
	printSeq(seq, N);
	for(int i=1; i<N; i++) {
		int key = seq[i];
		int j = i - 1;
		while(j >= 0 && seq[j] > key) {
			seq[j+1] = seq[j];
			j--;
		}
		seq[j+1] = key;
		printSeq(seq, N);
	}
}

