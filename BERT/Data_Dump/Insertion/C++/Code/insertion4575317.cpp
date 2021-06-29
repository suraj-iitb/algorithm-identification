#include<cstdio>

void insertionSort(int A[],int N){
    int value;
    int num;
    for(int i = 0; i < N; i++){
        value = A[i];
        num = i-1;
        while (num >= 0 && A[num] > value){
            A[num+1] = A[num];
            num--;
        }
        A[num+1] = value;
        for (int a = 0; a < N; a++){
            printf("%d", A[a]);
            if (a != N-1){
                printf(" ");
            }
            
        }
        printf("\n");
    }
}
int main(){
    int N;
    int A[1000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    insertionSort(A, N);
    return 0;
}
