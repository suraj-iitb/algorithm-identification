#include <stdio.h>

int main(void)
{
    int n ,m;
    int A[1000];
    int i ,j ,v ,t;
    
    scanf("%d" , &n);

    for (m = 0 ; m < n ; m++) {
            scanf("%d" , &A[m]);
    }
    
    /*Insertion Sort*/
    for (i = 1 ; i <= n - 1; i++) {
        
        for (t = 0 ; t < n - 1 ; t++)
            printf("%d " , A[t]);
        printf("%d\n" , A[n - 1]);
        
        v = A[i];
        j = i - 1;
        
        while (j >= 0 && A[j] > v) {
            
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
            
        }
    }
    /*for last line*/
    for (t = 0 ; t < n - 1 ; t++)
        printf("%d " , A[t]);
    printf("%d\n" , A[n - 1]);
    
    return 0;
}

