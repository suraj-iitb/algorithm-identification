#include <stdio.h>

#define N 100

int main(){
  int n, i, j,k, a[N], tmp=0,minj,count=0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n ; j++) {
            if (a[j] < a[minj]) {
                minj = j;
	    }
	}
                //A[i] と A[minj] 交換
	if(minj!=i){
                tmp = a[i];
                a[i] = a[minj];
                a[minj] = tmp;
		count++;
	}
        
    }

    for (k = 0; k < n; k++){
      printf("%d",a[k]);
      if(k!=n-1) printf(" ");
    }

    printf("\n%d\n",count);

    return 0;
}

