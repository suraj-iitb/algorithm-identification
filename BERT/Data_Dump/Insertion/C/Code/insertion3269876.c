#include<stdio.h>
#define N 100

int main(){
    int i, j, k, n, v, h, A[1000];
    
    scanf("%d",&n);
    
    for(i=0 ; i<n ; i++){
        scanf("%d",&A[i]);
        }
        
    for(i= 0 ; i<n ; i++){
        v = A[i];
        j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(h=0 ; h<n ;h++) { 
            if(h!=0)printf(" ");
            printf("%d",A[h]);
            if(h==n-1)printf("\n");
        }
        
    }
    return 0;
}




