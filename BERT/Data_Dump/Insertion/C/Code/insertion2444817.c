#include <stdio.h>

int main(void){
	int n, tmp, j, i,l;
	int array[256];
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&array[i]);
	
	for(i=0;i<n;i++){
		printf("%d",array[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n");
	for (i = 1; i < n; i++) {
    	tmp = array[i];
    	if (array[i - 1] > tmp) {
        	j = i;
        	do {
        	    array[j] = array[j - 1];
        	    j--;
        	} while (j > 0 && array[j - 1] > tmp);
        	array[j] = tmp;
    	}
    	for(l=0;l<n;l++){
    		printf("%d",array[l]);
    		if(l!=n-1)printf(" ");
    	}
    	printf("\n");
    }
	return 0;
}
