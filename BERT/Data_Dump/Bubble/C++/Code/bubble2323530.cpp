#include <iostream>
#include <stdio.h>
#include <utility>

#define MAX_N 100

void bubble_sort(int*,int);

int A[MAX_N];
int count = 0;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    bubble_sort(A,n);
    for(int i = 0; i < n; i++){
        if(i<(n-1))printf("%d ",A[i]);
        if(i == (n-1)) printf("%d\n",A[i]);
    }
    printf("%d\n",count);

}

void bubble_sort(int* a,int n){
    for(int i = 0; i < n; i++){
        for(int j = (n - 1); j > i; j--){
            if(A[j] < A[j-1]){
                std::swap(A[j],A[j-1]);
                count++;
            }
        }
    }
}
