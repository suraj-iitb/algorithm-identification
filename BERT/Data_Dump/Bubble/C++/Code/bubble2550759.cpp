//
//  main.cpp
//  bubble_sort
//
//  Created by ???????????? on 2017/09/30.
//  Copyright ?? 2017 ????????????. All rights reserved.
//

#include <iostream>
#include<stdio.h>

static const int N = 1000;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void trace(int A[], int n){
    int i;
    for ( i = 0; i < n; i++ ){
        if ( i > 0 ) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void bubble_sort(int n, int A[]){
    int i, j, k;
    bool flag = true;
    i = 0;
    k = 0;
    while(flag){
        flag = false;
        for(j = n-1; j >= (i+1); j-- ){
            if(A[j] < A[j-1]){
                swap(&A[j], &A[j-1]);
                flag = true;
                k++;
            }
        }
        i++;
    }
    trace(A, n);
    printf("%d", k);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int n;
    int A[N];
    

    
    //get n and A
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

    bubble_sort(n, A);
    return 0;
}
