#include<cstdio>
#include<algorithm>

int bubbleSort(int A[], int N){
    int i, j, count=0;
    for(i=0; i<N; i++){
        for(j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
                count++;
            }  
        }
    }
    return count;
}
/*
int bubbleSort(int A[], int N){
    int i, j, count=0;
    bool flag = 1;
    for(i=0; flag; i++){
        flag = 0;
        for(j=N-1; j>=i+1; j--){
           if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
                count++;
                flag = 1;
           }
        }
    }
    return count;
}
*/
int main(){
    int i, N, A[100], count;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    count = bubbleSort(A, N);

    for(i=0; i<N; i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", count);

    return 0;
}
