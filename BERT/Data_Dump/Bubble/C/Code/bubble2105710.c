int bubbleSort(int *A, int N){
    
    int flag = 1;
    int i;
    int tmp;
    int rtn =0;
    while(flag){
        flag = 0;
        for(i = N-1; i>0; i--){
            if(A[i-1] > A[i]){
                tmp = A[i-1];
                A[i-1] = A[i];
                A[i] = tmp;
                flag = 1;
                rtn++;
            }
        }
    }
    return rtn;
}

int main(void){
    int N;
    int A[100];
    int swap_num;
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);
    
    swap_num = bubbleSort(A, N);
    
    for(i = 0; i< N; i++){
        if(i==N-1){
            printf("%d\n", A[i]);
        }else{
            printf("%d ", A[i]);
        }
    }
    printf("%d\n", swap_num);
    
    return 0;
}
