#include <iostream>
#define MAX_NUM 100

int inputs[MAX_NUM] = {0};

using namespace std;

void swap(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int *a, int num) {
	for (int i=0; i<num; i++) {
		if (i>0) { cout<<" "; }
		cout<<a[i];
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n = 0;
	int swapCount = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> inputs[i];
	}

	for (int i=0; i<n-1; i++) {
		int minj = i;
		for (int j=i; j<n; j++) {
			if (inputs[j] < inputs[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(&inputs[i], &inputs[minj]);
			swapCount ++;
		}
	}


	printArray(inputs, n);
	cout<<swapCount<<endl;
	return 0;
}
