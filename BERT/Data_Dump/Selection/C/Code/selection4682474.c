#include<stdio.h>
int main(){
    int N,i,j,time,min;
    int A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
        min = i;
        for(j=i;j<N;j++){
            if(A[min] > A[j]){
                min = j;
            }
        }
        if(A[i] != A[min]){
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        time++;
        }
    }
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i<N-1){
            printf(" ");
        }
    }
    printf("\n%d\n",time);
    return 0;
}
