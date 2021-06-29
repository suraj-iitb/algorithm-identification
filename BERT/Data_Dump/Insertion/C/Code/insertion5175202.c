#include <stdio.h>
int main()
{
    int n,i,key,j,m;
    scanf("%d", &n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    for(i=0;i<n;i++){
        key = A[i];
        /* insert A[i] into the sorted sequence A[0,...,j-1] */
        j=i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        for(m=0;m<n;m++){
            printf("%d", A[m]);
            if(m<n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
