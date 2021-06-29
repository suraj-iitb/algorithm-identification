#include<stdio.h>
#define N 10000
#define M 500

int linearSearch(int*, int, int);

int main(){
    int A[N];
    int B[M];
    int i, j, x, y;
    int judge = 0;
    int cont = 0;
    int flag = 0;
    
    scanf("%d", &x);
    for(i=0 ; i<x ; i++){
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &y);
    for(j=0 ; j<y ; j++){
        scanf("%d", &B[j]);
        judge = linearSearch(A, B[j], x);
        if(judge != 0){
            cont++;
            flag = 1;
        }
    }
    
    if(flag==0){
        printf("0\n");
    }else{
        printf("%d\n", cont);
    }
    
    return 0;
}

int linearSearch(int* aa, int key, int n){
    int i;
    
    for(i=0 ; i<n ; i++){
        if(aa[i]==key){
            return 1;
        }
    }
    
    return 0;
}
