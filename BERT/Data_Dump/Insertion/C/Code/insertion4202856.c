#include<stdio.h>
int main()
{
    
    int n,v,j;
    scanf("%d",&n);
    int A[n];
    
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
        
    }
    for(int i=0; i<n; i++){
        printf("%d",A[i]);
        if(i<n-1)printf(" ");
    }
    printf("\n");
    for (int i=1; i<n; i++) {
        v=A[i];
        j = i-1;
        while (j>=0 && A[j]>v) {
            A[j+1] = A[j];
            j--;
        }
         A[j+1]=v;
        for(int k=0; k<n; k++){
            printf("%d",A[k]);
            if(k<n-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}

