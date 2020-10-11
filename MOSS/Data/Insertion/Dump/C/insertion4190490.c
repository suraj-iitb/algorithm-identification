#include <stdio.h>

void printconsole(int A[],int n){
    for (int k = 0; k < n; k++) {
        printf("%d",A[k]);
        if(k != n-1)putchar(' ');
    }
    putchar('\n');
}

void shellsort(int A[],int n){
    
}



void insertionSort(int A[],int n){
    int v,j;
    for (int i = 1; i < n; i++) {
        
        printconsole(A,n);
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    printconsole(A,n);
}

int main(int argc, const char * argv[]) {
    
    int n;
    int A[100];
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    
    insertionSort(A, n);
    
    /*
    printf("%d\n",n);
    for (int i = 0; i < n; i++) {
        printf("%d\n",A[i]);
    }
     */

    return 0;
}

