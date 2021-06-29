#include<stdio.h>

void selectionSort(int *, int);

int main()
{
    int N;
    scanf("%d",&N);
    int A[N], i;
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    
    selectionSort(A, N);
    
    return 0;
}


void selectionSort(int *a, int n)
{
    int i, j, minj, temp, count = 0;
    
    for(i=0; i<=n-1; i++){
        minj = i;
        for(j=i; j<=n-1; j++){
            if(a[j] < a[minj]) minj = j;
        }
        temp = a[i];
        a[i] = a[minj];
        a[minj] = temp;
        if(minj != i) count++;
    }
    
    printf("%d",a[0]);
    for(i=1; i<n; i++){
        printf(" %d",a[i]);
    }
    printf("\n%d\n",count);
}
