#include<stdio.h>

void insertionSort(int *, int);

int main()
{
    int N;
    scanf("%d",&N);
    int A[N],i;
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    insertionSort(A, N);
    
    return 0;
}


void insertionSort(int *a, int n)
{
    int i, j, k, v;
    
    for(i=1; i<=n-1; i++){
        for(k=0; k<n-1; k++){
            printf("%d ",a[k]);
        }
        printf("%d\n",a[n-1]);
        v = a[i];
        j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    for(k=0; k<n-1; k++){
        printf("%d ",a[k]);
    }
    printf("%d\n",a[n-1]);
}

