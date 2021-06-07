#include <stdio.h>
int main(void) {

	int S_number, T_number;
	int S_array[100000], T_array[5000];
	int mid;
	int overaycount = 0;

	scanf("%d", &S_number);
	for (int si = 0; si<S_number; si++) {
		scanf("%d", &S_array[si]);
	}

	scanf("%d", &T_number);




	
	for (int ti = 0; ti<T_number; ti++) {
		scanf("%d", &T_array[ti]);
		int left = 0;
		int right = S_number ;
		while (left<right) {
			mid = (left + right) / 2;
			if (S_array[mid] == T_array[ti]) {
				overaycount++;
				break;
			}
			else if (S_array[mid]<T_array[ti]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
	}
	printf("%d\n", overaycount);
	return 0;
}
