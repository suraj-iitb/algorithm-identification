// Insertion Sort
#include <stdio.h>

void insertion_sort(int Ap[], int N)
{
    int i, j, k, v;
    for(i = 0; i < N; i++){
        v = Ap[i];
        j = i - 1;
        while(j >= 0 && Ap[j] > v){
            Ap[j + 1] = Ap[j];
            j--;
        }
        Ap[j + 1] = v;
        for(k = 0; k < N; k++){
            printf("%d", Ap[k]);
            if(k != N - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int N, i;
    scanf("%d", &N);
    int A[N];
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    insertion_sort(A, N);
   
    return 0;
}
