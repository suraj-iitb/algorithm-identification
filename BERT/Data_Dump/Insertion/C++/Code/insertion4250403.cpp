#include<iostream>
#include<stdio.h>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int N,v,j;
	int A[1000];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int a = 0; a < N; a++) {
			cout << A[a];
			if (a < N - 1) {
				cout << ' ';
			}
			else {
				cout<<endl;
			}
		}
	for (int i = 1; i < N; i++) {
		v = A[i];
		j = i-1 ;
		while (j >= 0 && v < A[j]) {

			A[j + 1] = A[j];
			j--;
         A[j+1] = v;
		}
		
		for (int a = 0; a < N; a++) {
			cout << A[a];
			if (a < N - 1) {
				cout << ' ';
			}
			else {
				cout<<endl;
			}
		}
	}
	return 0;
}
