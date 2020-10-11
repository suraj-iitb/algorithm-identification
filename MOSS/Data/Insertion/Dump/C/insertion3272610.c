#include <stdio.h>
#define N 100
int main(){
    int A[N];
    int i,j,a,b;
    
    scanf("%d",&a);
    for(i=0;i<a;i++)
        scanf("%d",&A[i]);
    
    for(i=0;i<a;i++){

        
        b = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > b){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = b;
        for(j=0;j<a-1;j++)
            printf("%d ",A[j]);
        printf("%d\n",A[j]);
    }

    return 0;
    
}

