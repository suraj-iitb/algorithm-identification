#include<stdio.h>


int main() {
    int A[1001], N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) scanf("%d",&A[i]);
    int v,j;
    
    for (int i = 1; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            {if (k>=1) printf(" ");}
            printf("%d",A[k]);
        }
        printf("\n");
        
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = v;
        
    }

    for (int k = 0; k < N; k++)
        {
            {if (k>=1) printf(" ");}
            printf("%d",A[k]);
        }
        printf("\n");
        
    return 0;
}