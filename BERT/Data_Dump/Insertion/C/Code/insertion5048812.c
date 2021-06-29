#include <stdio.h>

int main(){
    int n,A[100],temp;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    for(i=0;i<n;i++){
        printf("%d",A[i]);
        if(i==n-1){
            printf("\n");
        }else{
            printf(" ");
        }
    }

    for(i=1;i<n;i++){
        temp = A[i];
        j = i-1;
        while(j>=0 && A[j]>temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;

        for(j=0;j<n;j++){
            printf("%d",A[j]);
            if(j==n-1){
                printf("\n");
            }else{
             printf(" ");
            }
        }
    }
    
    return 0;
}
