#include <cstdio>

int dump(int A[], int N){
    for (int i=0; i<N; i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

int insertionSort(int A[], int N){
    for (int i=1; i<N; i++){
        int v = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        dump(A,N);
    }
}

int main (){
    int N;
    scanf("%d",&N);
    int A[N];
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    dump(A, N);
    insertionSort(A, N);
    return 0;
}
