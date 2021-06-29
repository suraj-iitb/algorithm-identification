#include<stdio.h>

void bubbleSort(int a[100], int N);
void swap(int *a, int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;

}

int main(void){
    int a[100],N,i,j;
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d ",&a[i]);
    }

    bubbleSort(a,N);


}

void bubbleSort(int a[100], int N){
    int i,j,flag,count;
    flag = 1;
    count = 0;

    while(flag){
    flag = 0;
    
        for(j=N-1;j>0;j--){
            if(a[j] < a[j-1]){
                swap(&a[j],&a[j-1]);
                flag=1;
                count++;
            }
        }
    }
    printf("%d",a[0]);
    if(N>1){
        for(i=1;i<N;i++)
            printf(" %d",a[i]);
    }
    printf("\n"); 
    printf("%d\n",count);
}
