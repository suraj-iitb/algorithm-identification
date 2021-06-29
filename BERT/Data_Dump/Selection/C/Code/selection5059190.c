#include <stdio.h>
#define N 1000

int selectionSort(int *,int);
void swap(int *,int *);

int main(){
    int n,i,j,cnt;
    int A[N];
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    cnt=selectionSort(A,n);
    
    for(j=0;j<n;j++){
        printf("%d",A[j]);
        if(j<n-1) printf(" ");
    }
    printf("\n");
    
    printf("%d\n",cnt);
    
    return 0;
}


int selectionSort(int A[],int n){
    int i,j,cnt=0,min;
    
    for(i=0;i<n;i++){
        min=i;
        for(j=i;j<n;j++){
            if(A[j]<A[min]){
                min=j;
                
            }
        }
        if(i!=min){
            swap(&A[i],&A[min]);
            cnt++;
        }
    }
    return cnt;
}

void swap(int *a,int *b){
    int c;
    
    c=*a;
    *a=*b;
    *b=c;
    
}




