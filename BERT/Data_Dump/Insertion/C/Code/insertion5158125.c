#include<stdio.h>

void print(int A[],int n){
    int i;
    for(i = 0;i<n;i++){
        if(i > 0) printf(" ");
printf("%d",A[i]);
    }
    printf("\n");
}

void insertionsort(int A[],int n){
int i,j,t;
for(i = 1;i<n;i++){
    for(j = i-1;j>=0;j--){
        if(A[j]>A[j+1]){
t = A[j];
A[j] = A[j+1];
A[j+1] = t;
        }
    }
    print(A,n);
}
}

int main(){
    int n,A[1000],i;
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        scanf("%d",&A[i]);
    }
    print(A,n);
    insertionsort(A,n);
    return 0;
}
