#include<stdio.h>
#define N 100000
#define M 50000

int binarySearch(int*, int, int);

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
        judge = binarySearch(A, B[j], x);
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

int binarySearch(int* aa, int key, int n){
    int i;
    int mi;
    int left = 0,right;
    
    right = n;
    
    while(left<right){
        mi = (left + right) / 2;
        if(aa[mi]==key){
            return 1;
        }else if(key<aa[mi]){
            right = mi;
        }else{
            left = mi + 1;
        }
    }
    
    return 0;
}
