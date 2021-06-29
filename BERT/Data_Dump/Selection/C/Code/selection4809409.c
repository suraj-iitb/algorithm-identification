//
//  SelectionSort.c
//  Algorithm
//
//  Created by hongb Xu on 2020/9/1.
//  Copyright © 2020 hongb Xu. All rights reserved.
//

#include <stdio.h>

/*选择排序法（0起点*/
int selectionSort(int A[], int N){
    int i, j, t, sw = 0, minj;
    for(i=0; i<N-1; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        t = A[i]; A[i] = A[minj]; A[minj] = t;
        if (i != minj) sw++;
    }
    return sw;
}

int main(){
    int A[100], N, i, sw;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);
    sw = selectionSort(A, N);
    for(i =0; i<N; i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);
    return 0;
}
