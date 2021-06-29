#include <stdio.h>

#define Notfound -1;
int S_number, T_number;
int S_array[100000], T_array[500];
int findlineserch(int ti);

int main(void) {


	int ti;
	int return_find_or_not = 0;
	int overraycount = 0;

	scanf("%d", &S_number);

	for (int si = 0; si<S_number; si++) {
		scanf("%d", &S_array[si]);
	}
	scanf("%d", &T_number);

	for (int ti = 0; ti<T_number; ti++) {
		scanf("%d", &T_array[ti]);
	}

	ti = 0;

	while (T_number--) {

		return_find_or_not = findlineserch(ti);
		if (return_find_or_not != -1) {
			overraycount++;
		}
		ti++;
	}

	printf("%d\n", overraycount);

	return 0;
}

int findlineserch(int ti) {
	int si = 0;
	S_array[S_number] = T_array[ti];

	while (S_array[si] != T_array[ti]) {

		si++;
	}
	if (si == S_number) {
		return Notfound;
	}
	else return si;
}

