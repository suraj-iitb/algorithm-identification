#include <stdio.h>

int main(){
    int cp=0;

    int N;
    scanf("%d",&N);

    int A[N];
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    for(int i=0;i<N;i++){
        if(i==0)
            printf("%d",A[i]);
        else
            printf(" %d",A[i]);
    }
    printf("\n");

    for(int i=0;i<N-1;i++){
        for(int j=i;j>=0&&A[j]>A[j+1];j--){
            cp=A[j];
            A[j]=A[j+1];
            A[j+1]=cp;
        }
        for(int i=0;i<N;i++){
            if(i==0)
                printf("%d",A[i]);
            else
                printf(" %d",A[i]);
        }
        printf("\n");
    }

}
