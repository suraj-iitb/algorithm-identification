#include <stdio.h>
#define N 100

int bubbleSort(int *,int);
void swap(int *,int *);

int main(){
    int A[N];
    int i,j,n,cnt=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    cnt=bubbleSort(A,n);
    
    for(j=0;j<n;j++){
        printf("%d",A[j]);
        if(j<n-1) printf(" ");
        
    }
    printf("\n");
    
    printf("%d\n",cnt);
    
    return 0;
}


int bubbleSort(int A[],int n){
    int j,flag=1,cnt=0;
    
    while(flag){
        flag=0;
        for(j=n-1;j>0;j--){
            
            if(A[j]<A[j-1]){
                swap(&A[j],&A[j-1]);
                flag=1;
                cnt++;
            }
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






