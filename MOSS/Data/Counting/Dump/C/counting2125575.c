#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//#include<time.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
int main() {
	int n, i, f=0, j;
	int A[10001] = {};
	fscanf(stdin, "%d", &n);
	while (n--) fscanf(stdin, "%d", &i), A[i]++;

	for (i = 0; i < 10001; i++) {
		for (j = 0; j < A[i]; j++) {
			if (f) printf(" ");
			fprintf(stdout, "%d", i),f=1;
		}
	}
	puts("");
	return 0;
}
