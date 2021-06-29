#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 2000001
#define VMAX 10000

int main () {
	unsigned short *inputArray, *outputArray;

	int buckets[VMAX + 1];

	int n;
	scanf("%d", &n);

	inputArray = new unsigned short[n];
	outputArray = new unsigned short[n + 1];

	for (int i = 0; i <= VMAX; i++) {
		buckets[i] = 0;
	}



	for (int i = 0; i < n; i++) {
		scanf("%hu", &inputArray[i]);
		buckets[inputArray[i]]++;
	}

	//Accumulating the count, making bucket as cumulative array
	for (int i = 1; i <= VMAX; i++) {
		buckets[i] = buckets[i] + buckets[i - 1];
	}

	for (int i = 0; i < n; i++) {
		outputArray[buckets[inputArray[i]]] = inputArray[i];
		buckets[inputArray[i]]--;
	}

	for (int i = 1; i < n + 1; i++) {
		if (i > 1) printf(" ");

		printf("%d",outputArray[i]);

	}

	cout << endl;

	return 0;
}

