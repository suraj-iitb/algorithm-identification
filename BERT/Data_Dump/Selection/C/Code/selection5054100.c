#include<stdio.h>

int main(){
    int i,j,n,min,kou=0,A[100],B;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++){
        min=i;
        for(j=i;j<n;j++){
            if(A[min]>A[j])min=j;
        }
        if(min!=i){
         B=A[i];
         A[i]=A[min];
         A[min]=B;
         kou++;
        }
    }
    for(i=0;i<n;i++){
        if(i!=n-1)printf("%d ",A[i]);
        else printf("%d\n",A[i]);
    }
    printf("%d\n",kou);
    return 0;
}
