#include<stdio.h>
int main(){
    int i,j,k,n,v;
    int A[10000];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(i>0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
   
    for(i=1;i<=n-1;i++){
        v = A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
            A[j+1] = v;

            for(k=0;k<n;k++){
            if(k>0)printf(" ");
            printf("%d", A[k]);
            }
            printf("\n");
    }
    return 0;
}
