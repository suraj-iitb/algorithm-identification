#include <stdio.h>


void print_array(int A[], int N)
{
    int i;

    for(i = 0; i < N - 1; i++)
        printf("%d ", A[i]);

    printf("%d", A[N - 1]);
    printf("\n");

}


void insertionSort(int A[], int N)
{
    int i;

    for(i = 1; i < N; i++){
        int v = A[i];
        int j = i - 1;

        print_array(A, N);

        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
    print_array(A, N);
}

int main(void)
{
    int N, i;
    int A[1001];

    scanf("%d", &N);


    for(i = 0; i < N; i++){
        scanf("%d", A + i);
    }

    insertionSort(A, N);

    return 0;
}
