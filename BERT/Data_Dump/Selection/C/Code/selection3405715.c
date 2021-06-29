#include<stdio.h>

void selectionSort(int a[], int N);
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

    selectionSort(a,N);
}

void selectionSort(int a[], int N){
    int i,j,minj,count;
    count = 0;


    for(i=0;i<N-1;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(a[j]<a[minj])
                minj=j;
        }

        swap(&a[i],&a[minj]);
        if(i!=minj){
            count++;
        }  
        
    }

    printf("%d",a[0]);
    for(i=1;i<N;i++)
        printf(" %d",a[i]);
    
    printf("\n%d\n",count); 
}
