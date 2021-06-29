#include <stdio.h>
int main(void)
{
    int n,i,j,k;
    int pointer;
    
    scanf("%d", &n);
    int A[n];
    for(i = 0; i < n; i = i + 1){
        scanf("%d",&A[i]);
    }

    for(k = 0;k < n;k = k+1){
        if(k == n - 1){
            printf("%d\n",A[k]);
        }
        else{
            printf("%d ", A[k]);
        }
    }

    for(j = 1; j < n; j = j+1){
        pointer = A[j];
        i = j - 1;
        while((i>= 0) && (A[i] > pointer)){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = pointer;
        for(k = 0;k < n;k = k+1){
            if(k == n - 1){
                printf("%d\n",A[k]);
            }else{
                printf("%d ", A[k]);
            }
        }
    }
    
}
