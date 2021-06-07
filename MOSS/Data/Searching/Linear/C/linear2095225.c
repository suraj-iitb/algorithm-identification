#include <stdio.h>

#define n 5

int main() {
    int includeNumber[10000] = { 0 };
	int searchNumber[500] = { 0 };
	int needIN, needSN;
	int count;
	int i, j;
	count = 0;
	
	scanf("%d", &needIN);
	for (i = 0; i < needIN; i++) {
		scanf("%d", &includeNumber[i]);
	}
	scanf("%d", &needSN);
	for (i = 0; i < needSN; i++) {
		scanf("%d", &searchNumber[i]);
	}

	for (i = 0; i < needIN; i++) {
		for (j = 0; j < needSN; j++) {
			if (includeNumber[i] == searchNumber[j]) {
				searchNumber[j] = -1;
				count++;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
