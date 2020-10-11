#include<stdio.h>

int selectionSort(int A[],int N)
{
int i,minj,j,a,sw=0;
for(i=0;i<N-1;i++){
    minj = i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
            a=A[i];
            A[i]=A[minj];
            A[minj]=a;
            if(i!=minj){
                sw++;
            }
    }
    return sw;
}
int main(void)
{
    int sw,A[100],i,N;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    sw = selectionSort(A,N);
    for(i=0;i<N;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",sw);
    return 0;
}
