#include <stdio.h>

void output(int A[], int n);
void insertionSort(int A[], int n);

int main(){
    int n, i;
    scanf("%d", &n);
    int A[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    insertionSort(A, n);

    return 0;
}

void output(int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d", A[i]);
	if(i != n-1)printf(" ");
    }
    printf("\n");
}

void insertionSort(int A[],int n){
    int i, j, key;
    output(A, n);
for(i = 1; i <= n-1; i++) {
        key = A[i];
        j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j --;
        }
	 A[j+1] = key;
        
        output(A, n);
    }
}
