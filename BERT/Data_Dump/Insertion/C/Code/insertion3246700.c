#include <stdio.h>
int main(){
    int A[1000];
    int n;
    int i,j,v;
    int max,min;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        printf("%d",A[i]);
        if(i<n-1)printf(" ");
    }
    printf("\n");
    for(i=1;i<n;i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        
        for(j=0;j<n;j++){
            printf("%d",A[j]);
            if(j<n-1)printf(" ");
        }
        printf("\n");

    }
    return 0;
}

