#include <stdio.h>

int selection(int a[], int l,int r){
    int i, j;
    int count = 0;
    for(i = l;i < r; i++){
        int min = i;
        for(j = i+1; j<=r; j++){
            if(a[j]<a[min]) min = j;
        }
        if(min != i){
            int temp = a[min];
            a[min] = a[i];
            a[i]= temp;
            count ++;
        }
    }
    return count;
}

int main()
{
    int i;
    int N;
    int A[100];
    scanf("%d", &N);
    for (i = 0; i < N ;i++) {
        scanf("%d", &A[i]);
    }

    int count = selection(A, 0, N-1);
    for (i = 0; i < N ;i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);

    return 0;
}
