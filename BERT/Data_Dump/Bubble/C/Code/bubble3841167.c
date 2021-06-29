#include <stdio.h>

int main(void) {

	int number;
	scanf("%d", &number);

	int array[100];
	for (int i = 0; i<number; i++) {
		scanf("%d", &array[i]);
	}

	int count = 0;
	int tmp;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = 0; j<(number - 1); j++) {
			if (array[j]>array[j + 1]) {
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;

				count++;
				flag = 1;
			}		
		}
	}

	for (int m = 0; m<number; m++) {
	if(m == number - 1){
			printf("%d\n",array[m]);
		}
		else {
			printf("%d ", array[m]);
		}
	}

	printf("%d\n", count);


	return 0;
}
