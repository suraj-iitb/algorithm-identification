#include <stdio.h>

void cc(int *a, int n) {
	int k;
    for(k=0;k<n;k++) {
 		if (k != 0) {
 	    	printf(" ");
        }
    	printf("%d", a[k]);
    }
    printf("\n");
}


void Insertion_sort(int a[], int n) {
	int i,j,v,k;
	for (i=1;i<n;i++) {
		v = a[i];
		j = i-1;
		while (j>=0 && a[j] > v) {
			a[j+1] = a[j];
			j--;
			a[j+1]=v;
		}
		cc(a, n);
	}
}		

 
							  
int main(void) {
	int n,i;
	int a[1000] = {};

	scanf("%d", &n);

	for (i=0;i<n;i++) {
			scanf("%d", &a[i]);
	}
    
	cc(a, n);
	Insertion_sort(a, n);

	

	return 0;
}
