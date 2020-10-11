#include <stdio.h>
#define SIZE 100
int main(void){
	int array[SIZE], *p, i, j, work, index, N;
	char str[6];
	
	fscanf(stdin, "%d", &N);
	
	p = array;
	while (p < (array + N)) fscanf(stdin, "%d", p++);
	
	// output stdout
	p = array;
	while (p < array +N -1) fprintf(stdout, "%d ", *p++);
	fprintf(stdout, "%d\n", *p);
	
	i = 1;
	while (i < N) {
		for (work = array[i], j = i -1; j >= 0 && array[j] > work; j--) array[j +1] = array[j];
		array[j +1] = work;
		
		// output stdout
		p = array;
		while (p < array +N -1) fprintf(stdout, "%d ", *p++);
		fprintf(stdout, "%d\n", *p);
		
		i++;
	}
	
	return 0;
}
