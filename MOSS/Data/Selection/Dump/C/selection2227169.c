#include <stdio.h>

int selectionSort(int A[], int N) {
    int i,j,minj,dummy;
    int count =0;

    for(i=0;i<N;i++) {
        minj = i;
        for(j=i;j<N;j++) {
            if(A[j] < A[minj]) minj = j;
        }
        
        if(minj != i) {
            dummy = A[i];
            A[i] = A[minj];
            A[minj] = dummy;

            count ++;
        }
    }
    return count;
}

int main(void) {
    int N,i,count;
    int A[100];

    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    count = selectionSort(A,N);

    for(i=0;i<N;i++) {
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
