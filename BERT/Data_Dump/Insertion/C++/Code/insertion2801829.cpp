#include<iostream>
using namespace std;
int main() {
	int a;
	cin>>a;
	int A[100];
	int c;
	for (int i = 0; i < a; i++) {
		cin>>A[i];
	}
	for (int i = 0; i < a; i++) {
		if (i)cout << " ";
		cout<<A[i];
	}
	cout << endl;
	for (int i = 1; i < a; i++) {
		int key = A[i];
		int j = i -1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = key;
		for (int i2 = 0; i2 < a; i2++) {
			if(i2)cout<<" ";
			cout << A[i2];
		}
		cout<<endl;
	}
	return 0;
}
