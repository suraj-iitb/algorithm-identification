#include<cstdio>
#include<algorithm>

int selectionSort(int A[], int N){
    int i, j, min_j, count=0;

    for(i=0; i<N-1; i++){
        min_j = i;
        for(j=i; j<N; j++){
            if(A[j] < A[min_j]) min_j = j;
        }
        std::swap(A[i], A[min_j]);
        if(i != min_j) count++;
    }
    return count;
}

int main(){
    int N, i, A[100], count;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    count = selectionSort(A, N);

    for(i=0; i<N; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", count);

    return 0;  
}
